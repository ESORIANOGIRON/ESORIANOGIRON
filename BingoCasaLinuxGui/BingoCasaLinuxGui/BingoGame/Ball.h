#ifndef BALL_H
#define BALL_H

#include <sstream>
#include <stdio.h>
#include "BingoParameters.h"

class Ball {
  public:

    Ball();
    ~Ball();
    void SetBallNumber(int Number);
    void PickOutBall(void);

  private:

    int BallNumber;
    string LaunchImageInstruction;
    string LaunchSoundInstruction;

    void LaunchBallImage(void);
    void LaunchBallSound(void);
};

#endif
