
file(GLOB_RECURSE mul_srcs *.cpp *.c)
add_library(mul SHARED ${mul_srcs})
target_include_directories(mul BEFORE PUBLIC ../common)
