/*
    gain.h 
    Created on: 1/11/2026
        Author: Dustin Lee
*/

/*
    Gain adjusts the loudness of a track or stem by multiplying the audio signal. It allows 
    you to bring instruments up or down in the mix, maintain headroom, and prepare stems for 
    further processing. Proper gain staging ensures no clipping occurs while giving the AI/engine 
    room to apply EQ, compression, or other effects safely.
*/

#ifndef GAIN_H_
#define GAIN_H_

void apply_gain(std::vector<float>& samples, float gain_db);


#endif /* GAIN_H_ */


