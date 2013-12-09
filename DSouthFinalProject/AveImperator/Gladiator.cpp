//Specification file for Gladiator implimentation
#include<iostream>
#include <iomanip>
#include "Player.h"
using namespace std;



void Gladiator::prntBase() const
{
        cout << "Gladiator Stats: " << endl;
        cout << "Health" << setw(9) << "Fatigue" << setw(10) << "Strength" << setw(9) << "Agility" << setw(9) << "Defense" << setw(10) << "Movement" << endl;
        cout  << setw(6) << baseHlth  << setw(9) << baseFti << setw(10) << baseStr << setw(9) << baseAgi << setw(9) << baseDef << setw(10) << baseMvSp << endl;
    }