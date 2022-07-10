#ifndef playWavAudioFile_cpp
#define playWavAudioFile_cpp

#include <ezprint.cpp>
#include "sndfile.h"
#include "portaudio.h"
#include <ezprint.cpp>

namespace chl {

struct callback_data {
  SNDFILE* file;
  SF_INFO info;
};

const int FRAMES_PER_BUFFER = 512;

static int callback(const void *input, void *output,
                    unsigned long frameCount,
                    const PaStreamCallbackTimeInfo* timeInfo,
                    PaStreamCallbackFlags statusFlags,
                    void *userData ) {

  float* out;
  callback_data *data = (callback_data*) userData;
  sf_count_t number_read;

  out = (float*) output;
  data = (callback_data*) userData;

  /* clear output buffer */
  memset(out, 0, sizeof(float) * frameCount * data->info.channels);

  number_read = sf_read_float(data->file, out, frameCount * data->info.channels);
  if (number_read < frameCount) { return paComplete; }
  
  return paContinue;
}



void playWavAudioFile(const char* file_path) {

  SNDFILE *file;
  PaStream *stream;
  PaError error;
  callback_data data;

  data.file = sf_open(file_path, SFM_READ, &data.info);
  if (sf_error(data.file) != SF_ERR_NO_ERROR) {
    ezp::print_item("ERROR: problem loading file");
  }

  error = Pa_Initialize();
  if(error != paNoError) {
    ezp::print_item("ERROR: problem initializing portaudio");
  }

    /* Open PaStream with values read from the file */
    error = Pa_OpenDefaultStream(&stream
                                 ,0                     /* no input */
                                 ,data.info.channels         /* stereo out */
                                 ,paFloat32             /* floating point */
                                 ,data.info.samplerate
                                 ,FRAMES_PER_BUFFER
                                 ,callback
                                 ,&data);        /* our sndfile data struct */
    if(error != paNoError) {
      ezp::print_item("ERROR: problem loading default stream");
    }
    
    /* Start the stream */
    error = Pa_StartStream(stream);
    if(error != paNoError) {
      ezp::print_item("ERROR: problem starting audio stream");
    }

    /* Run until end of file is reached */
    while(Pa_IsStreamActive(stream))
    {
        Pa_Sleep(100);
    }

    /* Close the soundfile */
    sf_close(data.file);

    /*  Shut down portaudio */
    error = Pa_CloseStream(stream);
    if(error != paNoError) {
      ezp::print_item("ERROR: problem closing stream");
    }
    
    error = Pa_Terminate();
    if(error != paNoError) {
      ezp::print_item("ERROR: problem terminating portaudio");
    }
}

}




#endif /* playWavAudioFile_cpp */
