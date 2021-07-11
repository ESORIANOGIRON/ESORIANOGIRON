#ifndef BINGOPARAMETERS_H
#define BINGOPARAMETERS_H

#include <string>

//Definition of the whole bunch of parameters

using namespace std;

//Definition of Image and Sound File names for each ball
const string BALL_IMAGE_OPEN_INSTRUCTION = "gpicview ";
const string BALL_SOUND_OPEN_INSTRUCTION = "cvlc --play-and-exit ";
const string BALL_FILE_PATH = "../Balls/";
const string BALL_FILE_NAME_PREFIX = "Ball";
const string BALL_IMAGE_FILE_EXTENSION = ".png";
const string BALL_SOUND_FILE_EXTENSION = ".mp3";
const double IMAGE_SHOW_TIME = 2.0; //Time to show the ball image
// const double AUDIO_PLAY_TIME = 3.0; //Not used since vlc stops by itself

#endif
