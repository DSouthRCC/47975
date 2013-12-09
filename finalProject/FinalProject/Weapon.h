/* 
 * File:   Weapon.h
 * Author: rcc
 *
 * Created on November 20, 2013, 9:54 AM
 */

#ifndef WEAPON_H
#define	WEAPON_H

#include <string>
using namespace std;

struct Weapon {
    
    char WpType[25];
    short wpDmg;
    short wpSpd;
    short wpRch;
    short DefUp;
    short AgiDwn;
};

struct Armor
{
    char ArType[15];
    short DefUp;
    short AgiDwn;
};

#endif	/* WEAPON_H */

