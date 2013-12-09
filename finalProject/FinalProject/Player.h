/* 
 * File:   Player.h
 * Author: D
 *
 * Created on November 18, 2013, 12:40 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include "Gladiator.h"

class Player : public Gladiator
{
private:
   string name;
   short favor;
   short wins;

public:
    //default constructor
    Player() {
        name = "";
        favor = 0;
        wins = 0;
    }

    //constructor
    Player(string nm, short fv, short wns) {
        name = nm;
        favor = fv;
        wins = wns;
    }

    //mutators
    void setName(string nm) {
        name = nm;
    }

    void setFavor() {

    }

    void setWins() {

    }

    //accessors
    string getName() const {
        return name;
    }

    short getFavor() const {
        return favor;
    }

    short getWins() const {
        return wins;
    }
};

#endif	/* PLAYER_H */