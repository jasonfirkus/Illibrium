#pragma once
#include "precompiled.h"
#define P_ print(
#define T_ );
#define IF_(x, y) if (input == x) {y}
#define SP_ cout << endl;
#define CLS system("cls");
#define WAIT system("pause");

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

typedef void (*function_identifier)();

extern string cyb1;
extern string gun;
extern string barracksinv;
extern string dineRoomInv;
extern string airlockInv;
extern string input;
extern string name;
extern string invPlayer[11];

extern const unsigned short int gunBonus;
extern bool colour;
extern bool timerDone;
extern bool stop;
extern bool keyDPressed;
extern bool keyOPressed;
extern bool keyD2Pressed;
extern bool keyGPressed;
extern bool keyEPressed;

void room_complete();
void refresh();
void seconds();
void print_room_1(string, string);
void print_room_2(string, string, string);
void print_room_3(string, string, string, string);
void print_room_4(string, string, string, string, string);
void not_equal(string, string, string, string);
void printVar(string, int);
void end();
void print_slow(const string&, unsigned int);
void print_slow_no_space(const string&, unsigned int);
void print_slow_15(const string&);
void print(string);

namespace Timer
{
	void hangerGuard();
}


namespace Hanger
{
	void ifStealthy();
	void landingBay();
	void firstShip();
	void secondShip();
	void thirdShip();
	void fourthShip();
	void gShipAttacks();
	void playerAttacks();
}

namespace House
{
	void openPackage();
	void livingRoom();
	void packActions();
	void dineRoomHouse();
	void action();
	void backstory();
	void killPuppy();
}

namespace Global
{
	void fullInvPlayer();
	void stats();
	void help();
	void actions();
	void gameOver();
	void no();
	void timer(int, int, string, string, string, string, function_identifier, function_identifier);
	int extraDamage();
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
	void walkedIntoGuard();
}

namespace DeadEndOne
{
	void eastHall();
	void eastHallCont();
}

class Player
{
public:
	static int speed;
	static int damage;
	static int defense;
	static int health;
};

class GuardEasy
{
private:
	static int health;
	static int damage;
	static int defense;

public:
	static void showVariables(string show)
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

	static void minusVariables(string identify, int minusBy)
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

	static int easyReturnDefense()
	{
		return defense;
	}
	static int easyReturnHealth()
	{
		return health;
	}
	static int easyReturnDamage()
	{
		return damage;
	}
};

class GuardShip : public GuardEasy
{
public:
	int extraDamage()
	{
		int random = ((rand() % 5) + 1);
		return random;
	}
private:
	static int health;
	static int damage;
	static int defense;
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
	static int health;
	static int damage;
	static int defense;
	static int speed;
};
