# FakeFloat
Library of float number representation through integer 

# How to use
#include "fakefloat.h"

const struct sFakeFloat a = { 
    2, 3   // = 0.25
};

const struct sFakeFloat b = {
    2, 2  // = 0.5
};

struct sFakeFloat result;
    
int main(int argc, const char * argv[]) {
    ffAdd(a, b, &result);
    ffMult(a, b, &result);
    ffDevide(a, b, &result);

    return 0;
}
