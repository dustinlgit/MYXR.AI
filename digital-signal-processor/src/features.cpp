#include "include/features.h"

#include <vector>
#include <cmath>
#include <algorithm>

AudioFeatures extract_features(const std::vector<float>& samples) {
    float sum_squares = 0.0f;
    float peak = 0.0f;

    for (auto s : samples) {
        sum_squares += s * s;
        if (std::abs(s) > peak) peak = std::abs(s);
    }

    AudioFeatures f;
    f.rms = std::sqrt(sum_squares / samples.size());
    f.peak = peak;
    return f;
}