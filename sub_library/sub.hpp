/*================================================================
*   Copyright (C) 2020 All rights reserved.
*
*   File Name     ：sub.hpp
*   Author        ：Wenbing.Wang
*   Created Time  ：2020-08-22
*   Description   ：
*
================================================================*/


#ifndef _SUBSTRACTION_H
#define _SUBSTRACTION_H
#include "header.h"

namespace cannon {

template<typename T>
class API_EXPORT Substraction {
public:
    Substraction() = default;
    ~Substraction() = default;
    Substraction(const Substraction &) = delete;
    Substraction& operator= (const Substraction &) = delete;
    Substraction(T a, T b);
    API_LOCAL T sub(T a, T b); //for test if this symbol exported
    API_EXPORT T sub_l(T a, T b); //for test if this symbol exported
private:
    T sub_impl(T a, T b);
private:
    T a, b;
};
#endif //SUBSTRACTION_H
}
