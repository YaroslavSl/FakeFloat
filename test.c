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

void testAdd1(void) {
    sTestFakeFloat_t it = {
        {1, 1},    // = 0.5
        {1, 4},    // = 0.0625
        {9, 4}     // = 0.5625
    };
    
    ffAdd(it.a, it.b, &result);
    printf("result: %d / 2^%d \n", result.num, result.shift);
    assert(!memcmp(&result, &(it.res), sizeof(result)));
}

void testAdd2(void) {
    sTestFakeFloat_t it = {
        {1, 4},   // = 0.0625
        {1, 1},   // = 0.5
        {9, 4}    // = 0.5625
    };
    
    ffAdd(it.a, it.b, &result);
    printf("result: %d / 2^%d \n", result.num, result.shift);
    assert(!memcmp(&result, &(it.res), sizeof(result)));
}

void testAdd3(void) {
    sTestFakeFloat_t it = {
        {1656917852, 27},    // = 12.345
        {128, 8},            // = 0.5
        {1724026716, 27}     // = 12.845
    };
    
    ffAdd(it.a, it.b, &result);
    printf("result: %d / 2^%d \n", result.num, result.shift);
    assert(!memcmp(&result, &(it.res), sizeof(result)));
}

void testAdd4(void) {
    sTestFakeFloat_t it = {
        {1, 1},   // = 0.5
        {-1, 4},  // = -0.0625
        {7, 4}    // = 0.4375
    };
    
    ffAdd(it.a, it.b, &result);
    printf("result: %d / 2^%d \n", result.num, result.shift);
    assert(!memcmp(&result, &(it.res), sizeof(result)));
}

void testAdd5(void) {
    sTestFakeFloat_t it = {
        {-1, 1},  // = -0.5
        {1, 4},   // = 0.0625
        {-7, 4}   // = -0.4375
    };
    
    ffAdd(it.a, it.b, &result);
    printf("result: %d / 2^%d \n", result.num, result.shift);
    assert(!memcmp(&result, &(it.res), sizeof(result)));
}

void testMult1(void) {
    sTestFakeFloat_t it = {
        {2, 3},   // = 0.25
        {3, 4},   // = 0.1875
        {6, 7}    // = 0.046875
    };

    ffMult(it.a, it.b, &result);
    printf("result: %d / 2^%d \n", result.num, result.shift);
    assert(!memcmp(&result, &(it.res), sizeof(result)));
}

void testMult2(void) {
    sTestFakeFloat_t it = {
        {3, 4},   // = 0.1875
        {2, 3},   // = 0.25
        {6, 7}    // = 0.046875
    };
    
    ffMult(it.a, it.b, &result);
    printf("result: %d / 2^%d \n", result.num, result.shift);
    assert(!memcmp(&result, &(it.res), sizeof(result)));
}

void testMult3(void) {
    sTestFakeFloat_t it = {
        {3, 4},   // = 0.1875
        {-2, 3},   // = -0.25
        {-6, 7}    // = -0.046875
    };
    
    ffMult(it.a, it.b, &result);
    printf("result: %d / 2^%d \n", result.num, result.shift);
    assert(!memcmp(&result, &(it.res), sizeof(result)));
}

void testDev1(void) {
    sTestFakeFloat_t it = {
        {2, 2},   // = 1
        {2, 2},   // = 1
        {1, 0}    // = 1
    };
    
    ffDevide(it.a, it.b, &result);
    printf("result: %d / 2^%d \n", result.num, result.shift);
    assert(!memcmp(&result, &(it.res), sizeof(result)));
}

void testDev2(void) {
    sTestFakeFloat_t it = {
        {2, 3},   // = 0.25
        {2, 2},   // = 0.5
        {1, 1}    // = 0.5
    };
    
    ffDevide(it.a, it.b, &result);
    printf("result: %d / 2^%d \n", result.num, result.shift);
    assert(!memcmp(&result, &(it.res), sizeof(result)));
}



int main(int argc, const char * argv[]) {
    testAdd1();
    testAdd2();
    testAdd3();
    testAdd4();
    testAdd5();
    testMult1();
    testMult2();
    testMult3();
    testDev1();
    testDev2();

    return 0;
}
