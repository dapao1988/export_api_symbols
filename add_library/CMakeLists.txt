
file(GLOB_RECURSE add_srcs *.cpp *.c)
add_library(add SHARED ${add_srcs})
