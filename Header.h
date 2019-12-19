#pragma once

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
	int health = 100;
};
