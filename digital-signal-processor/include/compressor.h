/*
    compressor.h 
    Created on: 1/11/2026
        Author: Dustin Lee
*/

/*
    
*/

#ifndef COMPRESSOR_H_
#define COMPRESSOR_H_

#include <cmath>

void apply_compression(float* samples, int num_samples, float threshold_db = -6.0f, float ratio = 2.0f);

#endif /* COMPRESSOR_H_ */


