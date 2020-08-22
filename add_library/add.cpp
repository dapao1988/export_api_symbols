/*================================================================
*   Copyright (C) 2020 All rights reserved.
*
*   File Name     ：add.cpp
*   Author        ：Wenbing.Wang
*   Created Time  ：2020-08-22
*   Description   ：
*
================================================================*/


#include "add.hpp"

API_EXPORT int add(int a, int b) {
    return add_impl(a, b);
}

API_LOCAL int add_impl(int a, int b) {
    return (a+b);
}
