#add_library(CyberBase_catch_main STATIC catch_main.cpp)
#target_link_libraries(CyberBase_catch_main PUBLIC catch project_options project_warnings)

add_executable(CyberBase_tests
        Test_pointer.cpp
        Test_typeName.cpp
        Test_TypeId.cpp
        Test_id.cpp
        Test_Log.cpp
        Test_RangeOfNumber.cpp
        Test_math.cpp
        Test_component.cpp
        Test_Log.cpp
        Test_memory.cpp)

target_link_libraries(CyberBase_tests PRIVATE CyberBase project_options project_warnings Catch2::Catch2WithMain)


add_test(AllTest CyberBase_tests)
