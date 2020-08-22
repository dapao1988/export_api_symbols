/*================================================================
*   Copyright (C) 2020 All rights reserved.
*
*   File Name     ：mul.cpp
*   Author        ：Wenbing.Wang
*   Created Time  ：2020-08-22
*   Description   ：
*
================================================================*/


#include "mul.hpp"

template<typename T>
Multiply<T>::Multiply(T a, T b) {
    this->a = a;
    this->b = b;
}

template<typename T>
 //API_LOCAL will be error: visibility does not match previous declaration
API_LOCAL T Multiply<T>::mul(T a, T b) {
    return mul_impl(a, b);
}

template<typename T>
T Multiply<T>::mul_impl(T a, T b) {
    return (a*b);
}

template<typename T>
API_EXPORT T Multiply<T>::mul_l(T a, T b) {
    return mul_impl(a, b);
}
template class Multiply<short>;
template class Multiply<int>;
template class Multiply<float>;
template class Multiply<double>;
