#include<iostream>
#include "Player.h"
using namespace std;

void Player::setAttributes(short hlt, short str, short fat, short agi, short def, short mvSpd)
{
	health = hlt;
    fatigue = fat;
	strength = str;
	agility = agi; 
    defense = def; 
	moveSpd = mvSpd; 
}

void Player::setPlyrAtkP(short plyrStr, short wpDmg, short wpSpd)
{
	plyrAtkP = ((plyrStr * (wpDmg + wpSpd))*.5);
}