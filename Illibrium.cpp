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

//These are for the room inventory's and items that you can pickup
string cyb1 = " Cyberkey 1";
string gun = " Neodynium Exodus Rifle";
string barracksinv = "gun";
string dineRoomInv = "note";
string airlockInv = " Space Suit";

//Global variables
string input;
string name = "Good luck, " + name;

//Inventory Player
string invPlayer[10] = {};

//Using the gun when attacking bonus
const unsigned short int gunBonus = 5;

//For colouring
bool colour = true;

void print_room_1(string title, string desc1)
{
	end();

	print_slow_15(title);
	print_slow_15(desc1);
}

void print_room_2(string title, string desc1, string desc2)
{
	end();

	print_slow_15(title);
	print_slow_15(desc1);
	print_slow_15(desc2);
}

void print_room_3(string title, string desc1, string desc2, string desc3)
{
	end();

	print_slow_15(title);
	print_slow_15(desc1);
	print_slow_15(desc2);
	print_slow_15(desc3);
}

void print_room_4(string title, string desc1, string desc2, string desc3, string desc4)
{
	end();

	print_slow_15(title);
	print_slow_15(desc1);
	print_slow_15(desc2);
	print_slow_15(desc3);
	print_slow_15(desc4);
}

void end()
{
	cout << endl;
}

void printVar(string printText, int printVar)
{
	cout << printText << " " << printVar << endl;
}

void print(string print)
{
	cout << print << endl;
}

void not_equal(string notA, string notB, string notC, string notD)
{
	string notDirections[4] = { notA, notB, notC, notD };
	bool valid = false;

	for (int i = 0; i < 4; i++)
	{
		if (input == notDirections[i])
		{
			valid = true;
		}
	}
	if (!valid && input != "help" && input != "stats" && input != "i")
	{
		Global::no();
	}
}

void DeadEndOne::eastHall()
{
	print_slow_15(" East Hall.");
	print_slow_15(" It is a well lit corridor, the walls are glowing blue.");

	do {
		getline(cin, input);
		if (input == "w")
		{
			Guard::airlock();
		}
		if (input == "e")
		{
			DeadEndOne::eastHallCont();
		}
		Global::actions();

		not_equal("w", "e", "", "");

	} while (input != "w" && input != "e");
}

void DeadEndOne::eastHallCont()
{
	print_slow(" End of East Hall.", 15);
	print_slow(" Lmao this was just a dead end. Go back fool.", 15);

	do {
		getline(cin, input);
		if (input == "w")
		{
			DeadEndOne::eastHall();
		}
		Global::actions();

		not_equal("w", "", "", "");

	} while (input != "w");
}

void print_slow(const string& message, unsigned int typeSpeed)
{
	bool stop = false;
	for (const char c : message)
	{
		cout << c << flush;
		if (stop == false)
		{
			Sleep(typeSpeed);
		}
		SHORT key = GetKeyState(' ');
		if (key & 0x8000)
		{
			stop = true;
		}
	}
	end();
}

void print_slow_no_space(const string& message, unsigned int typeSpeed)
{
	bool stop = false;
	for (const char c : message)
	{
		cout << c << flush;
		if (stop == false)
		{
			Sleep(typeSpeed);
		}
		SHORT key = GetKeyState(' ');
		if (key & 0x8000)
		{
			stop = true;
		}
	}
}

void print_slow_15(const string& message)
{
	Sleep(200);
	bool stop = false;
	for (const char c : message)
	{
		cout << c << flush;
		if (stop == false)
		{
			Sleep(15);
		}
		SHORT key = GetKeyState(' ');
		if (key & 0x8000)
		{
			stop = true;
		}
	}
	end();
}

int main()
{
	system("color 3");

	getline(cin, input);

	//This is to skip to certain functions for testing
	if (input == "guard airlock")
	{
		Guard::airlock();
	}
	if (input == "guard fight")
	{
		Guard::guardFight();
	}
	if (input == "dead")
	{
		Global::gameOver();
	}
	if (input == "fight")
	{
		Guard::guardAttacks();
	}
	IF_("help", Global::help();)
	IF_("hanger", Hanger::landingBay();)

	print(" Please run this game in fullscreen for an optimal experience");
	end();
	system("pause");
	end();

	Sleep(200);
	print_slow("You can press space to skip the typing animation and to continue", 15);
	end();
	system("pause");

	end();

	system("cls");

	cout << " ___       __   _______   ___       ________  ________  _____ ______   _______        _________  ________       ___  ___       ___       ___  ________  ________  ___  ___  ___  ______   ____" << endl;
	cout << "|\\  \\     |\\  \\|\\  ___ \\ |\\  \\     |\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\      |\\___   ___|\\   __  \\     |\\  \\|\\  \\     |\\  \\     |\\  \\|\\   __  \\|\\   __  \\|\\  \\|\\  \\|\\  \\|\\   _ \\  \\\\  \\ " << endl;
	cout << "\\ \\  \\    \\ \\  \\ \\   __/|\\ \\  \\    \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|     \\|___ \\  \\_\\ \\  \\|\\  \\    \\ \\  \\ \\  \\    \\ \\  \\    \\ \\  \\ \\  \\|\\ /\\ \\  \\|\\  \\ \\  \\ \\  \\\\\\  \\ \\  \\\\ \\__\\\\  \\" << endl;
	cout << " \\ \\  \\  __\\ \\  \\ \\  \\_|/_\\ \\  \\    \\ \\  \\    \\ \\  \\\\\\  \\ \\  \\\\|__| \\  \\ \\  \\_|/__        \\ \\  \\ \\ \\  \\\\\\  \\    \\ \\  \\ \\  \\    \\ \\  \\    \\ \\  \\ \\   __  \\ \\   _  _\\ \\  \\ \\  \\\\\\  \\ \\  \\\\|__| \\  \\" << endl;
	cout << "  \\ \\  \\|\\__\\_\\  \\ \\  \\_|\\ \\ \\  \\____\\ \\  \\____\\ \\  \\\\\\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\        \\ \\  \\ \\ \\  \\\\\\  \\    \\ \\  \\ \\  \\____\\ \\  \\____\\ \\  \\ \\  \\|\\  \\ \\  \\\\  \\\\ \\  \\ \\  \\\\\\  \\ \\  \\    \\ \\  \\" << endl;
	cout << "   \\ \\____________\\ \\_______\\ \\_______\\ \\_______\\ \\_______\\ \\__\\    \\ \\__\\ \\_______\\        \\ \\__\\ \\ \\_______\\    \\ \\__\\ \\_______\\ \\_______\\ \\__\\ \\_______\\ \\__\\\\ _\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\" << endl;
	cout << "    \\|____________|\\|_______|\\|_______|\\|_______|\\|_______|\\|__|     \\|__|\\|_______|         \\|__|  \\|_______|     \\|__|\\|_______|\\|_______|\\|__|\\|_______|\\|__|\\|__|\\|__|\\|_______|\\|__|     \\|__|" << endl;
	end();

	Sleep(200);
	print_slow("Welcome to Illibrium", 30);
	end();
	system("pause");
	end();

	Sleep(200);
	print_slow(" You are in the year 2070 and an evil organization is plotting to take over the world and you must stop them.", 15);
	end();
	system("pause");
	end();

	Sleep(200);
	print_slow(" You will play as a rebel trying to overthrow them. You are also on the moon.", 15);
	end();
	system("pause");
	end();

	Sleep(200);
	print_slow(" What is your name rebel? \n(enter your name)", 15);
	cin.ignore(0, '\n');
	getline(cin, name);
	end();

	Sleep(200);
	print_slow_no_space("Good luck, ", 30);
	print_slow_no_space(name, 30);
	end();
	system("pause");
	end();

	Sleep(200);
	print_slow(" Welcome to Illibrium", 30);
	end();
	system("pause");
	end();

	system("cls");

	end();

	Sleep(200);
	print_slow(" You are in the living room of your house.", 15);

	Sleep(200);
	print_slow(" To the north there is a dining room with the remains of last nights dinner and what looks to be a package.", 15);

	Sleep(200);
	print_slow(" To the south there is a door leading to the backyard", 15);

	Sleep(200);
	print_slow(" To the east there is a floating sofa", 15);

	Global::help();

	do
	{
		getline(cin, input);
		if (input == "s")
		{
			Barracks::oHouse();
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
			House::dineRoomHouse();
		}
		Global::actions();

		not_equal("n", "s", "e", "w");

	} while (input != "n" && input != "s" && input != "w" && input != "e" && input != "use disc" && input != "attack guard");
}

/*
do
{
	if (input == "")
	{

	}
	Global::actions();

	not_equal("", "", "", "");

} while (input != "" && input != "" && input != "" && input != "");
*/


