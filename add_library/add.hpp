/*================================================================
*   Copyright (C) 2020 All rights reserved.
*
*   File Name     ：add.hpp
*   Author        ：Wenbing.Wang
*   Created Time  ：2020-08-22
*   Description   ：
*
================================================================*/


#ifndef _ADD_H
#define _ADD_H
#include "header.h"

#ifdef __cplusplus
extern "C"
{
#endif
API_EXPORT int add(int a, int b);
API_LOCAL int add_impl(int a, int b);
#ifdef __cplusplus
}
#endif
#endif //ADD_H
