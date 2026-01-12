#include "include/gain.h"

#include <vector>
#include <cmath>

void apply_gain(std::vector<float>& samples, float gain_db) {
    float linear_gain = pow(10.0f, gain_db / 20.0f);
    for (auto& sample : samples) {
        sample *= linear_gain;
    }
}