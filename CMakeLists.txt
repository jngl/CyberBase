cmake_minimum_required (VERSION 3.15)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

project (CyberBase)
include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    option(ENABLE_BUILD_WITH_TIME_TRACE "Enable -ftime-trace to generate time tracing .json files on clang" OFF)
    if(ENABLE_BUILD_WITH_TIME_TRACE)
        add_compile_definitions(project_options INTERFACE -ftime-trace)
    endif()
endif()

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# enable cache system
include(cmake/Cache.cmake)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# sanitizer options if supported by compiler
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

if(ENABLE_COVERAGE)
    message("Coverage id enable")
endif()

# enable doxygen
include(cmake/Doxygen.cmake)
enable_doxygen()

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)
option(ENABLE_FUZZING "Enable Fuzzing Builds" OFF)

# Very basic PCH example
option(ENABLE_PCH "Enable Precompiled Headers" OFF)
if(ENABLE_PCH)
    # This sets a global PCH parameter, each project will build its own PCH, which is a good idea if any #define's change
    #
    # consider breaking this out per project as necessary
    target_precompile_headers(
            project_options
            INTERFACE
            <vector>
            <string>
            <map>
            <utility>)
endif()

include(FindPkgConfig)

option(ENABLE_TESTING "Enable Testing" ON)
if(ENABLE_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()

option(ENABLE_UNITY "Enable Unity builds of projects" OFF)
if(ENABLE_UNITY)
    # Add for any project you want to apply unity builds for
    set_target_properties(intro PROPERTIES UNITY_BUILD ON)
endif()

#Third party
add_subdirectory(third_party)

#FMT
find_package(fmt REQUIRED)

#CyberBase
file(GLOB_RECURSE cyberbase_source_files src/* include/*)
add_library(CyberBase ${cyberbase_source_files})
target_include_directories(CyberBase PUBLIC include/ )
target_link_libraries(CyberBase project_options project_warnings fmt)

#example
file(GLOB_RECURSE example_source_files example/*)
add_executable(example ${example_source_files})
target_link_libraries(example PRIVATE CyberBase)



