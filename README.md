# FakeFloat
Library of float number representation through integer 

# Presentation
https://docs.google.com/presentation/d/e/2PACX-1vSIy0YzvnnktTu4zWC__4PfQIt8aHLs9ceSrW2IhF0wp5Tad5U8qcb2B5Szm2m3T2vbdwOfue9LFILo/pub?start=false&loop=false&delayms=10000

# How to use
```c
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
```
