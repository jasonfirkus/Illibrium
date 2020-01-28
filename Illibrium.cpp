#include "precompiled.h"
#include "declarations.h"
using namespace std;

#pragma comment(lib, "Winmm.lib")

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
string invPlayer[11] = {};

//Using the gun when attacking bonus
const unsigned short int gunBonus = 5;

//For colouring
bool colour = true;

void center(string words)
{
	int console_width = 240;
	int len = words.length();
	cout << setw((console_width / 2) + len / 2) << right << words << endl;
}

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
		print("Nani? Doiu imidesu ka?");
	}
}

void DeadEndOne::eastHall()
{
	print_slow_15(" East Hall.");
	print_slow_15(" It is a well lit corridor, the walls are glowing blue.");

	do {
		end(); cout << ">>"; getline(cin, input);
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
		end(); cout << ">>"; getline(cin, input);
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
	SP_
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
	thread xp(Global::xp);
	mciSendString(TEXT("open \"undetale.mp3\" type mpegvideo alias undertale"), NULL, 0, NULL);
	mciSendString(TEXT("play undertale"), NULL, 0, NULL);

	SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_

	cout << "                                                                       ___   ___        ___        ___   ________   ________   ___   ___  ___   _____ ______      " << endl;
	cout << "                                                                      |\\  \\ |\\  \\      |\\  \\      |\\  \\ |\\   __  \\ |\\   __  \\ |\\  \\ |\\  \\|\\  \\ |\\   _ \\  _   \\    " << endl;
	cout << "                                                                      \\ \\  \\\\ \\  \\     \\ \\  \\     \\ \\  \\\\ \\  \\|\\ /_\\ \\  \\|\\  \\\\ \\  \\\\ \\  \\\\\\  \\\\ \\  \\\\\\__\\ \\  \\   " << endl;
	cout << "                                                                       \\ \\  \\\\ \\  \\     \\ \\  \\     \\ \\  \\\\ \\   __  \\\\ \\   _  _\\\\ \\  \\\\ \\  \\\\\\  \\\\ \\  \\\\|__| \\  \\  " << endl;
	cout << "                                                                        \\ \\  \\\\ \\  \\____ \\ \\  \\____ \\ \\  \\\\ \\  \\|\\  \\\\ \\  \\\\  \\|\\ \\  \\\\ \\  \\\\\\  \\\\ \\  \\    \\ \\  \\ " << endl;
	cout << "                                                                         \\ \\__\\\\ \\_______\\\\ \\_______\\\\ \\__\\\\ \\_______\\\\ \\__\\\\ _\\ \\ \\__\\\\ \\_______\\\\ \\__\\    \\ \\__\\" << endl;
	cout << "                                                                          \\|__| \\|_______| \\|_______| \\|__| \\|_______| \\|__|\\|__| \\|__| \\|_______| \\|__|     \\|__|\n \n \n \n" << endl;
#if VERSION == 1
	// SP_ SP_ SP_ SP_ SP_ SP_ SP_ SP_
	cout << "                                                                                                          Press enter to continue ";
	getline(cin, input);
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
	IF_("pak", House::dineRoomHouse();)
#else
	print_slow_15("Press space to continue");
#endif

	Global::menu();

	CLS
	WAIT
	CLS

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
	end();
	cout << ">>";
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
		end(); cout << ">>"; getline(cin, input);
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

/* This is the actual timer
srand(time(NULL));
int randomIfDodged = ((rand() % 4) + 1);

// Initialization
ULARGE_INTEGER initialTime;
ULARGE_INTEGER currentTime;
FILETIME ft;
GetSystemTimeAsFileTime(&ft);
initialTime.LowPart = ft.dwLowDateTime;
initialTime.HighPart = ft.dwHighDateTime;
LONGLONG countdownStartTime = 100000000; // 100 Nano seconds
LONGLONG displayedNumber = 11; // Prevent 31 to be displayed

// Game loop
while (true)
{
	GetSystemTimeAsFileTime(&ft); // 100 nano seconds
	currentTime.LowPart = ft.dwLowDateTime;
	currentTime.HighPart = ft.dwHighDateTime;

	//// Read Input ////


	//// Game Logic ////
	LONGLONG elapsedTime = currentTime.QuadPart - initialTime.QuadPart;
	LONGLONG currentNumber_100ns = countdownStartTime - elapsedTime;

	if (currentNumber_100ns <= 0)
	{
		system("cls");

		cout << "" << endl;

		timerDone = true;
		break;
	}
	if (keyDPressed == true && keyOPressed == true && keyD2Pressed == true && keyGPressed == true && keyEPressed == true)
	{
		system("cls");

		if (randomIfDodged <= 2)
		{
			wcout << "" << endl;
			end();

			print("");
			cout << "" << endl;

			break;
		}
		else
		{
			cout << "" << endl;

			break;
		}
	}


	LONGLONG currentNumber_s = currentNumber_100ns / 10000000 + 1;
	system("cls");

	cout << "You have " << currentNumber_s << " " << endl;
	displayedNumber = currentNumber_s;
	if (keyDPressed == true)
	{
		cout << "d";
	}
	if (keyOPressed == true)
	{
		cout << "o";
	}
	if (keyD2Pressed == true)
	{
		cout << "d";
	}
	if (keyGPressed == true)
	{
		cout << "g";
	}
	if (keyEPressed == true)
	{
		cout << "e";
	}
	Sleep(70);
}
end();
system("pause");

//Put this in the function that you are calling the timer function
			thread one(Guard::guardAttacks);
			while (timerDone != true)
			{
				SHORT keyD = GetKeyState('D');
				SHORT keyO = GetKeyState('O');
				SHORT keyD2 = GetKeyState('D');
				SHORT keyG = GetKeyState('G');
				SHORT keyE = GetKeyState('E');
				if (keyD & 0x8000)
				{
					keyDPressed = true;
				}
				if (keyO & 0x8000)
				{
					keyOPressed = true;
				}
				if (keyD2 & 0x8000)
				{
					keyD2Pressed = true;
				}
				if (keyG & 0x8000)
				{
					keyGPressed = true;
				}
				if (keyE & 0x8000)
				{
					keyEPressed = true;
				}
			}
			one.join();
*/


