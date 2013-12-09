//specification file for Combat class
#ifndef COMBAT_H
#define	COMBAT_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T>
T setAttack(T attkSpd, T defRate)
{
    srand(static_cast<unsigned int>(time(0)));
    int percent = rand() % 10 + 1; //add random adjustment
    int atkPerc; //set attack
    atkPerc = (attkSpd/defRate); //base percent
    atkPerc = atkPerc + percent; //adjusted percent
    
    return atkPerc;
}

template <class T>
T setDamage(T attkDmg, T attkPerc)
{
    int damage; //damage
    float perc = attkPerc*.10; //percent adjustment
    damage = ((attkDmg*perc)); //total damage
    return damage;
}

template <class T>
T setDodge(T defense, T attkPerc)
{
    int dodged;
    srand(static_cast<unsigned int>(time(0)));
    int percent = rand() % 10 + 1; //add random adjustment
    float perc = percent*.20;
    dodged = ((defense*perc)); //total damage
    //return
    return dodged;
}

template <class T>
T setParry(T parRating, T atkRate)
{
    float parry;
    srand(static_cast<unsigned int>(time(0)));
    int adjust = rand() % 10 + 1; //add random adjustment
    parry = ((parRating/atkRate)*adjust);
    cout << endl << "Parry: " << parry << endl;
    //return
    return parry;
}

#endif	/* COMBAT_H */