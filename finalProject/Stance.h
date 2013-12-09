// Specification file for the Stance class
#ifndef STANCE_H
#define STANCE_H
#include <string>

using namespace std;

class Stance
{
private:
	string stance;
	short moveSpd;
	short strength;
	short agility;
	short defense;
   
public:
   // Default Constructor
   Weapon()
      {
	  set("",0,0,0,0);}
   
   // Constructor
   Weapon(string stnc, short mvSpd, short str, short agi, short def)
      { 
		set(stnc, mvSpd, str, agi, def);
   }
   
	//Mutator functions
	void set(string stnc, short mvSpd, short str, short agi, short def)
	{
	string stance = stnc;
	short moveSpd = mvSpd;
	short strength = str;
	short agility = agi;
	short defense = def;
	}
};
#endif