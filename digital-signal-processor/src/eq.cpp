#include "include/eq.h"

#include <cmath>
#include <vector>
constexpr double PI = 3.14159265358979323846;

// Biquad processing
float Biquad::process(float x) {
    float y = b0 * x + b1 * z1 + b2 * z2 - a1 * z1 - a2 * z2;
    z2 = z1;
    z1 = x;
    return y;
}

// Design simple high-pass filter
void design_highpass(Biquad &f, float fc, float fs, float Q) {
    float w0 = 2.0f * PI * fc / fs;
    float alpha = sin(w0) / (2.0f * Q);
    float cosw0 = cos(w0);

    float b0 =  (1 + cosw0) / 2;
    float b1 = -(1 + cosw0);
    float b2 =  (1 + cosw0) / 2;
    float a0 =  1 + alpha;
    float a1 = -2 * cosw0;
    float a2 = 1 - alpha;

    f.b0 = b0 / a0;
    f.b1 = b1 / a0;
    f.b2 = b2 / a0;
    f.a1 = a1 / a0;
    f.a2 = a2 / a0;
}

// Apply filter in-place
void apply_biquad(std::vector<float>& samples, Biquad& filter) {
    for (auto& s : samples) {
        s = filter.process(s);
    }
}



