#include "include/limiter.h"

#include <vector>

void apply_limiter(std::vector<float>& samples, float ceiling) {
    for (auto& s : samples) {
        if (s > ceiling) s = ceiling;
        else if (s < -ceiling) s = -ceiling;
    }
}


