#include "include/compressor.h"

#include <vector>
#include <cmath>

void apply_compression(std::vector<float>& samples, float threshold_db, float ratio) {
    float threshold = pow(10.0f, threshold_db / 20.0f);

    for (auto& s : samples) {
        float abs_s = std::abs(s);
        if (abs_s > threshold) {
            float exceed = abs_s - threshold;
            float gain = exceed / ratio;
            s = (s >= 0 ? 1.0f : -1.0f) * (threshold + gain);
        }
    }
}


