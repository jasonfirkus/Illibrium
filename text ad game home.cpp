#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>
#include <conio.h>
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include "Header.h"
using namespace std;

string input;
string invPlayer[5] = {};

void global::stats();
void outsideHouse();
void global::actions();
void house::dineRoomHouse();
void outsideHouseActions();
void global::fullInvPlayer();
void no();
void global::help();
void house::openPackage();
void house::livingRoom();
void house::packActions();
void house::action();



void no()
{
	cout << "What?" << endl;
}

/*enum directions
{
	north,
	south,
	west,
	east,
}*/

void global::stats()
{

	int speedPlayer;
	speedPlayer = 100;
	cout << " Speed: " << speedPlayer << endl;

	int strengthPlayer;
	strengthPlayer = 100;
	cout << " Strength: " << strengthPlayer << endl;

	int defensePlayer;
	defensePlayer = 100;
	cout << " Defense: " << defensePlayer << endl;

	int healthPlayer;
	healthPlayer = 100;
	cout << " Health: " << healthPlayer << endl;
	getline(cin, input);
	house::action();
}

void global::help()
{
	cout << "Type 'n' for north" << endl;
	cout << "Type 'e' for east" << endl;
	cout << "Type 's' for south" << endl;
	cout << "Type 'w' for west" << endl;
	cout << "Type 'i' for inventory" << endl;
	cout << "Type 'stats' for your stats" << endl;
	cout << "There are also basic commands you can perform such as 'pick up ____' or 'open ____' 'attack ____' Type help at any time to view these commands" << endl;
	getline(cin, input);
	house::action();
}

void global::actions()
{
	if (input == "i")
	{
		global::fullInvPlayer();
	}
	if (input == "stats")
	{
		global::stats();
	}
	if (input == "help")
	{
		global::help();
	}
}

void global::fullInvPlayer()
{
	for (int p = 0; p < 5; p++)
	{
		cout << invPlayer[p];
	}
	getline(cin, input);
	house::action();
}

void house::livingRoom()
{
	cout << " Living Room. \n You are in the middle of the living room" << endl;
	getline(cin, input);

	house::action();
}

void house::openPackage()
{
	cout << "You open the package and find a black disc the size of a hockey puck and a note. It contains the first part of what seems to be a password." << endl;

	house::packActions();
	house::packActions();
	
	while (input != "s")
	{
		getline(cin, input);
		if (input == "s")
		{
			livingRoom();
		}
		if (input == "n" && input == "w" && input == "e")
		{
			cout << "That is a wall" << endl;
		}
		if (input != "s" && input != "n")
		{
			no();
		}
	}
}

void house::packActions()
{
	do
	{
		getline(cin, input);
		if (input == "pick up note")
		{
			string cyb1 = "Cyberkey 1";
			invPlayer[1] = cyb1;

			cout << "picked up note" << endl;
		}
		if (input == "s")
		{
			house::livingRoom();
		}
		if (input == "n" && input == "w" && input == "e")
		{
			cout << "That is a wall" << endl;
		}
		if (input == "use disc")
		{
			cout << "A blue holographic figure appears out of the disc and speaks to you" << endl;
		}
		if (input != "pick up note" && input != "s" && input != "n" && input != "w" && input != "e" && input != "use disc")
		{
			no();
		}
	} while (input != "pick up note" && input != "s" && input != "use disc");
}

void house::dineRoomHouse()
{
	cout << " Dining room.\n You go to the dining table and see a package" << endl;
	do
	{
		getline(cin, input);
		if (input == "open package")
		{
			house::openPackage();
		}
		if (input == "s")
		{
			house::livingRoom();
		}
		if (input == "n" && input == "w" && input == "e")
		{
			cout << "That is a wall" << endl;
		}
		if (input != "open package" && input != "use disc" && input != "s" && input != "pick up note")
		{
			no();
		}
	} while (input != "open package" && input != "s");
}

void house::action()
{

	if (input == "s")
	{
		outsideHouse();
	}
	if (input == "w")
	{
		cout << "That is a wall" << endl;
	}
	if (input == "e")
	{
		cout << "You sat on the sofa. Congratulations!!!!" << endl;
	}
	if (input == "n")
	{
		house::dineRoomHouse();
	}
	global::actions();
	if (input != "n" && input != "s" && input != "w" && input != "e" && input != "open package" &&
		input != "pick up note" && input != "help" && input != "stats" && input != "i" && input != "use disc")
	{
		no();
	}
}

void outsideHouseActions()
{
	if (input == "s")
	{
		house::livingRoom();
	}
	if (input == "w")
	{
		cout << "That is a wall" << endl;
	}
	if (input == "e")
	{
		cout << "You sat on the sofa. Congratulations!!!!" << endl;
	}
	if (input == "n")
	{
		house::dineRoomHouse();
	}
	global::actions();
	if (input != "n" && input != "s" && input != "w" && input != "e" && input != "help" && input != "stats" && input != "i")
	{
		no();
	}
}

void outsideHouse()
{
	cout << " Outside The House.\n You are outside the house, you are standing on a lush green lawn.";
	cout << "There is a transparent bubble directly in front of you surrounding the perimeter of the house and lawn." << endl;
	Sleep(2000);

	cout << " To the north is the living room inside the house." << endl;
	Sleep(2000);

	cout << "To the east is a white door in the bubble which looks to lead to another set of buildings." << endl;
	Sleep(2000);

	cout << "To the west is a gray door which leads to a single building." << endl;
}

int main()
{
	string name;

	cout << " ___       __   _______   ___       ________  ________  _____ ______   _______        _________  ________       ___  ___       ___       ___  ________  ________  ___  ___  ___  ______   ____" << endl;
	cout << "|\\  \\     |\\  \\|\\  ___ \\ |\\  \\     |\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\      |\\___   ___|\\   __  \\     |\\  \\|\\  \\     |\\  \\     |\\  \\|\\   __  \\|\\   __  \\|\\  \\|\\  \\|\\  \\|\\   _ \\  \\\\  \\ " << endl;
	cout << "\\ \\  \\    \\ \\  \\ \\   __/|\\ \\  \\    \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|     \\|___ \\  \\_\\ \\  \\|\\  \\    \\ \\  \\ \\  \\    \\ \\  \\    \\ \\  \\ \\  \\|\\ /\\ \\  \\|\\  \\ \\  \\ \\  \\\\\\  \\ \\  \\\\ \\__\\\\  \\" << endl;
	cout << " \\ \\  \\  __\\ \\  \\ \\  \\_|/_\\ \\  \\    \\ \\  \\    \\ \\  \\\\\\  \\ \\  \\\\|__| \\  \\ \\  \\_|/__        \\ \\  \\ \\ \\  \\\\\\  \\    \\ \\  \\ \\  \\    \\ \\  \\    \\ \\  \\ \\   __  \\ \\   _  _\\ \\  \\ \\  \\\\\\  \\ \\  \\\\|__| \\  \\" << endl;
	cout << "  \\ \\  \\|\\__\\_\\  \\ \\  \\_|\\ \\ \\  \\____\\ \\  \\____\\ \\  \\\\\\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\        \\ \\  \\ \\ \\  \\\\\\  \\    \\ \\  \\ \\  \\____\\ \\  \\____\\ \\  \\ \\  \\|\\  \\ \\  \\\\  \\\\ \\  \\ \\  \\\\\\  \\ \\  \\    \\ \\  \\" << endl;
	cout << "   \\ \\____________\\ \\_______\\ \\_______\\ \\_______\\ \\_______\\ \\__\\    \\ \\__\\ \\_______\\        \\ \\__\\ \\ \\_______\\    \\ \\__\\ \\_______\\ \\_______\\ \\__\\ \\_______\\ \\__\\\\ _\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\" << endl;
	cout << "    \\|____________|\\|_______|\\|_______|\\|_______|\\|_______|\\|__|     \\|__|\\|_______|         \\|__|  \\|_______|     \\|__|\\|_______|\\|_______|\\|__|\\|_______|\\|__|\\|__|\\|__|\\|_______|\\|__|     \\|__|" << endl;

	cout << " You are in the year 2070, an evil organization is plotting to take over the world and you must stop them. \n(enter)" << endl;
	getline(cin, input);
	if (input == "sk") // To skip to open package function for testing
	{
		house::openPackage();
	}

	cout << " You will play as a rebel trying to overthrow them. You are also on the moon. \n(enter)" << endl;
	getline(cin, input);

	cout << " What is your name rebel? \n(enter your name)" << endl;
	cin.ignore(0, '\n');
	getline(cin, name);

	cout << " Good luck, " << name << "\n(enter)" << endl;
	getline(cin, input);

	cout << " Welcome to Illibrium\n (enter)" << endl;
	getline(cin, input);

	if (system("CLS")) system("clear");

	cout << endl;
	cout << " You are in the living room of your house." << endl;
	Sleep(500);

	cout << " To the north there is a dining room with the remains of last nights dinner and what looks to be a package." << endl;
	Sleep(500);

	cout << " To the south there is a door leading to the backyard" << endl;
	Sleep(500);

	cout << " To the east there is a floating sofa" << endl;
	Sleep(500);

	cout << endl;
	global::help();

	while (input != "n" && input != "s" && input != "w" && input != "e" && input != "help" && input != "stats" && input != "i" && input != "use disc")
	{
		getline(cin, input);
		if (input == "s")
		{
			outsideHouse();
		}
		if (input == "w")
		{
			cout << "That is a wall" << endl;
		}
		if (input == "e")
		{
			cout << "You sat on the sofa. Congratulations!!!!" << endl;
		}
		if (input == "n")
		{
			house::dineRoomHouse();
		}
		if (input == "i")
		{
			global::fullInvPlayer();
		}
		if (input == "stats")
		{
			global::stats();
		}
		if (input == "help")
		{
			global::help();
		}
		if (input != "n" && input != "s" && input != "w" && input != "e" && input != "help" && input != "stats" && input != "i")
		{
			no();
		}
	}

	return 0;
}
