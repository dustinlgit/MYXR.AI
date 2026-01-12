/*
    features.h 
    Created on: 1/11/2026
        Author: Dustin Lee
*/

/*
    Feature extraction measures key properties of a track or stem, turning audio into numbers 
    the AI can understand. Common features include RMS (average loudness), peak levels, crest 
    factor (peak-to-average ratio), spectral centroid (brightness), and energy in low/mid/high bands. 
    These metrics allow the AI or Markov engine to decide what adjustments (gain, EQ, compression) 
    are needed and track the effect of each action.
*/

#ifndef FEATURES_H_
#define FEATURES_H_

struct AudioFeatures {
    float rms;
    float peak;
};

AudioFeatures extract_features(const std::vector<float>& samples);

#endif /* FEATURES_H_ */


