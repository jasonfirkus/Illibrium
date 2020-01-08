#pragma once
#include <string>
#include <iostream>
using namespace std;

/*
Function key
any _ in a function name means it is a global function with nothing to do with the game and is to ease making functions for the game or such
For example the slow text print animation is one of those
any function with House:: means it is part of the set of the rooms house
any function with Global:: means it is a global function to do with the game
any function with Barracks:: means it is a function to do with the path of rooms going to the barracks room
any function with Guard:: means it is a function to do with the first with the guard guarding the entrance to the hanger
any function with DeadEndOne::, well that's kind of obvious
*/

extern string cyb1;
extern string gun;
extern string barracksinv;
extern string dineRoomInv;
extern string airlockInv;
extern string input;
extern string name;
extern string invPlayer[10];

extern int gunBonus;
extern bool colour;

void not_equal(string, string, string, string);
void printVar(string, int);
void end();
void print_slow(const string&, unsigned int);
void print_slow_no_space(const string&, unsigned int);
void print_slow_15(const string&);
void print(string);


namespace Hanger
{
	void entry();
}

namespace House
{
	void openPackage();
	void livingRoom();
	void packActions();
	void dineRoomHouse();
	void action();
	void backstory();
}

namespace Global
{
	void fullInvPlayer();
	void stats();
	void help();
	void actions();
	void gameOver();
	void no();
}

namespace Barracks
{
	void oActions();
	void oHouse();
	void westHall();
	void westHall2();
	void barracks();
}

namespace Guard
{
	void airlock();
	void guardFight();
	void examineGuardOne();
	void corridorImpossible();
	void examineImpossible();
	void attackImpossible();
	void attackEasy();
	void guardAttacks();
	void damageGuard();
	void failDodge();
}

namespace DeadEndOne
{
	void eastHall();
	void eastHallCont();
}

class Player
{
public:
	int speed = 100;
	int damage = 5;
	int defense = 5;
	int health = 20;
};

class GuardEasy
{
private:
	int health = 11;
	int damage = 10;
	int defense = 5;

public:
	void showVariables(string show)
	{
		if (show == "health")
		{
			cout << health;
		}
		if (show == "damage")
		{
			cout << damage;
		}
		if (show == "defense")
		{
			cout << defense;
		}
	}

	void addToVariables(string identify, int addBy)
	{
		if (identify == "health")
		{
			health = health + addBy;
		}
		if (identify == "defense")
		{
			defense = defense + addBy;
		}
		if (identify == "damage")
		{
			damage = damage + addBy;
		}
	}

	void minusVariables(string identify, int minusBy)
	{
		if (identify == "health")
		{
			health = health - minusBy;
		}
		if (identify == "defense")
		{
			defense = defense - minusBy;
		}
		if (identify == "damage")
		{
			damage = damage - minusBy;
		}
	}

	int guardEasyReturnDefense()
	{
		return defense;
	}
	int guardEasyReturnHealth()
	{
		return health;
	}
	int guardEasyReturnDamage()
	{
		return damage;
	}
};

class GuardImpossible : public GuardEasy
{
public:
	void showVariables(string show)
	{
		if (show == "health")
		{
			cout << health << endl;
		}
		if (show == "damage")
		{
			cout << damage << endl;
		}
		if (show == "defense")
		{
			cout << defense << endl;
		}
		if (show == "speed")
		{
			cout << speed << endl;
		}
	}

private:
	int health = 1000000;
	int damage = 1000000;
	int defense = 100000;
	int speed = 1000000;
};
