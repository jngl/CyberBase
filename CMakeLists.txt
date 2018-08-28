cmake_minimum_required (VERSION 3.0)
project (CyberBase)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=boost-*,cppcoreguidelines-*,clang-analyzer-*,modernize-*,performance-*;-header-filter=CyberBase")
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

#Boost
find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework log)

#CyberBase
file(GLOB_RECURSE cyberbase_source_files src/*)
add_library(CyberBase ${cyberbase_source_files})
target_include_directories(CyberBase PUBLIC include/ ${Boost_INCLUDE_DIR})
target_link_libraries(CyberBase ${Boost_LIBRARIES})

#example
file(GLOB_RECURSE example_source_files example/*)
add_executable(example ${example_source_files})
target_link_libraries(example PRIVATE CyberBase)

#Test
set(TEST_FILES tests/test_Vector3.cpp)

enable_testing()
add_executable(CyberBaseTests ${TEST_FILES})

target_link_libraries(CyberBaseTests
    CyberBase
)
target_include_directories(CyberBaseTests PUBLIC
    include
)

add_test(Test CyberBaseTests)


