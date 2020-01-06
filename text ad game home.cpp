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
#include "Header.h"

using std::cout;
using std::flush;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
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
int gunBonus = 5;

//For colouring
bool colour = true;

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

void Global::no()
{
	print("What?");
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

void notEqual(string notA, string notB, string notC, string notD)
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

void Global::fullInvPlayer()
{
	end();

	cout << "You have a:" << endl;
	for (int p = 0; p < 10; p++)
	{
		cout << invPlayer[p];
	}
}

void House::livingRoom()
{
	print_slow(" Living Room. \n  You are in the middle of the living room, to the east is a floating couch.", 15);
	print_slow(" To the north is the dining room", 15);
	print_slow(" To the south is the backyard of the house", 15);
	getline(cin, input);

	House::action();
}

void House::openPackage()
{
	cout << " You open the package and find a black disc the size of a hockey puck and a note. It contains the first part of what seems to be a password." << endl;

	House::packActions();
	House::packActions();

	while (input != "s")
	{
		getline(cin, input);
		if (input == "s")
		{
			House::livingRoom();
		}
		if (input == "n" && input == "w" && input == "e")
		{
			cout << "That is a wall" << endl;
		}
		Global::actions();

		notEqual("s", "n", "w", "e");
	}
}

void House::backstory()
{
	//This is explaining the three password segments and the Quantum order from the black disc

	end();

	cout << " A blue holographic figure appears out of the disc and speaks to you. It says 'included in this package is a note that contains the key to saving world from the Quantum Order." << endl;
	Sleep(1700);

	cout << " The Quantum Order wants to gain absolute control of the world through the use of qauntum computers." << endl;
	Sleep(1700);

	cout << " They will be able to see everyone's information and will keep a constant watch over the entire world. Nobody will be free from their eyes." << endl;
	Sleep(1700);

	cout << " The only way to stop them is to use the password in the absolute point terminal which will cause a chain reaction that will destroy all " << endl;
	Sleep(1700);

	cout << " quantum computers around the world. The password has been split into three segments." << endl;
	Sleep(1700);

	cout << " The note included in this package has the first segment." << endl;
	Sleep(1700);

	cout << " You must find the other two segments and free humanity from the Quantum Order." << endl;
	Sleep(1700);

	cout << " Help us " << name << " you are our only hope. (not stolen shamelessly from Star Wars btw)" << endl;
}

void House::packActions()
{
	do
	{
		getline(cin, input);
		if (input == "pick up note" && dineRoomInv == "note")
		{
			invPlayer[1] = cyb1;
			dineRoomInv = "";
			cout << "picked up note" << endl;
		}
		if (input == "s")
		{
			House::livingRoom();
		}
		if (input == "n" && input == "w" && input == "e")
		{
			cout << "That is a wall" << endl;
		}
		if (input == "use disc")
		{
			House::backstory();
		}
		Global::actions();
		if (input != "pick up note" && input != "s" && input != "n" && input != "w" && input != "e" && input != "use disc" && input != "i" && input != "stats" && input != "help")
		{
			Global::no();
		}
	} while (input != "pick up note" && input != "s" && input != "use disc");
}

void House::dineRoomHouse()
{
	cout << " Dining room.\n You go to the dining table and see a package" << endl;
	do
	{
		getline(cin, input);
		if (input == "open package")
		{
			House::openPackage();
		}
		if (input == "s")
		{
			House::livingRoom();
		}
		if (input == "n" && input == "w" && input == "e")
		{
			cout << "That is a wall" << endl;
		}
		notEqual("open package", "use disc", "s", "pick up note");
	} while (input != "open package" && input != "s");
}

void House::action()
{

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
	if (input != "n" && input != "s" && input != "w" && input != "e" && input != "open package" &&
		input != "pick up note" && input != "help" && input != "stats" && input != "i" && input != "use disc")
	{
		print("What?");
	}
}

void Barracks::oActions()
{
	do {
		getline(cin, input);
		if (input == "s")
		{
			cout << " You walked into the bubble and were instantly vaporized. Your bones were turned into air molecules which floated away into space" << endl;

			Global::gameOver();
		}
		if (input == "w")
		{
			Barracks::westHall();
		}
		if (input == "e")
		{
			Guard::airlock();
		}
		if (input == "n")
		{
			House::livingRoom(); //Takes you back to the start
		}
		Global::actions();

		notEqual("n", "s", "e", "w");

	} while (input != "s" && input != "w" && input != "e" && input != "n");

}

void Barracks::oHouse()
{
	cout << " Outside The House.\n You are outside the house, you are standing on a lush green lawn." << endl;
	Sleep(700);

	cout << " There is a transparent bubble directly in front of you surrounding the perimeter of the house and lawn." << endl;
	Sleep(700);

	cout << " To the north is the living room inside the house where you started." << endl;
	Sleep(700);

	cout << " To the east is a white doorway in the bubble which looks to lead to another set of buildings." << endl; //this continues to the main story
	Sleep(700);

	cout << " To the west is a gray doorway which leads to a single building." << endl; //This is the barracks
	Barracks::oActions();
}

void Barracks::westHall()
{
	cout << " West Hall\n It is a long glowing hallway. There are flying orbs around you providing light. You see a door at the end of the hallway." << endl;

	cout << " To continue down the hallway go south." << endl;

	cout << " To go back go east" << endl;

	do {
		getline(cin, input);
		if (input == "s")
		{
			Barracks::westHall2();
		}
		if (input == "w" && input == "n")
		{
			Global::gameOver();
		}
		if (input == "e")
		{
			Barracks::oHouse();
		}
		Global::actions();

		notEqual("n", "s", "e", "w");

	} while (input != "s" && input != "e");
}

void Barracks::westHall2()
{
	cout << " End of West Hall.\n You reach the end of the hall." << endl;

	cout << " To the east there is a door leading into a room which looks to be stocked with guns and weapons." << endl;

	cout << " To the north is the exit." << endl;
	do {
		getline(cin, input);
		if (input == "n")
		{
			Barracks::westHall();
		}
		if (input == "w" && input == "s")
		{
			Global::gameOver();
		}
		if (input == "e")
		{
			Barracks::barracks();
		}
		Global::actions();

		notEqual("n", "s", "e", "w");

	} while (input != "n" && input != "e");
}

void Barracks::barracks()
{
	cout << " Barracks.\n You enter inside the room to see rack upon rack of neodynium exodus rifles (gun)." << endl;
	cout << " All of them are locked into the racks but you spot one that isn't." << endl;
	if (barracksinv != "gun")
	{
		cout << " You already took the gun" << endl;
	}
	do {
		getline(cin, input);
		if (input == "pick up gun" && barracksinv == "gun")
		{
			cout << "picked up gun" << endl;
			invPlayer[2] = gun;
			barracksinv = "";

		}
		if (input != "pick up gun" && input != "w" && input != "i" && input != "stats" && input != "help")
		{
			cout << "That is not something you can do" << endl;
		}
		if (input == "w")
		{
			Barracks::westHall2();
		}
		Global::actions();

	} while (input != "w");
}

void Guard::airlock()
{
	cout << " Airlock." << endl;
	cout << " The airlock is a small white room. There are a couple space suits and an array of tools. " << endl;
	cout << " To the south is a corridor leaing to a bigger building" << endl;
	cout << " To the east is another corridor which goes to a small building." << endl;

	//If you've already taken a suit then this says "You already took a space suit"
	if (airlockInv != " Space Suit")
	{
		cout << " You already took a space suit" << endl;
	}

	do {

		getline(cin, input);
		if (input == "s")
		{
			Guard::guardFight(); //Towards guard fight
		}
		if (input == "e")
		{
			DeadEndOne::eastHall();
		}
		if (input == "w")
		{
			Barracks::oHouse();
		}
		if (input == "pick up space suit" && airlockInv == " Space Suit")
		{
			cout << "picked up space suit" << endl;
			invPlayer[3] = " Space Suit";
			airlockInv = "";
		}
		Global::actions();

		notEqual("s", "e", "w", "pick up space suit");

	} while (input != "s" && input != "e" && input != "w");
}

void DeadEndOne::eastHall()
{
	cout << " East Hall." << endl;
	cout << " It is a well lit corridor, the walls are glowing blue." << endl;

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

		notEqual("w", "e", "", "");

	} while (input != "w" && input != "e");
}

void DeadEndOne::eastHallCont()
{
	cout << " End of East Hall." << endl;
	cout << " Lmao this was just a dead end. Go back fool." << endl;

	do {
		getline(cin, input);
		if (input == "w")
		{
			DeadEndOne::eastHall();
		}
		Global::actions();

		notEqual("w", "", "", "");

	} while (input != "w");
}

void Guard::guardFight()
{
	end();

	cout << " Main Hub." << endl;
	cout << " The corridor opens up into a massive rooom. The walls are white with blue accents. The ceiling is about 7 metres high." << endl;
	cout << " To the south is another corridor leading to the shipping bay. Blocking the corridor is a guard who looks to be holding a gun." << endl;
	cout << " To the east is another corridor leading to a different bay." << endl;
	do
	{
		getline(cin, input);
		if (input == "n")
		{
			Guard::airlock();
		}
		if (input == "e")
		{
			Guard::corridorImpossible();
		}
		if (input == "attack guard")
		{
			Guard::attackEasy();
		}
		if (input == "examine guard")
		{
			Guard::examineGuardOne();
		}
		Global::actions();

		notEqual("n", "attack guard", "examine guard", "e");

	} while (input != "n" && input != "e" && input != "attack guard");
}

void Guard::examineGuardOne()
{
	GuardEasy guard;

	end();
	cout << " Quantum Guard" << endl;

	cout << " Health: ";
	guard.showVariables("health");
	end();

	cout << " Damage: ";
	guard.showVariables("damage");
	end();

	cout << " Defense: ";
	guard.showVariables("defense");
	end();
}

void Guard::corridorImpossible()
{
	long long int secondsUntilGuardEat = 5; //The long long means the number can be a 64 bit integer. Basically a big number
	unsigned char pressedKey = NULL; //Unsigned char is used when dealing with numbers. unsigned is for -255 to 255
	long long int seconds_from_1970 = time(NULL); //this makes the time work.

	while (true)
	{
		if (_kbhit()) //kbhit will not wait for an input from the user before running the rest of the program
		{
			pressedKey = _getch(); //getchar is getline but only a character
			break;
		}
		if (seconds_from_1970 + secondsUntilGuardEat <= time(NULL))break;
		system("cls"); //Clears screen 

		print_slow("Corridor.", 30);
		print_slow("You walk down the corridor and at the end you find another corridor with a guard blocking it.", 15);
		print_slow("'1' to attack the guard", 30);
		print_slow("'2' to examine the guard", 30);
		print_slow("'3' to go west", 30);
		print_slow("If you do nothing the guard attack you", 15);

		cout << "The guard sees you and charges. You have " << seconds_from_1970 + secondsUntilGuardEat - time(NULL) << " seconds until the guard reaches you" << endl;
		Sleep(1000);
	}
	system("cls"); //Clears screen
	switch (pressedKey)
	{
	case '1':
		Guard::attackImpossible();

	case '2':

		Guard::examineImpossible();

	case '3':

		cout << "You try to run away but the guard has 1 billion speed and easily catches up with you." << endl;
		Sleep(500);

		cout << "The guard runs up and eats you. You died." << endl;

		Global::gameOver();

	default:

		cout << "You took to long. The guard ran up and ate your face off." << endl;
		Global::gameOver();

	}
}

void Guard::examineImpossible()
{
	GuardImpossible guard;

	end();

	cout << " Zero-Point Quantum Guard" << endl;

	cout << " Health: ";
	guard.showVariables("health");
	end();

	cout << " Damage: ";
	guard.showVariables("damage");
	end();

	cout << " Defense: ";
	guard.showVariables("defense");
	end();

	cout << " Speed: ";
	guard.showVariables("speed");
	end();

	getline(cin, input);
	Guard::corridorImpossible();
}

void Guard::attackImpossible()
{
	cout << "Choose a weapon to attack the guard with" << endl;
	do
	{
		getline(cin, input);
		if (input == "gun")
		{
			end();

			cout << "You shoot the guard but it does 0 damage as the guard has 1 billion defense" << endl;
			Sleep(500);

			cout << "The guard runs up and eats you. You died" << endl;
			Global::gameOver();
		}
		if (input == "fist")
		{
			end();

			cout << "You run up to the guard to punch him but before you can he eats you. You died." << endl;
			Global::gameOver();
		}
		Global::actions();

	} while (input != "use fist" && input != "use gun");
}

void Guard::attackEasy()
{
	srand(time(NULL)); // This makes the random # gen not gen the same number

	GuardEasy guard;
	Player player;
	end();

	cout << "What do you want to attack the guard with" << endl;
	do
	{
		getline(cin, input);
		if (input == "gun")
		{
			end();
			srand(time(NULL));

			int random = ((rand() % 5) + 1);
			int finalDamage = player.damage + gunBonus + random - guard.guardEasyReturnDefense();
			guard.minusVariables("health", finalDamage);

			cout << "You attack the guard with your gun. It does " << finalDamage << " damage" << endl;

			cout << "The guard has ";
			guard.showVariables("health");
			cout << " health left" << endl;

			getline(cin, input);
			Guard::guardAttacks();

		}
		if (input == "fist")
		{
			end();

			int randomes = ((rand() % 5) + 1);
			int finalDamageFist = player.damage + randomes - guard.guardEasyReturnDefense();
			guard.minusVariables("health", finalDamageFist);

			cout << "You fisted the guard with your fist. It does " << finalDamageFist << " damage." << endl;

			cout << "The guard has ";
			guard.showVariables("health");
			cout << " health left" << endl;

			getline(cin, input);
			Guard::guardAttacks();
		}
		Global::actions();

		notEqual("gun", "fist", "", "");

	} while (input != "gun" && input != "fist");
}

void Guard::guardAttacks()
{
	GuardEasy guard;
	Player player;

	srand(time(NULL));
	int randomIfDodged = ((rand() % 4) + 1);

	// Initialization
	ULARGE_INTEGER initialTime;
	ULARGE_INTEGER currentTime;
	FILETIME ft;
	GetSystemTimeAsFileTime(&ft);
	initialTime.LowPart = ft.dwLowDateTime;
	initialTime.HighPart = ft.dwHighDateTime;
	LONGLONG countdownStartTime = 30000000; // 100 Nano seconds
	LONGLONG displayedNumber = 4; // Prevent 31 to be displayed



	// Game loop
	while (true)
	{
		GetSystemTimeAsFileTime(&ft); // 100 nano seconds
		currentTime.LowPart = ft.dwLowDateTime;
		currentTime.HighPart = ft.dwHighDateTime;

		//// Read Input ////
		bool dodge = false;

		SHORT key = GetKeyState('1');
		if (key & 0x8000)
		{
			dodge = true;
		}

		//// Game Logic ////
		LONGLONG elapsedTime = currentTime.QuadPart - initialTime.QuadPart;
		LONGLONG currentNumber_100ns = countdownStartTime - elapsedTime;

		if (currentNumber_100ns <= 0)
		{
			system("cls");

			cout << "You took too long, the guard's shot hit you." << endl;
			Guard::failDodge();

			break;
		}
		if (dodge)
		{
			system("cls");

			if (randomIfDodged <= 2)
			{
				

				wcout << "You dodged the guard's shot!" << endl;
				end();

				Guard::damageGuard();

				print("You killed the guard! Congratulations");
				cout << "You gained 5 defense, 5 damage and 20 health" << endl;
				player.damage = 10;
				player.health = 40;
				player.defense = 10;

				exit(0);
			}
			else
			{
				cout << "You failed to dodge the guard's shot" << endl;
				Guard::failDodge();

				break;
			}
		}

		//// Render ////
		LONGLONG currentNumber_s = currentNumber_100ns / 10000000 + 1;
		if (currentNumber_s != displayedNumber) 
		{
			system("cls");

			cout << "The guard shoots at you." << endl;
			cout << "'1' To dodge the guards shot" << endl;

			end();

			cout << "You have " << currentNumber_s << " seconds to dodge the guard's shot" << endl;
			displayedNumber = currentNumber_s;
		}
	}
	system("pause");
}

void Guard::failDodge()
{
	GuardEasy guard;
	Player player;

	int finalDamageGuard = guard.guardEasyReturnDamage() - player.defense;
	player.health = player.health - finalDamageGuard;

	end();
	cout << "The guard's shot hits you in the chest. It does " << finalDamageGuard << " damage." << endl;

	end();
	Guard::damageGuard();

	print("You killed the guard! Congratulations");
	end();

	cout << "You gained 5 defense, 5 damage and 20 health" << endl;

	player.damage = 10;
	player.health = 40;
	player.defense = 10;

	exit(0);
}

void Guard::damageGuard()
{
	Player player;
	GuardEasy guard;

	int random = ((rand() % 5) + 1);
	int finalDamage = player.damage + gunBonus + random - guard.guardEasyReturnDefense();

	do
	{
		system("pause");
		system("cls");

		print("What would you like to do now?");
		getline(cin, input);
		if (input == "attack guard")
		{
			guard.minusVariables("health", finalDamage);
		}
		Global::actions();

		notEqual("attack guard", "", "", "");

	} while (input != "attack guard");
	end();

	cout << "You attack the guard with your gun. It does " << finalDamage << " damage" << endl;
	end();
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

int main()
{
	system("color b");

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

	print(" Please run this game in fullscreen for an optimal experience");
	system("pause");

	Sleep(200); 
	print_slow("You can press space to skip the typing animation and to continue", 15);
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

		notEqual("n", "s", "e", "w");

	} while (input != "n" && input != "s" && input != "w" && input != "e" && input != "use disc");

	return 0;
}

/*
do
{
	if (input == "")
	{

	}
	Global::actions();

	notEqual("", "", "", "");

} while (input != "" && input != "" && input != "" && input != "");
*/


