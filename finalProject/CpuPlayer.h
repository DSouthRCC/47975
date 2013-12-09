/* 
 * File:   CpuPlayer.h
 * Author: D
 *
 * Created on November 18, 2013, 12:40 PM
 */

#ifndef CPUPLAYER_H
#define	CPUPLAYER_H

#include "Gladiator.h"

class CpuPlayer : public Gladiator
{
private:
   string name;

public:
    //default constructor
    CpuPlayer() {
        name = "";
    }

    //constructor
    CpuPlayer(string nm) {
        name = nm;
     }

    //mutators
    void setName(string nm) {
        name = nm;
    }
    //accessors
    string getName() const {
        return name;
    }
};

#endif	/* CPUPLAYER_H */