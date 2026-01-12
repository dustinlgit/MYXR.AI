/*
    eq.h 
    Created on: 1/11/2026
        Author: Dustin Lee
*/

/*
    EQ is like a sculpting tool for the frequency spectrum. It boosts or cuts specific 
    frequency bands to remove muddiness, brighten instruments, or carve space for each 
    element in a mix. High-pass filters remove unwanted low rumble, bell filters emphasize 
    or reduce midrange tones, and low/high-shelf filters gently adjust tonal balance. In a 
    professional mix, EQ makes each instrument sit clearly and harmoniously.
*/

#ifndef EQ_H_
#define EQ_H_

struct Biquad {
    float b0, b1, b2, a1, a2;
    float z1 = 0.0f, z2 = 0.0f;

    float process(float x);
};

void design_highpass(Biquad &f, float fc, float fs, float Q = 0.707f);
void apply_biquad(std::vector<float>& samples, Biquad& filter);

#endif /* EQ_H_ */


