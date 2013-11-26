// Implementation file for the IntArray class
#include <iostream>
#include <cstdlib>   // For the exit function
#include "TestScores.h"
using namespace std;

void TestScores::setScores(int score, int index)
{
    if (score > 0 && score < 100)
    {
           testScrs[index] = score;
    }
    else
    {
       throw Error();
    }
}
