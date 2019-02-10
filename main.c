//
//  main.c
//  fakefloat
//
//  Created by Yaroslav on 1/22/19.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include <stdio.h>
#include "fakefloat.h"

struct sFakeFloat a = {1, 1}; // 1/16
struct sFakeFloat b = {1, 4}; // 1/2
struct sFakeFloat result;


struct sFakeFloat aa = { 1656917852, 27 }; // 12.345
struct sFakeFloat bb = {128, 8}; // 0.5
struct sFakeFloat result2;

int main(int argc, const char * argv[]) {
    // insert code here...
    add(a, b, &result);
    printf("num=%d shift=%d ", result.num, result.shift);
    return 0;
}
