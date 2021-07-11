#ifndef CARD_H
#define CARD_H

#include <vector>

using namespace std;

class Card {
  public:

    Card();
    ~Card();

    vector <vector <int>> GetCardNumbers(void);
    void GenerateCardNumbers (int MaxBallNumber);
    void ShowCardNumbers(int MaxBallNumber);
    void ClearCardNumbers(){CardNumbers.clear();}

  private:

    vector <vector <int>> CardNumbers;

};


#endif // CARD_H
