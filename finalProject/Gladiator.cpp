#include<iostream>
#include "Player.h"
using namespace std;



void Gladiator::prntBase() const
{
        cout << "Base Stats: " << endl;
        cout << "Health\t" << "Fatigue\t" << "Strength\t" << "Agility\t" << "Defense\t" << "Movement\t" << endl
                << baseHlth << "\t" << baseFti << "\t" << baseStr << "\t" << baseAgi << "\t" << baseDef << "\t" << baseMvSp << endl;
    }
