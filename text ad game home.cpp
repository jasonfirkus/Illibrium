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
#include <chrono>
using namespace std;

//These are for the room inventory's
string cyb1 = " Cyberkey 1";
string gun = " Neodynium Exodus Rifle";
string barracksinv = "gun";
string dineRoomInv = "note";
string airlockInv = " Space Suit";

//Global variables
string input;
string name;

//Inventory Player
string invPlayer[10] = {};


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


class GuardEasy
{
	public:
		void showVariables(string show)
		{
			if (show == "health")
			{
				cout << health << endl;
			}
			if (show == "damage")
			{
				cout << damage << endl;
			}
			if (show == "defense")
			{
				cout << defense << endl;
			}
		}

	private:
		string check;
		int health = 10;
		int damage = 10;
		int defense = 5;
};

void Global::gameOver()
{
	cout << " You walked into the bubble and were instantly vaporized. Your bones were turned into air molecules which floated away into space" << endl;
	cout << "  .----------------.  .----------------.  .----------------.  .----------------.   .----------------.  .----------------.  .----------------.  .----------------.  .----------------. " << endl;
	cout << " | .--------------. || .--------------. || .--------------. || .--------------. | | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |" << endl;
	cout << " | |    ______    | || |      __      | || | ____    ____ | || |  _________   | | | |     ____     | || | ____   ____  | || |  _________   | || |  _______     | || |              | |" << endl;
	cout << " | |  .' ___  |   | || |     /  \\     | || ||_   \\  /   _|| || | |_   ___  |  | | | |   .'    `.   | || ||_  _| |_  _| | || | |_   ___  |  | || | |_   __ \\    | || |      _       | |" << endl;
	cout << " | | / .'   \\_|   | || |    / /\\ \\    | || |  |   \\/   |  | || |   | |_  \\_|  | | | |  /  .--.  \\  | || |  \\ \\   / /   | || |   | |_  \\_|  | || |   | |__) |   | || |     | |      | |" << endl;
	cout << " | | | |    ____  | || |   / ____ \\   | || |  | |\\  /| |  | || |   |  _|  _   | | | |  | |    | |  | || |   \\ \\ / /    | || |   |  _|  _   | || |   |  __ /    | || |     | |      | |" << endl;
	cout << " | | \\ `.___]  _| | || | _/ /    \\ \\_ | || | _| |_\\/_| |_ | || |  _| |___/ |  | | | |  \\  `--'  /  | || |    \\ ' /     | || |  _| |___/ |  | || |  _| | \\ \\_  | || |     | |      | |" << endl;
	cout << " | |  `._____.'   | || ||____|  |____|| || ||_____||_____|| || | |_________|  | | | |   `.____.'   | || |     \\_/      | || | |_________|  | || | |____| |___| | || |     |_|      | |" << endl;
	cout << " | |              | || |              | || |              | || |              | | | |              | || |              | || |              | || |              | || |     (_)      | |" << endl;
	cout << " | '--------------' || '--------------' || '--------------' || '--------------' | | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |" << endl;
	cout << "  '----------------'  '----------------'  '----------------'  '----------------'   '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << endl;
	exit(0);
}

void Global::no()
{
	cout << "What?" << endl;
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
		cout << "What" << endl;
	}
}

/*enum directions
{
	north,
	south,
	west,
	east,
}*/

void Global::stats()
{
	cout << endl;

	Player player;

	player.speed = 100;
	cout << " Speed: " << player.speed << endl;

	player.damage = 10;
	cout << " Damage: " << player.damage << endl;

	player.defense = 5;
	cout << " Defense: " << player.defense << endl;

	player.health = 100;
	cout << " Health: " << player.health << endl;
}

void Global::help()
{
	cout << endl;

	cout << " Type 'n' for north" << endl;
	cout << " Type 'e' for east" << endl;
	cout << " Type 's' for south" << endl;
	cout << " Type 'w' for west" << endl;
	cout << " Type 'i' for inventory" << endl;
	cout << " Type 'stats' for your stats" << endl;
	cout << " Basic Commands: " << endl;
	cout << " pick up _____" << endl;
	cout << " use _____" << endl;
	cout << " attack ______" << endl;
	cout << " examine _____ this shows you the stats of thing you put in" << endl;
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
	cout << endl;

	cout << "You have a:" << endl;
	for (int p = 0; p < 10; p++)
	{
		cout << invPlayer[p];
	}
}

void House::livingRoom()
{
	cout << " Living Room. \n  You are in the middle of the living room\n To the east is a floating couch." << endl;
	cout << " To the north is the dining room" << endl;
	cout << " To the south is the backyard of the house" << endl;
	getline(cin, input);

	House::action();
}

void House::openPackage()
{
	cout << "You open the package and find a black disc the size of a hockey puck and a note. It contains the first part of what seems to be a password." << endl;

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

	cout << endl;

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
		Global::no();
	}
}

void Barracks::oActions()
{
	do {
		getline(cin, input);
		if (input == "s")
		{
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

	cout << endl;
	cout << " Quantum Guard" << endl;

	cout << " Health: ";
	guard.showVariables("health");
	cout << endl;

	cout << " Damage: ";
	guard.showVariables("damage");
	cout << endl;

	cout << " Defense: ";
	guard.showVariables("defense");
	cout << endl;
}

void Guard::corridorImpossible()
{
	cout << "Corridor." << endl;
	cout << "You walk down the corridor and at the end you find another corridor with a guard blocking it." << endl;
	cout << "The guard sees you and charges you. You have 30 seconds until the guard reaches you." << endl;
	chrono::steady_clock::time_point tend = chrono::steady_clock::now()
										  + chrono::seconds(30);
	while (chrono::steady_clock::now() < tend)
	{
		do
		{
			getline(cin, input);
			if (input == "attack guard")
			{

			}
			if (input == "examine guard")
			{

			}
			notEqual("attack guard", "examine guard", "", "");

			Global::actions();

		} while (input != "examine guard" && input != "attack guard");
	}
}

int main()
{
	cout << "Press enter to continue" << endl;
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

	cout << "Please run this game in fullscreen for an optimal experience" << endl;
	getline(cin, input);

	if (system("CLS")) system("clear");

	cout << " ___       __   _______   ___       ________  ________  _____ ______   _______        _________  ________       ___  ___       ___       ___  ________  ________  ___  ___  ___  ______   ____" << endl;
	cout << "|\\  \\     |\\  \\|\\  ___ \\ |\\  \\     |\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\      |\\___   ___|\\   __  \\     |\\  \\|\\  \\     |\\  \\     |\\  \\|\\   __  \\|\\   __  \\|\\  \\|\\  \\|\\  \\|\\   _ \\  \\\\  \\ " << endl;
	cout << "\\ \\  \\    \\ \\  \\ \\   __/|\\ \\  \\    \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|     \\|___ \\  \\_\\ \\  \\|\\  \\    \\ \\  \\ \\  \\    \\ \\  \\    \\ \\  \\ \\  \\|\\ /\\ \\  \\|\\  \\ \\  \\ \\  \\\\\\  \\ \\  \\\\ \\__\\\\  \\" << endl;
	cout << " \\ \\  \\  __\\ \\  \\ \\  \\_|/_\\ \\  \\    \\ \\  \\    \\ \\  \\\\\\  \\ \\  \\\\|__| \\  \\ \\  \\_|/__        \\ \\  \\ \\ \\  \\\\\\  \\    \\ \\  \\ \\  \\    \\ \\  \\    \\ \\  \\ \\   __  \\ \\   _  _\\ \\  \\ \\  \\\\\\  \\ \\  \\\\|__| \\  \\" << endl;
	cout << "  \\ \\  \\|\\__\\_\\  \\ \\  \\_|\\ \\ \\  \\____\\ \\  \\____\\ \\  \\\\\\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\        \\ \\  \\ \\ \\  \\\\\\  \\    \\ \\  \\ \\  \\____\\ \\  \\____\\ \\  \\ \\  \\|\\  \\ \\  \\\\  \\\\ \\  \\ \\  \\\\\\  \\ \\  \\    \\ \\  \\" << endl;
	cout << "   \\ \\____________\\ \\_______\\ \\_______\\ \\_______\\ \\_______\\ \\__\\    \\ \\__\\ \\_______\\        \\ \\__\\ \\ \\_______\\    \\ \\__\\ \\_______\\ \\_______\\ \\__\\ \\_______\\ \\__\\\\ _\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\" << endl;
	cout << "    \\|____________|\\|_______|\\|_______|\\|_______|\\|_______|\\|__|     \\|__|\\|_______|         \\|__|  \\|_______|     \\|__|\\|_______|\\|_______|\\|__|\\|_______|\\|__|\\|__|\\|__|\\|_______|\\|__|     \\|__|" << endl;

	cout << endl;
	cout << "Welcome to Illibrium" << endl;
	getline(cin, input);

	cout << " You are in the year 2070, an evil organization is plotting to take over the world and you must stop them. \n(enter)" << endl;
	getline(cin, input);
	// To skip to open package function for testing
	if (input == "sk") 
	{
		House::openPackage();
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
	notEqual("", "", "", "");

} while (input != "" && input != "" && input != "" && input != "");
*/
