/* 
 * File:   Combat.h
 * Author: D
 *
 * Created on December 7, 2013, 7:32 PM
 */

#ifndef COMBAT_H
#define	COMBAT_H

#include <iostream>

using namespace std;

template <class T>
T attack(T attacker, T defender)
{
    float atkPerc;
    
    atkPerc = attacker-defender;
    
    if (atkPerc < 0)
    {
        atkPerc = 0;
    }
    else if (atkPerc > 0 && atkPerc < 3)
    {
        atkPerc = 1;
    }
    else if (atkPerc >= 3 && atkPerc < 6)
    {
      atkPerc = 2;  
    }
    else if (atkPerc > 6)
    {
        atkPerc = 3;
    }
    return atkPerc;
}

template <class T>
T getDamage(T attacker, T defender, T attkPerc)
{
    int damage;
    
    damage = ((attacker*attkPerc)/(defender/3));
    
    return damage;
}

template <class T>
T getBlock(T attacker, T defender)
{
    float blocked;

    blocked = attacker - defender;
  
    return blocked;
}

template <class T>
T getDodge(T attacker, T defender)
{
    float dodge;
    
    dodge = attacker - defender;
    
    return dodge;
}

template <class T>
T getParry(T attacker, T defender)
{
    float parry;
    
    //math
    
    return parry;
}

#endif	/* COMBAT_H */