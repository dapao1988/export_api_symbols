/*================================================================
*   Copyright (C) 2020 All rights reserved.
*
*   File Name     ：mul.hpp
*   Author        ：Wenbing.Wang
*   Created Time  ：2020-08-22
*   Description   ：
*
================================================================*/


#ifndef _MUL_H
#define _MUL_H
#include "header.h"

template<typename T>
class API_EXPORT Multiply {
public:
    Multiply() = default;
    Multiply(T a, T b);
    API_LOCAL T mul(T a, T b); //for test if this symbol exported
    API_EXPORT T mul_l(T a, T b); //for test if this symbol exported
private:
    T mul_impl(T a, T b);
private:
    T a, b;
};
#endif //MUL_H
