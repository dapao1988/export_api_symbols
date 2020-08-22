
file(GLOB_RECURSE add_srcs *.cpp *.c)
add_library(add SHARED ${add_srcs})
message("project_name in add: ${CMAKE_PROJECT_NAME}")
target_include_directories(${LIBRARY_OUTPUT_NAME} ../common)
