/*
    eq.h 
    Created on: 1/11/2026
        Author: Dustin Lee
*/

/*
    
*/

#ifndef EQ_H_
#define EQ_H_

struct Biquad {
    float b0, b1, b2, a1, a2;
    float z1 = 0.0f, z2 = 0.0f;
    
    float process(float x);
};

void design_highpass(Biquad &f, float fc, float fs, float Q = 0.707f);

#endif /* EQ_H_ */


