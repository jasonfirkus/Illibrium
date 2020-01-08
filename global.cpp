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

void Global::no()
{
	cout << "Nani?" << endl;
}

void Global::gameOver()
{
	end();

	cout << "  .----------------.  .----------------.  .----------------.  .----------------.   .----------------.  .----------------.  .----------------.  .----------------.  .----------------. " << endl;
	cout << " | .--------------. || .--------------. || .--------------. || .--------------. | | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |" << endl;
	cout << " | |    ______    | || |      __      | || | ____    ____ | || |  _________   | | | |     ____     | || | ____   ____  | || |  _________   | || |  _______     | || |              | |" << endl;
	cout << " | |  .' ___  |   | || |     /  \\     | || ||_   \\  /   _|| || | |_   ___  |  | | | |   .'    `.   | || ||_  _| |_  _| | || | |_   ___  |  | || | |_   __ \\    | || |      _       | |" << endl;
	cout << " | | / .'   \\_|   | || |    / /\\ \\    | || |  |   \\/   |  | || |   | |_  \\_|  | | | |  /  .--.  \\  | || |  \\ \\   / /   | || |   | |_  \\_|  | || |   | |__) |   | || |     | |      | |" << endl;
	cout << " | | | |    ____  | || |   / ____ \\   | || |  | |\\  /| |  | || |   |  _|  _   | | | |  | |    | |  | || |   \\ \\ / /    | || |   |  _|  _   | || |   |  __ /    | || |     | |      | |" << endl;
	cout << " | | \\ `.___]  _| | || | _/ /    \\ \\_ | || | _| |_\\/_| |_ | || |  _| |___/ |  | | | |  \\  `--'  /  | || |    \\ ' /     | || |  _| |___/ |  | || |  _| | \\ \\__  | || |     | |      | |" << endl;
	cout << " | |  `._____.'   | || ||____|  |____|| || ||_____||_____|| || | |_________|  | | | |   `.____.'   | || |     \\_/      | || | |_________|  | || | |____| |___| | || |     |_|      | |" << endl;
	cout << " | |              | || |              | || |              | || |              | | | |              | || |              | || |              | || |              | || |     (_)      | |" << endl;
	cout << " | '--------------' || '--------------' || '--------------' || '--------------' | | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |" << endl;
	cout << "  '----------------'  '----------------'  '----------------'  '----------------'   '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << endl;
	exit(0);
}

void Global::stats()
{
	end();

	Player player;

	player.speed = 100;
	cout << " Speed: " << player.speed << endl;

	player.damage = 10;
	cout << " Damage: " << player.damage << endl;

	player.defense = 5;
	cout << " Defense: " << player.defense << endl;

	player.health = 20;
	cout << " Health: " << player.health << endl;
}

void Global::actions()
{
	if (input == "i")
	{
		Global::fullInvPlayer();
	}
	if (input == "stats")
	{
		Global::stats();
	}
	if (input == "help")
	{
		Global::help();
	}
}

void Global::help()
{
	end();

	cout << " Type 'n' for north" << endl;
	cout << " Type 'e' for east" << endl;
	cout << " Type 's' for south" << endl;
	cout << " Type 'w' for west" << endl;
	cout << " Type 'i' for inventory" << endl;
	cout << " Type 'stats' for your stats" << endl;
	end();
	cout << " Basic Commands: " << endl;
	cout << " pick up _____" << endl;
	cout << " use _____" << endl;
	cout << " attack ______" << endl;
	cout << " examine _____ this shows you the stats of thing you put in" << endl;
	end();
	cout << " Type help at any time to view these commands" << endl;
}

void Global::fullInvPlayer()
{
	end();

	cout << "You have a:" << endl;
	for (int p = 0; p < 10; p++)
	{
		cout << invPlayer[p];
	}
}