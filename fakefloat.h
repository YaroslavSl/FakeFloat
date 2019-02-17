//
//  fakefloat.h
//  fakefloat
//
//  Created by Yaroslav on 1/22/19.
//  MIT License 
//

#ifndef fakefloat_h
#define fakefloat_h

//floatingPointValue = num / 2^shift;
struct sFakeFloat {
    int32_t num;  // numerator
    int8_t shift; // right shift values (use negative for left shift)
};

extern void ffAdd(struct sFakeFloat *a, struct sFakeFloat *b, struct sFakeFloat *result);
extern void ffMult(struct sFakeFloat *a, struct sFakeFloat *b, struct sFakeFloat *result);
extern void ffDivide(struct sFakeFloat *a, struct sFakeFloat *b, struct sFakeFloat *result);

#endif /* fakefloat_h */
