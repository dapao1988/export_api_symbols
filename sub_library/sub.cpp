/*================================================================
*   Copyright (C) 2020 All rights reserved.
*
*   File Name     ：sub.cpp
*   Author        ：Wenbing.Wang
*   Created Time  ：2020-08-22
*   Description   ：
*
================================================================*/


#include "sub.hpp"

template<typename T>
Substraction<T>::Substraction(T a, T b) {
    this->a = a;
    this->b = b;
}

template<typename T>
 //API_LOCAL will be error: visibility does not match previous declaration
API_LOCAL T Substraction<T>::sub(T a, T b) {
    return sub_impl(a, b);
}

template<typename T>
T Substraction<T>::sub_impl(T a, T b) {
    return (a - b);
}

template<typename T>
API_EXPORT T Substraction<T>::sub_l(T a, T b) {
    return sub_impl(a, b);
}
template class Substraction<short>;
template class Substraction<int>;
template class Substraction<float>;
template class Substraction<double>;
