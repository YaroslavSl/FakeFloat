//
//  fakefloat.h
//  fakefloat
//
//  Created by Yaroslav on 1/22/19.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#ifndef fakefloat_h
#define fakefloat_h

#include <stdint.h>

//floatingPointValue = num / 2^shift;
struct sFakeFloat {
    int32_t num;  // numerator
    int8_t shift; // right shift values (use negative for left shift)
};

void ffAdd(struct sFakeFloat a, struct sFakeFloat b, struct sFakeFloat *result);

#endif /* fakefloat_h */
