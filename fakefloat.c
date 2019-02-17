//
//  fakefloat.c
//  fakefloat
//
//  Created by Yaroslav on 1/22/19.
//  MIT License 
//
#include "fakefloat.h"
//#include <assert.h>

void ffAdd(struct sFakeFloat *a, struct sFakeFloat *b, struct sFakeFloat *result);
void ffMult(struct sFakeFloat *a, struct sFakeFloat *b, struct sFakeFloat *result);
void ffDivide(struct sFakeFloat *a, struct sFakeFloat *b, struct sFakeFloat *result);

void ffAdd(struct sFakeFloat *a, struct sFakeFloat *b, struct sFakeFloat *result) {
    int64_t tmp;
    // compare b.shift and a.shift and << >>
    if (b->shift > a->shift) {
        tmp = a->num;
        tmp = tmp << (b->shift - a->shift);
        tmp = tmp + b->num;
        result->shift = b->shift;
    } else {
        tmp = b->num;
        tmp = tmp << (a->shift - b->shift);
        tmp = tmp + a->num;
        result->shift = a->shift;
    }

    //printf("tmp=%lld\n", tmp);

    while (tmp > INT32_MAX || tmp < -INT32_MAX) {
        tmp = tmp >> 1;
        result->shift--;
    }
    //printf("result.shift=%d\n", result->shift);

    result->num = (int32_t)tmp;
    //printf("result->num=%d\n", result->num);
}

void ffMult(struct sFakeFloat *a, struct sFakeFloat *b, struct sFakeFloat *result) {
    int64_t tmp;
    tmp = a->num;
    tmp = tmp * b->num;
    
    result->shift = 0;
    while (tmp > INT32_MAX || tmp < -INT32_MAX) {
        tmp = tmp >> 1;
        result->shift--;
    }
    result->num = (int32_t) tmp;
    
    tmp = a->shift + b->shift + result->shift;
    //assert(tmp < INT8_MAX);
    result->shift = (int32_t) tmp;
}

void ffDivide(struct sFakeFloat *a, struct sFakeFloat *b, struct sFakeFloat *result) {
    int64_t tmp;
    tmp = a->num;
    tmp = tmp / b->num;
    
    result->shift = 0;
    while (tmp > INT32_MAX || tmp < -INT32_MAX) {
        tmp = tmp >> 1;
        result->shift--;
    }
    result->num = (int32_t) tmp;
    
    tmp = a->shift - b->shift + result->shift;
    //assert(tmp < INT8_MAX);
    result->shift = (int32_t) tmp;
}
