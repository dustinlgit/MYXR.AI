/*
    features.h 
    Created on: 1/11/2026
        Author: Dustin Lee
*/

/*
    
*/

#ifndef FEATURES_H_
#define FEATURES_H_

#include <cmath>
#include <algorithm>

struct AudioFeatures {
    float rms;
    float peak;
};

AudioFeatures extract_features(const float* samples, int num_samples);

#endif /* FEATURES_H_ */


