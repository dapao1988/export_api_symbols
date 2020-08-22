cmake_minimum_required(VERSION 3.17)

project(main)

message("current path: ${CMAKE_CURRENT_SOURCE_DIR}")
message("install path: ${CMAKE_INSTALL_PREFIX}")
option(EXPORT_SYMBOL_DEFAULT "whether to use __attribute_default_ for library symbol" ON)

if (EXPORT_SYMBOL_DEFAULT)
    add_definitions(-DEXPORT_SYMBOL_DEFAULT)
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(add_library)
file(GLOB demo_src ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${demo_src})
target_include_directories(${PROJECT_NAME} PUBLIC add_library)
target_link_libraries(${PROJECT_NAME} add)
install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin})

macro(do_test ARG1 ARG2 RESULT)
    add_test(NAME test_add_${ARG1}_${ARG2} COMMAND ${PROJECT_NAME} ${ARG1} ${ARG2})
    set_tests_properties(test_add_${ARG1}_${ARG2}
        PROPERTIES PASS_REGULAR_EXPRESSION ${RESULT})
endmacro(do_test)

macro(do_test1)
    add_test(test_example_no_args ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME})
    set_tests_properties(test_example_no_args
        PROPERTIES PASS_REGULAR_EXPRESSION "usage")
endmacro(do_test)

do_test(5 6 11)
do_test(6 6 12)
do_test(16 16 32)
do_test(26 26 52)
do_test(36 36 72)
do_test(46 46 92)
do_test1()
enable_testing()
