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
using namespace std;

string input;
string invPlayer[5] = {};

void actions();
void dineRoomHouse();
void actionsHouse();
void outsideHouseActions();
void fullInvPlayer();

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

void outsideHouse()
{
	cout << " You are outside your house, you are standing on a lush green lawn. There is a transparent bubble surrounding the perimeter of the house and lawn.\n" << endl;
}

void stats()
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
	actionsHouse();
}

void help()
{
	cout << "Type 'n' for north" << endl;
	cout << "Type 'e' for east" << endl;
	cout << "Type 's' for south" << endl;
	cout << "Type 'w' for west" << endl;
	cout << "Type 'i' for inventory" << endl;
	cout << "Type 'stats' for your stats" << endl;
	getline(cin, input);
	actionsHouse();
}

void fullInvPlayer()
{
	for (int p = 0; p < 5; p++)
	{
		cout << invPlayer[p];
	}
	getline(cin, input);
	actionsHouse();
}

void livingRoom()
{
	cout << " Living Room. \n You are in the middle of the living room" << endl;
	getline(cin, input);
	actionsHouse();
}

void openPackage()
{
	cout << "You open the package and find a black disc the size of a hockey puck and a crimson emerald knife. It is about 9 inches in length." << endl;
	getline(cin, input);
	if (input == "pick up knife")
	{
	string knife = "emerald knife";
	invPlayer[1] = knife;
	cout << "picked up knife" << endl;
	}
	actionsHouse();
}

void dineRoomHouse()
{
		cout << " Dining room.\n You go to the dining table and see a package" << endl;
		getline(cin, input);
		if (input == "open package")
		{
			openPackage();
		}
		actionsHouse();
}

void actionsHouse()
{
	if (input == "s")
	{
		livingRoom();
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
		dineRoomHouse();
	}
	actions();
	if (input != "n" && input != "s" && input != "w" && input != "e" && input != "open package" && input != "pick up knife" && input != "help" && input != "stats" && input != "i")
	{
		no();
	}
}

void outsideHouseActions()
{
	if (input == "s")
	{
		livingRoom();
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
		dineRoomHouse();
	}
	actions();
	if (input != "n" && input != "s" && input != "w" && input != "e" && input != "help" && input != "stats" && input != "i")
	{
		no();
	}
}

void actions()
{
	if (input == "i")
	{
		fullInvPlayer();
	}
	if (input == "stats")
	{
		stats();
	}
	if (input == "help")
	{
		help();
	}
}

int main()
{
	string c;
	string name;
	invPlayer[4] = "bobobobobobo";
	cout << " ___       __   _______   ___       ________  ________  _____ ______   _______        _________  ________       ___  ___       ___       ___  ________  ________  ___  ___  ___  _____ ______" << endl;
	cout << "|\\  \\     |\\  \\|\\  ___ \\ |\\  \\     |\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\      |\\___   ___|\\   __  \\     |\\  \\|\\  \\     |\\  \\     |\\  \\|\\   __  \\|\\   __  \\|\\  \\|\\  \\|\\  \\|\\   _ \\  _   \\ " << endl;
	cout << "\\ \\  \\    \\ \\  \\ \\   __/|\\ \\  \\    \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|     \\|___ \\  \\_\\ \\  \\|\\  \\    \\ \\  \\ \\  \\    \\ \\  \\    \\ \\  \\ \\  \\|\\ /\\ \\  \\|\\  \\ \\  \\ \\  \\\\\\  \\ \\  \\\\\\__\\ \\  \\" << endl;
	cout << " \\ \\  \\  __\\ \\  \\ \\  \\_|/_\\ \\  \\    \\ \\  \\    \\ \\  \\\\\\  \\ \\  \\\\|__| \\  \\ \\  \\_|/__        \\ \\  \\ \\ \\  \\\\\\  \\    \\ \\  \\ \\  \\    \\ \\  \\    \\ \\  \\ \\   __  \\ \\   _  _\\ \\  \\ \\  \\\\\\  \\ \\  \\\\|__| \\  \\" << endl;
	cout << "  \\ \\  \\|\\__\\_\\  \\ \\  \\_|\\ \\ \\  \\____\\ \\  \\____\\ \\  \\\\\\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\        \\ \\  \\ \\ \\  \\\\\\  \\    \\ \\  \\ \\  \\____\\ \\  \\____\\ \\  \\ \\  \\|\\  \\ \\  \\\\  \\\\ \\  \\ \\  \\\\\\  \\ \\  \\    \\ \\  \\" << endl;
	cout << "   \\ \\____________\\ \\_______\\ \\_______\\ \\_______\\ \\_______\\ \\__\\    \\ \\__\\ \\_______\\        \\ \\__\\ \\ \\_______\\    \\ \\__\\ \\_______\\ \\_______\\ \\__\\ \\_______\\ \\__\\\\ _\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\" << endl;
	cout << "    \\|____________|\\|_______|\\|_______|\\|_______|\\|_______|\\|__|     \\|__|\\|_______|         \\|__|  \\|_______|     \\|__|\\|_______|\\|_______|\\|__|\\|_______|\\|__|\\|__|\\|__|\\|_______|\\|__|     \\|__|" << endl;

	cout << " You are in the year 2070, an evil organization is plotting to take over the world and you must stop them. (enter)" << endl;
	getline(cin, c);

	cout << " You will play as a rebel trying to overthrow them. You are also on the moon. (enter)" << endl;
	getline(cin, c);

	cout << " What is your name rebel? (enter your name)\n" << endl;
	cin.ignore(0, '\n');
	getline(cin, name);

	cout << " Good luck, (enter)" << endl;
	getline(cin, c);

	cout << " Welcome to Illibrium " << name << " (enter)" << endl;
	getline(cin, c);

	if (system("CLS")) system("clear");
	cout << endl;
	cout << " You are in the living room of your house on the Moon, there is a sofa to the east." << endl;
	Sleep(500);

	cout << " To the north there is a dining room with the remains of last nights dinner and what looks to be a package." << endl;
	Sleep(500);

	cout << " To the south there is a door leading to the backyard" << endl;
	Sleep(500);

	cout << " To the east there is a floating sofa" << endl;
	Sleep(500);

	cout << endl;
	help();
	cout << "There are also basic commands you can perform such as 'pick up ____' or 'open ____' 'attack ____' Type help at any time to view these commands" << endl;
	
	while (input != "n" && input != "s" && input != "w" && input != "e" && input != "open package" && input != "pick up knife" && input != "help" && input != "stats" && input != "i")
	{
		getline(cin, input);
		if (input == "s")
		{

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
			dineRoomHouse();
		}
		if (input == "i")
		{
			fullInvPlayer();
		}
		if (input == "stats")
		{
			stats();
		}
		if (input == "help")
		{
			help();
		}
		if (input != "n" && input != "s" && input != "w" && input != "e" && input != "open package" && input != "pick up knife" && input != "help" && input != "stats" && input != "i")
		{
			no();
		}
	}

	return 0;
}
