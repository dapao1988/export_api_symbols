
file(GLOB_RECURSE add_srcs *.cpp *.c)
add_library(add SHARED ${add_srcs})
target_include_directories(add BEFORE PUBLIC ../common)
