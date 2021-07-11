#include "GenerateRandomNumbers.h"
#include <iostream>


using namespace std;


vector <int> GenerateRandomNumbers(int RowSize, int MinNumber, int MaxNumber)
{
    vector <int> NumberSet;
    while (NumberSet.size()< RowSize)
    {
        int Numero = rand() % MaxNumber + 1; //Generate random number

        for(int i=0; i<NumberSet.size(); i++) //Check out wether the random number is repeated
        {
            if(Numero == NumberSet[i] || Numero <= MinNumber)
            {
                Numero = 0; //Random number  is repeated or less than the minimum: Reject it
            }
            else
            {
                //Nothing to do
            }
        }

        if(Numero!=0 && Numero > MinNumber) //Random number is not repeated: Save it to the NumberSet
        {
            NumberSet.push_back(Numero);
        }
    };

    return NumberSet;
}
