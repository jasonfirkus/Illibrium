#include "precompiled.h"
#include "declarations.h"
using namespace std;



int Global::extraDamage()
{
	srand(time(NULL));
	int random = ((rand() % 5) + 1);
	return random;
	
}

void Global::timer(int time1, int time2, string desc1, string desc2, string desc3, string desc4, function_identifier func1, function_identifier func2)
{
	// Initialization
	ULARGE_INTEGER initialTime;
	ULARGE_INTEGER currentTime;
	FILETIME ft;
	GetSystemTimeAsFileTime(&ft);
	initialTime.LowPart = ft.dwLowDateTime;
	initialTime.HighPart = ft.dwHighDateTime;
	LONGLONG countdownStartTime = time1; // 100 Nano seconds
	LONGLONG displayedNumber = time2; // Prevent 31 to be displayed

	// Game loop
	while (true)
	{
		GetSystemTimeAsFileTime(&ft); // 100 nano seconds
		currentTime.LowPart = ft.dwLowDateTime;
		currentTime.HighPart = ft.dwHighDateTime;

		//// Read Input ////
		bool keyPressed = false;

		SHORT key = GetKeyState('1');
		if (key & 0x8000)
		{
			keyPressed = true;
		}

		//// Game Logic ////
		LONGLONG elapsedTime = currentTime.QuadPart - initialTime.QuadPart;
		LONGLONG currentNumber_100ns = countdownStartTime - elapsedTime;

		if (currentNumber_100ns <= 0)
		{
			system("cls");

			cout << desc1 << endl;

			func1();


			break;
		}
		if (keyPressed)
		{
			system("cls");

			cout << desc2 << endl;

			func2();
			break;
		}

	
		//// Render ////
		LONGLONG currentNumber_s = currentNumber_100ns / 10000000 + 1;
		if (currentNumber_s != displayedNumber)
		{
			system("cls");
			cout << desc3 << endl;

			end();

			cout << "You have " << currentNumber_s << desc4 << endl;
			displayedNumber = currentNumber_s;
		}
	}
	end();
	system("pause");
}

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
	cout << "'get on ____ ship' " << endl;
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
