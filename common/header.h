/*================================================================
*   Copyright (C) 2020 All rights reserved.
*
*   File Name     ：header.h
*   Author        ：Wenbing.Wang
*   Created Time  ：2020-08-22
*   Description   ：header for export library api symbol
*
================================================================*/


#pragma once

#if __GNUC__ >= 4
    #if (EXPORT_SYMBOL_DEFAULT == 1)
        #warning "==============dynamic library==============="
        #define API_EXPORT __attribute__((visibility ("default")))
        #define API_LOCAL __attribute__((visibility ("hidden")))
    #else
        #warning "==============static library==============="
        #define API_EXPORT
        #define API_LOCAL
    #endif
#else
    #warning "gcc version is smaller than 4, not support attribute feature"
#endif
