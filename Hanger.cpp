#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <time.h>
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include "declarations.h"
using namespace std;

void Hanger::landingBay()
{
	system("cls");
	end();

	print_slow(" Landing Bay", 30);
	print_slow_15(" You walk down the corridor and come to the end. There is a doorway which you walk through into the shipping bay. It is massive.");
	print_slow_15(" The ceiling is about 100 metres high and you see many workers preparing ships for takeoff and doing maintenance.");
	print_slow_15(" There are four landing pads which each contain a ship. Each one has a guard protecting it. But you see some boxes that allow might allow you to sneak past then guard unoticed.");
	print_slow_15(" The first ship has the least health of the bunch but has the most speed. It is blue with white highlights.");
	print_slow_15(" The second ship has the most attack power out of the bunch but the least defense. It is black with golden highlights.");
	print_slow_15(" The third ship has  the most defense but least attack power. It is green with black highlights.");
	print_slow_15(" The fourth ship has the most health but least speed. It is silver and has black highlights.");
	SP_
	system("pause");
	SP_

	do
	{
		getline(cin, input);
		SP_
		if (input == "get on first ship")
		{
			Hanger::firstShip();
		}
		if (input == "get on second ship")
		{
			Hanger::secondShip();
		}
		if (input == "get on third ship")
		{
			Hanger::thirdShip();
		}
		if (input == "get on fourth ship")
		{
			Hanger::firstShip();
		}
		Global::actions();
		not_equal("get on first ship", "get on second ship", "get on third ship", "get on fourth ship");

	} while (input != "get on first ship" && input != "get on second ship" && input != "get on third ship" && input != "get on fourth ship");
}

void Hanger::firstShip()
{
	Hanger::ifStealthy();
}

void Hanger::secondShip()
{
	Hanger::ifStealthy();
}

void Hanger::thirdShip()
{
	Hanger::ifStealthy();
}

void Hanger::fourthShip()
{
	Hanger::ifStealthy();
}

void Hanger::ifStealthy()
{
	srand(time(NULL));
	int yesno = ((rand() % 3) + 1);

	string ranOutOfTime = " You didn't attack the guard in time.";
	string pressedButton = " You attack the guard.";
	string options = " '1' to attack the guard";
	string timeDesc = " seconds until the guard reaches you.";

	if (yesno == 1)
	{
		print(" You snuck past the guard!");
	}
	else
	{
		print(" You weren't sneaky enough.\n The guard heard a sound coming from the boxes and he starts walking over to them.");
		system("pause");
		Global::timer(30000000, 4, ranOutOfTime, pressedButton, options, timeDesc, Hanger::gShipAttacks, Hanger::playerAttacks);
	}
}

void Hanger::gShipAttacks()
{
	
	int finalDamageGuard = GuardShip::easyReturnDamage() - Player::defense + Global::extraDamage();
	Player::health = Player::health - finalDamageGuard;

	end();
	cout << " The guard walks around the boxes and shoots you in the back. It does " << finalDamageGuard << " damage." << endl;
}

void Hanger::playerAttacks()
{
	end();
	srand(time(NULL));

	int random = ((rand() % 5) + 1);
	int finalDamage = Player::damage + gunBonus + random - GuardShip::easyReturnDefense();
	GuardShip::minusVariables("health", finalDamage);

	cout << "You attack the guard with your gun. It does " << finalDamage << " damage" << endl;

	cout << "The guard has ";
	GuardShip::showVariables("health");
	cout << " health left" << endl;

	getline(cin, input);
}
