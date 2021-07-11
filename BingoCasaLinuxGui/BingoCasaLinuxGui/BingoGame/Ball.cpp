#include "Ball.h"

using namespace std;

Ball::Ball()
{
    SetBallNumber(0);
}

Ball::~Ball()
{
}

void Ball::SetBallNumber(int Number)
{
    BallNumber = Number;
}

void Ball::PickOutBall(void)
{
    //Launch Ball Image & Sound
    LaunchBallImage();
    LaunchBallSound();

    //Wait a few seconds to stop playing the sound
    time_t timeOrig = time(NULL);
    struct tm y2k = {0};
    double secondsOrig = difftime(timeOrig,mktime(&y2k));
    double seconds = 0.0;

    //Checking the time to stop playing the sound
    //Not necessary since the vlc command will stop by itself
    /*while(seconds < AUDIO_PLAY_TIME)
    {
        seconds = difftime(time(NULL),mktime(&y2k)) - secondsOrig;
    }
    string SoundKillCommand = "killall " + BALL_SOUND_OPEN_INSTRUCTION;
    system(SoundKillCommand.c_str());*/

    //Wait a couple seconds more to take away the ball image

    //Checking the time to stop showing the ball image
    while(seconds < IMAGE_SHOW_TIME)
    {
        seconds = difftime(time(NULL),mktime(&y2k)) - secondsOrig;
    }
    string ImageKillCommand = "killall " + BALL_IMAGE_OPEN_INSTRUCTION;
    system(ImageKillCommand.c_str());
}

void Ball::LaunchBallImage(void)
{
    stringstream NumberOut;
    NumberOut << BallNumber;
    string LaunchCommand = BALL_IMAGE_OPEN_INSTRUCTION + BALL_FILE_PATH + BALL_FILE_NAME_PREFIX + NumberOut.str() + BALL_IMAGE_FILE_EXTENSION + " &";
    system(LaunchCommand.c_str());
}

void Ball::LaunchBallSound(void)
{
    stringstream NumberOut;
    NumberOut << BallNumber;
    string LaunchCommand = BALL_SOUND_OPEN_INSTRUCTION + BALL_FILE_PATH + BALL_FILE_NAME_PREFIX + NumberOut.str() + BALL_SOUND_FILE_EXTENSION;
    system(LaunchCommand.c_str());
}
