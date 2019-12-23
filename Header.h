//#ifndef GLOBAL_H 
//#define GLOBAL_H

#pragma once
/*
void Global::stats();
void Barracks::oActions();
void Global::actions();
void House::dineRoomHouse();
void Barracks::oHouse();
void Global::fullInvPlayer();
void Global::no();
void Global::help();
void House::openPackage();
void House::livingRoom();
void House::packActions();
void House::action();
void House::backstory();
void Barracks::westHall();
void Barracks::westHall2();
void Barracks::barracks();
void Guard::airlock();
void notEqual(string notA, string notB, string notC, string notD);
void DeadEndOne::eastHall();
void DeadEndOne::eastHallCont();
void Guard::guardFight();
void Global::gameOver();
void Guard::examineImpossible();
void Guard::attackEasy();
void Guard::guardAttacks();
*/
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
	void no();
	void gameOver();
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

//#endif // GLOBAL_H
