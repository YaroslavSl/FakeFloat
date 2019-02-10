//
//  fakefloat.c
//  fakefloat
//
//  Created by Yaroslav on 1/22/19.
//  Copyright © 2019 Yaroslav. All rights reserved.
//
#include "fakefloat.h"
#include <stdio.h>

void add(struct sFakeFloat a, struct sFakeFloat b, struct sFakeFloat *result);
int test(void);

void add(struct sFakeFloat a, struct sFakeFloat b, struct sFakeFloat *result) {
    int16_t tmp = a.num;               // 1/16 + 1/2 : 1
    // compare b.shift and a.shift and << >>
    tmp = tmp << (b.shift - a.shift);  // 4 - 1: 1<<3 : 8
//
    tmp = tmp + b.num;                 // : 9

    printf("%d\n", tmp);

    result->shift = b.shift;           // 4
    printf("%d\n", result->shift);
    while (tmp > INT8_MAX || tmp < -INT8_MAX) {
        tmp = tmp >> 1;
        result->shift--;
    }
    printf("%d\n", result->shift);

    result->num = b.num;
    printf("%d\n", result->num);

    //return 0;
}

void mult(struct sFakeFloat a, struct sFakeFloat b, struct sFakeFloat *result){
    int64_t tmp;
    tmp = a.num;
    tmp = tmp * b.num;
    
    result->shift = 0;
    while (tmp > INT32_MAX || tmp < -INT32_MAX) {
        tmp = tmp >> 1;
        result->shift--; }
    result->num = tmp;
    
    //tmp = a.shift + b.shift;
    //ASSERT(tmp < INT8_MAX);
    //result->num = tmp;
}

