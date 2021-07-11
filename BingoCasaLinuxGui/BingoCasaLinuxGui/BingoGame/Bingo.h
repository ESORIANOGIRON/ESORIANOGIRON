#ifndef BINGO_H
#define BINGO_H

#include "Ball.h"
#include "Card.h"
#include "GenerateRandomNumbers.h"

enum GameStatus{INIT, NORMALRUN, BALLREPEAT, FINISHED};
enum GameMaxBallNumber{MAX75, MAX90};

class Bingo {

  public:

    Bingo();
    ~Bingo();
    void RunGame();
    void SetGameStatus(GameStatus Status);
    void SetGameMaxBallNumber(GameMaxBallNumber);
    GameMaxBallNumber GetGameMaxBalls(void);

    int GetLuckyNumber(int GamePic);
    void SetLuckyBallNumber(int LuckyNumber);

    vector <vector <int>> FillUpCard();
    void ClearCard(){CardManager->ClearCardNumbers();}

  private:

    Ball* LuckyBall;
    Card* CardManager;
    vector <int> LuckyNumbers;
    GameStatus BingoStatus;
    GameMaxBallNumber BingoMaxBalls;
};



#endif // BINGO_H
