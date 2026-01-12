/*
    compressor.h 
    Created on: 1/11/2026
        Author: Dustin Lee
*/

/*
    A compressor reduces the dynamic range of an audio signal by turning down loud peaks and 
    slightly raising softer sections. This makes instruments more consistent in volume, helps 
    them sit together in the mix, and prevents sudden spikes from jumping out. Light compression 
    can add “glue” to a track without making it sound squashed, allowing the AI to control 
    perceived loudness while preserving natural dynamics.
*/

#ifndef COMPRESSOR_H_
#define COMPRESSOR_H_

void apply_compression(std::vector<float>& samples, float threshold_db = -6.0f, float ratio = 2.0f);

#endif /* COMPRESSOR_H_ */


