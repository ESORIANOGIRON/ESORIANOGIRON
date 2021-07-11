#include <iostream>
#include "Card.h"
#include "GenerateRandomNumbers.h"

using namespace std;

Card::Card()
{
}

Card::~Card()
{
}

vector <vector <int>> Card::GetCardNumbers(void)
{
    return CardNumbers;
}

void Card::GenerateCardNumbers(int MaxBallNumber)
{
    if(MaxBallNumber == 75)
    {
        //Matrix "CardNumbers" will have 4 Rows x 5 Columns
        //See "Cards/75BallsCard.pdf"
        //1st Column: 4 Numbers between 1 and 15
        GenerateRandomNumbers(4, 0, 15);
        CardNumbers.push_back(GenerateRandomNumbers(4, 0, 15));
        //2nd Column: 4 Numbers between 16 and 30
        CardNumbers.push_back(GenerateRandomNumbers(4, 15, 30));
        //3rd Column: 3 Numbers between 31 and 45, plus a zero for the central position
        //See "Cards/75BallsCard.pdf"
        vector<int> PrevColumn = GenerateRandomNumbers(3, 30, 45);
        auto it = PrevColumn.insert(PrevColumn.begin()+2,0);
        CardNumbers.push_back(PrevColumn);
        //4th Column: 4 Numbers between 46 and 60
        CardNumbers.push_back(GenerateRandomNumbers(4, 45, 60));
        //5th Column: 4 Numbers between 61 and 75
        CardNumbers.push_back(GenerateRandomNumbers(4, 60, 75));

    }
    else if(MaxBallNumber == 90) //90 Balls Bingo
    {
        //Matrix "CardNumbers" will have 2 Rows x 5 Columns
        //See "Cards/90BallsCard.pdf"
        //1st Column: 2 Numbers between 1 and 10
        CardNumbers.push_back(GenerateRandomNumbers(2, 0, 10));
        //2nd Column: 2 Numbers between 11 and 20
        CardNumbers.push_back(GenerateRandomNumbers(2, 10, 20));
        //3rd Column: 1 Number between 21 and 30, plus a zero
        //See "Cards/90BallsCard.pdf"
        vector<int> PrevColumn = GenerateRandomNumbers(1, 20, 30);
        PrevColumn.push_back(0);
        CardNumbers.push_back(PrevColumn);
        //4th Column: 2 Numbers between 31 and 40
        CardNumbers.push_back(GenerateRandomNumbers(2, 30, 40));
        //5th Column: 1 Number between 41 and 50, plus a zero
        //See "Cards/90BallsCard.pdf"
        PrevColumn = GenerateRandomNumbers(1, 40, 50);
        PrevColumn.push_back(0);
        CardNumbers.push_back(PrevColumn);
        //6th Column: 2 Numbers between 51 and 60
        CardNumbers.push_back(GenerateRandomNumbers(2, 50, 60));
        //7th Column: 2 Numbers between 61 and 70
        CardNumbers.push_back(GenerateRandomNumbers(2, 60, 70));
        //8th Column: 1 Number between 71 and 80, plus a zero
        //See "Cards/90BallsCard.pdf"
        PrevColumn = GenerateRandomNumbers(1, 70, 80);
        PrevColumn.push_back(0);
        CardNumbers.push_back(PrevColumn);
        //9th Column: 2 Numbers between 81 and 90
        CardNumbers.push_back(GenerateRandomNumbers(2, 80, 90));
    }
    else
    {
        cout << "ERROR: MAX NUMBER OF BALLS NOT SET" << endl;
    }

}

void Card::ShowCardNumbers(int MaxBallNumber)
{    //Show the numbers with the legible 90/75 balls card format
    if(MaxBallNumber == 75) //75 Balls Bingo
    {
        cout << " B   I   N   G   O" << endl;

        for(int i=0; i< (int)CardNumbers.size(); i++)
        {
            for (int j=0; j< (int)CardNumbers.size(); j++)
            {
                if(CardNumbers[j][i]>9) cout << CardNumbers[j][i] << "  ";
                else if(CardNumbers[j][i]==0) cout << "    " ;
                else
                cout << " " << CardNumbers[j][i] << "  ";
            }
        cout << endl;
        }
    }
    else if(MaxBallNumber == 90)
    {
        cout << "G   O   O   D       L   U   C   K" << endl;
        for(int i = 0; i< (int)CardNumbers[i].size();i++)
        {
             for (int j=0; j< (int)CardNumbers.size(); j++)
             {
                if(CardNumbers[j][i]>9) cout << CardNumbers[j][i] << "  ";
                else if(CardNumbers[j][i]==0) cout << "    " ;
                else cout << CardNumbers[j][i] << "   ";
             }
             cout << endl;
        }
    }
    else
    {
        cout << "ERROR: MAX BALL NUMBER NOT DEFINED" << endl;
    }




    //Clear the vector once it has been shown
    CardNumbers.clear();
}
