#include <iostream>
#include <vector>
#include "Bingo.h"


using namespace std;

Bingo::Bingo()
{
    SetGameStatus(INIT);
    SetGameMaxBallNumber(MAX90);
    LuckyBall = new Ball();
    CardManager = new Card();
}

Bingo::~Bingo()
{
    delete LuckyBall;
    delete CardManager;
}

void Bingo::RunGame()
{
    //Game Start, Create number store
    SetGameStatus(NORMALRUN);

    //Start picking out balls
    cout << endl << "PRESS INTRO TO PICK THE FIRST BALL" << endl;
    while (getchar() != '\n');

    for (uint i=0; i<LuckyNumbers.size(); i++)
    {
        //Update Game Data
        cout << endl << "NUMBER: " << LuckyNumbers[i] << endl;
        cout << "BALLS OUT: " << i+1 << endl;

        //Manage Ball Image & Sound
        LuckyBall->SetBallNumber(LuckyNumbers[i]);
        LuckyBall->PickOutBall();
        cout << "PRESS INTRO TO CONTINUE" << endl;
        while (getchar() != '\n');
    }

    //All balls are out: game finished
    cout << "ALL BALLS ARE OUT: SEE YOU NEXT GAME!" << endl;
    while ( getchar() != '\n');
    SetGameStatus(FINISHED);
}

void Bingo::SetGameStatus(GameStatus Status)
{
    BingoStatus = Status;

    if(Status == NORMALRUN)
    {
        //Check the game max ball number
        int MaxBallNumber = 0;
        if(BingoMaxBalls == MAX75) MaxBallNumber = 75;
        else if(BingoMaxBalls == MAX90) MaxBallNumber = 90;
        else cout << "Error: Max Ball Number Not Defined" << endl;
        LuckyNumbers = GenerateRandomNumbers(MaxBallNumber,0,MaxBallNumber);
    }
}

void Bingo::SetGameMaxBallNumber(GameMaxBallNumber MaxBN)
{
    BingoMaxBalls = MaxBN;
}

GameMaxBallNumber Bingo::GetGameMaxBalls(void)
{
    return  BingoMaxBalls;
}

void Bingo::SetLuckyBallNumber(int LuckyNumber)
{
    LuckyBall->SetBallNumber(LuckyNumber);
    LuckyBall->PickOutBall();
}

int Bingo::GetLuckyNumber(int GamePic)
{
    return LuckyNumbers[GamePic];
}

vector <vector <int>> Bingo::FillUpCard()
{
    int MaxBallNumber = 0;
    if(BingoMaxBalls == MAX75) MaxBallNumber = 75;
    else if(BingoMaxBalls == MAX90) MaxBallNumber = 90;
    CardManager->GenerateCardNumbers(MaxBallNumber);
    return CardManager->GetCardNumbers();
}
