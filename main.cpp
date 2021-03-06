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
#include "mul.hpp"
#include "sub.hpp"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace cannon;
int main(int argc, char* argv[]) {
    if  (argc < 3) {
        printf("usage: exe param1 param2\n");
        return 0;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("input param, a: %d, b: %d\n", a, b);

    Multiply<int> mul_obj;
    Substraction<int> sub_obj;
#if (EXPORT_SYMBOL_DEFAULT == 0)
    printf("API_LOCAL verify:\n");
    printf("a+b=%d\n", add(a, b));
    printf("a+b=%d\n", add_impl(a, b));

    printf("a*b=%d\n", mul_obj.mul(a,b));

    printf("a-b=%d\n", sub_obj.sub(a, b));
#else
    printf("API_EXPORT verify:\n");
    printf("a+b=%d\n", add(a, b));
    //printf("a+b=%d\n", add_impl(a, b));  //open will failed for api symbol hidden, undefined reference to `add_impl'

    //printf("a*b=%d\n", mul_obj.mul(a,b)); //undefined reference to `Multiply<int>::mul(int, int)',main: hidden symbol `_ZN8MultiplyIiE3mulEii' isn't defined
    printf("a*b=%d\n", mul_obj.mul_l(a,b)); //undefined reference to `Multiply<int>::mul(int, int)',main: hidden symbol `_ZN8MultiplyIiE3mulEii' isn't defined

    printf("a-b=%d\n", sub_obj.sub_l(a, b));
#endif
    return 0;
}
