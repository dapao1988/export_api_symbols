
file(GLOB_RECURSE sub_srcs *.cpp *.c)
add_library(sub SHARED ${sub_srcs})
target_include_directories(sub BEFORE PUBLIC ../common)
