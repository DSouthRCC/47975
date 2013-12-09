/* 
 * File:   Gladiator.h
 * Author: D
 *
 * Created on November 18, 2013, 12:38 PM
 */

#ifndef GLADIATOR_H
#define	GLADIATOR_H

#include <string>
using namespace std;

class Gladiator {
protected:
    short health;
    short fatigue;

public:
    //default constructor
    Gladiator() {
        health = 0;
        fatigue = 0;
    }

    //constructor
    Gladiator(short hp, short fati) {
        health = hp;
        fatigue = fati;
    }

    //mutators
    void setHealth() {
        health = hp;
    }

    void setFatigue() {
        fatigue = fati;
    }

    //accessors
    short getHealth() const {
        return health;
    }

    short getFatigue() const {
        return fatigue;
    }
};

#endif	/* GLADIATOR_H */