// Specification file for the Armor class
#ifndef ARMOR_H
#define ARMOR_H
#include <string>

using namespace std;

class Armor
{
private:
	string arName;
	short arDefAdj;
	short arAgiAdj;

public:
	//default constructor
	Armor() {
		set("",0,0);
	}

	//base constructor
	Armor(string armor, short aDefAdj, short aAgiAdj) { 
		set(armor, aDefAdj, aAgiAdj);
	}

	//mutators
	void set(string armor, short aDefAdj, short aAgiAdj) {
		arName = armor;
		arDefAdj = aDefAdj;
		arAgiAdj = aAgiAdj;
	}

	string getArName() const
	{ return arName; }

	short getArDefAdj() const
	{ return arDefAdj; }

	short getArAgiAdj() const
	{ return arAgiAdj; }

	void prntArmr() const {
		cout << "Armor\t" << "Def Adj\t" << "Agi Adj\t" << endl
		<< arName << "\t" << arDefAdj << "\t" << arAgiAdj << endl;
	}

};
#endif