//
//  Main.cpp
//  Mach1 Spatial SDK
//  Mach1Decode / Mach1DecodePositional APIs
//  Copyright © 2021 Mach1, Corp. All rights reserved.
//

#include <math.h>
#include <stdio.h>
#include <string>

#include "fmod.hpp"


extern "C"
{
    // Define Main FMOD Call To Access Our Plugin
    F_EXPORT FMOD_DSP_DESCRIPTION* F_CALL FMODGetDSPDescription();
}

// All Callback Function Definitions
FMOD_RESULT F_CALLBACK Plugin_Create                    (FMOD_DSP_STATE *dsp_state);
FMOD_RESULT F_CALLBACK Plugin_Release                   (FMOD_DSP_STATE *dsp_state);
FMOD_RESULT F_CALLBACK Plugin_Read                      (FMOD_DSP_STATE *dsp_state, float *inbuffer, float *outbuffer, unsigned int length, int inchannels, int *outchannels);
FMOD_RESULT F_CALLBACK Plugin_Process                   (FMOD_DSP_STATE *dsp_state, unsigned int length, const FMOD_DSP_BUFFER_ARRAY *inbufferarray, FMOD_DSP_BUFFER_ARRAY *outbufferarray, FMOD_BOOL inputsidle, FMOD_DSP_PROCESS_OPERATION op);
FMOD_RESULT F_CALLBACK Plugin_SetBool             (FMOD_DSP_STATE *dsp_state, int index, FMOD_BOOL value);
FMOD_RESULT F_CALLBACK Plugin_GetBool             (FMOD_DSP_STATE *dsp_state, int index, FMOD_BOOL *value, char *valuestr);

// Our parameters in the plugin

FMOD_DSP_PARAMETER_DESC* Mach1Decode_Param[1] =
{
};

// Our main definition
// Sets callbacks and info like name
FMOD_DSP_DESCRIPTION Silence_Desc =
{
    FMOD_PLUGIN_SDK_VERSION,    // version
    "Mach1Spatial-Decode",            // name
    0x00010000,                 // plugin version
    8,                          // no. input buffers
    2,                          // no. output buffers
    Plugin_Create,              // create
    Plugin_Release,             // release
    0,                          // reset
    0,                          // read
    Plugin_Process,             // process
    0,                          // setposition
    1,                          // no. parameter
    Mach1Decode_Param,          // pointer to parameter descriptions
    0,                          // Set float
    0,                          // Set int
    Plugin_SetBool,             // Set bool
    0,                          // Set data
    0,                          // Get float
    0,                          // Get int
    Plugin_GetBool,             // Get bool
    0,                          // Get data
    0,                          // Check states before processing
    0,                          // User data
    0,                          // System register
    0,                          // System deregister
    0                           // Mixer thread exucute / after execute
};
