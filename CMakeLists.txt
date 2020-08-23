cmake_minimum_required(VERSION 3.17)

project(main)

message("current path: ${CMAKE_CURRENT_SOURCE_DIR}")
message("project binary path: ${CMAKE_BINARY_DIR}")
message("install path: ${CMAKE_INSTALL_PREFIX}")
option(EXPORT_SYMBOL_DEFAULT "whether to use __attribute_default_ for library symbol" ON)

if (EXPORT_SYMBOL_DEFAULT)
    add_definitions(-DEXPORT_SYMBOL_DEFAULT=1)
elseif()
    add_definitions(-DEXPORT_SYMBOL_DEFAULT=0)
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -g -Wall -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(add_library)
add_subdirectory(mul_library)
add_subdirectory(sub_library)
file(GLOB demo_src ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${demo_src})
target_include_directories(${PROJECT_NAME} PUBLIC add_library)
target_include_directories(${PROJECT_NAME} PUBLIC mul_library)
target_include_directories(${PROJECT_NAME} PUBLIC sub_library)
target_link_libraries(${PROJECT_NAME} add)
target_link_libraries(${PROJECT_NAME} mul)
target_link_libraries(${PROJECT_NAME} sub)

#install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(TARGETS ${PROJECT_NAME} add mul sub
    RUNTIME DESTINATION ${CMAKE_INSTAL_BINDIR}
    PERMISSIONS GROUP_EXECUTE OWNER_EXECUTE
    LIBRARY DESTINATION ${CMAKE_INSTAL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTAL_LIBDIR}
    )

install(FILES ${PROJECT_SOURCE_DIR}/add_library/add.hpp DESTINATION include)
install(FILES ${PROJECT_SOURCE_DIR}/mul_library/mul.hpp DESTINATION include)
install(FILES ${PROJECT_SOURCE_DIR}/mul_library/sub.hpp DESTINATION include)
install(FILES ${PROJECT_SOURCE_DIR}/main.cpp DESTINATION sample)
macro(do_test ARG1 ARG2 RESULT)
    add_test(NAME test_add_${ARG1}_${ARG2} COMMAND ${PROJECT_NAME} ${ARG1} ${ARG2})
    set_tests_properties(test_add_${ARG1}_${ARG2}
        PROPERTIES PASS_REGULAR_EXPRESSION ${RESULT})
endmacro(do_test)

macro(do_mul ARG1 ARG2 RESULT)
    add_test(NAME test_mul_${ARG1}_${ARG2} COMMAND ${PROJECT_NAME} ${ARG1} ${ARG2})
    set_tests_properties(test_mul_${ARG1}_${ARG2}
        PROPERTIES PASS_REGULAR_EXPRESSION ${RESULT})
endmacro(do_mul)

macro(do_sub ARG1 ARG2 RESULT)
    add_test(NAME test_sub_${ARG1}_${ARG2} COMMAND ${PROJECT_NAME} ${ARG1} ${ARG2})
    set_tests_properties(test_sub_${ARG1}_${ARG2}
        PROPERTIES PASS_REGULAR_EXPRESSION ${RESULT})
endmacro(do_sub)

macro(do_test_no_args)
    add_test(test_example_no_args ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME})
    set_tests_properties(test_example_no_args
        PROPERTIES PASS_REGULAR_EXPRESSION "usage")
endmacro(do_test_no_args)

do_test(5 6 11)
do_test(6 6 12)
do_test(16 16 32)
do_test(26 26 52)
do_test(36 36 72)
do_test(46 46 92)
do_test_no_args()
do_mul(0 2 0)
do_mul(1 2 2)
do_mul(2 4 8)
do_mul(25 25 625)
do_sub(0 2 -2)
do_sub(100 2 98)
do_sub(100 0 100)
enable_testing()
