/*================================================================
*   Copyright (C) 2020 All rights reserved.
*
*   File Name     ：main.cpp
*   Author        ：Wenbing.Wang
*   Created Time  ：2020-08-22
*   Description   ：
*
================================================================*/


#include "add.hpp"
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if  (argc < 3) {
        printf("usage: exe param1 param2\n");
        return 0;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("input param, a: %d, b: %d\n", a, b);

    printf("a+b=%d\n", add(a, b));
    return 0;
}
