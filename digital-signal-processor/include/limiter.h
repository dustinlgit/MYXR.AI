/*
    limiter.h 
    Created on: 1/11/2026
        Author: Dustin Lee
*/

/*
    The limiter is a super fast compressor that prevents audio from exceeding a set "brick wall" threshold,
    catching loud audio distortion while allowing the overall percieved loudness by raising quieter sections,
    making tracks professional and consistent for streaming.

    I set the limiter's ceiling to -0.3 dB in accordance to Gary H. 
*/

#ifndef LIMITER_H_
#define LIMITER_H_

void apply_limiter(float* samples, int num_samples, float ceiling = 0.997f);

#endif /* LIMITER_H_ */


