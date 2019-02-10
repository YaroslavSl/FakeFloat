//
//  main.c
//  fakefloat
//
//  Created by Yaroslav on 1/22/19.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "fakefloat.h"

typedef struct sTestFakeFloat {
    struct sFakeFloat a;
    struct sFakeFloat b;
    struct sFakeFloat res;
} sTestFakeFloat_t;

struct sFakeFloat result;

void test1(void) {
    sTestFakeFloat_t it = {
        {1, 1},    // = 0.5
        {1, 4},    // = 0.0625
        {9, 4}     // = 0.5625
    };
    
    ffAdd(it.a, it.b, &result);
    printf("test: result of add: num=%d shift=%d \n", result.num, result.shift);
    assert(!memcmp(&result, &(it.res), sizeof(result)));
}

void test2(void) {
    sTestFakeFloat_t it = {
        {1, 4},   // = 0.0625
        {1, 1},   // = 0.5
        {9, 4}    // = 0.5625
    };
    
    ffAdd(it.a, it.b, &result);
    printf("test: result of add: num=%d shift=%d \n", result.num, result.shift);
    assert(!memcmp(&result, &(it.res), sizeof(result)));
}

void test3(void) {
    sTestFakeFloat_t it = {
        {1656917852, 27},    // = 12.345
        {128, 8},            // = 0.5
        {1724026716, 27}     // = 12.845
    };
    
    ffAdd(it.a, it.b, &result);
    printf("test: result of add: num=%d shift=%d \n", result.num, result.shift);
    assert(!memcmp(&result, &(it.res), sizeof(result)));
}

int main(int argc, const char * argv[]) {
    test1();
    test2();
    test3();
    
    return 0;
}
