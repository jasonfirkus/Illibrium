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
string name;
string invPlayer[5] = {};

void global::stats();
void barracks::oActions();
void global::actions();
void house::dineRoomHouse();
void barracks::oHouse();
void global::fullInvPlayer();
void global::no();
void global::help();
void house::openPackage();
void house::livingRoom();
void house::packActions();
void house::action();
void house::backstory();
void barracks::westHall();
void barracks::westHall2();
void barracks::barracks();


void global::no()
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
	cout << " Type 'n' for north" << endl;
	cout << " Type 'e' for east" << endl;
	cout << " Type 's' for south" << endl;
	cout << " Type 'w' for west" << endl;
	cout << " Type 'i' for inventory" << endl;
	cout << " Type 'stats' for your stats" << endl;
	cout << " There are also basic commands you can perform such as 'pick up ____' or 'open ____' 'attack ____' Type help at any time to view these commands" << endl;
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
	cout << " Living Room. \n  You are in the middle of the living room\n To the east is a floating couch." << endl;
	cout << " To the north is the dining room" << endl;
	cout << " To the south is the backyard of the house" << endl;
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
			house::livingRoom();
		}
		if (input == "n" && input == "w" && input == "e")
		{
			cout << "That is a wall" << endl;
		}
		if (input != "s" && input != "n")
		{
			global::no();
		}
	}
}

void house::backstory()
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
			house::backstory();
		}
		if (input != "pick up note" && input != "s" && input != "n" && input != "w" && input != "e" && input != "use disc")
		{
			global::no();
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
			global::no();
		}
	} while (input != "open package" && input != "s");
}

void house::action()
{

	if (input == "s")
	{
		barracks::oHouse();
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
		global::no();
	}
}

void barracks::oActions()
{
	do {
	    getline(cin, input);
		if (input == "s")
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
		}
		if (input == "w")
		{
			barracks::westHall();
		}
		if (input == "e")
		{
			barracks::oHouse();
		}
		if (input == "n")
		{
			house::livingRoom(); //Takes you back to the start
		}
		global::actions();
		if (input != "n" && input != "s" && input != "w" && input != "e" && input != "help" && input != "stats" && input != "i")
		{
			global::no();
		}
    } while (input != "s" && input != "w" && input != "e" && input != "n");
	
}

void barracks::oHouse()
{
	cout << " Outside The House.\n You are outside the house, you are standing on a lush green lawn." << endl;
	Sleep(700);

	cout << " There is a transparent bubble directly in front of you surrounding the perimeter of the house and lawn." << endl;
	Sleep(700);

	cout << " To the north is the living room inside the house where you started." << endl;
	Sleep(700);

	cout << " To the east is a white door in the bubble which looks to lead to another set of buildings." << endl; //this continues to the main story
	Sleep(700);

	cout << " To the west is a gray door which leads to a single building." << endl; //This is the barracks
	barracks::oActions();
}

void barracks::westHall()
{
	cout << "West Hall\n It is a long glowing hallway. There are flying orbs around you providing light. You see a door at the end of the hallway." << endl;

	cout << "To continue down the hallway go south." << endl;

	cout << "To go back go east" << endl;

	do {
		getline(cin, input);
		if (input == "s")
		{
			barracks::westHall2();
		}
		if (input == "w" && input == "n")
		{
			cout << "You run at mach 20 into a molybdenum wall shattering your spleen and die." << endl;
			cout << "  .----------------.  .----------------.  .----------------.  .----------------.   .----------------.  .----------------.  .----------------.  .----------------.  .----------------. " << endl;
			cout << " | .--------------. || .--------------. || .--------------. || .--------------. | | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |" << endl;
			cout << " | |    ______    | || |      __      | || | ____    ____ | || |  _________   | | | |     ____     | || | ____   ____  | || |  _________   | || |  _______     | || |              | |" << endl;
			cout << " | |  .' ___  |   | || |     /  \\     | || ||_   \\  /   _|| || | |_   ___  |  | | | |   .'    `.   | || ||_  _| |_  _| | || | |_   ___  |  | || | |_   __ \\    | || |      _       | |" << endl;
			cout << " | | / .'   \\_|   | || |    / /\\ \\    | || |  |   \\/   |  | || |   | |_  \\_|  | | | |  /  .--.  \\  | || |  \\ \\   / /   | || |   | |_  \\_|  | || |   | |__) |   | || |     | |      | |" << endl;
			cout << " | | | |    ____  | || |   / ____ \\   | || |  | |\\  /| |  | || |   |  _|  _   | | | |  | |    | |  | || |   \\ \\ / /    | || |   |  _|  _   | || |   |  __ /    | || |     | |      | |" << endl;
			cout << " | | \\ `.___]  _| | || | _/ /    \\ \\_ | || | _| |_\\/_| |_ | || |  _| |___/ |  | | | |  \\  `--'  /  | || |    \\ ' /     | || |  _| |___/ |  | || |  _| |  \\ \\_  | || |     | |      | |" << endl;
			cout << " | |  `._____.'   | || ||____|  |____|| || ||_____||_____|| || | |_________|  | | | |   `.____.'   | || |     \\_/      | || | |_________|  | || | |____| |___| | || |     |_|      | |" << endl;
			cout << " | |              | || |              | || |              | || |              | | | |              | || |              | || |              | || |              | || |     (_)      | |" << endl;
			cout << " | '--------------' || '--------------' || '--------------' || '--------------' | | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |" << endl;
			cout << "  '----------------'  '----------------'  '----------------'  '----------------'   '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << endl;

		}
		if (input == "e")
		{
			barracks::oHouse();
		}
		global::actions();
		if (input != "n" && input != "s" && input != "w" && input != "e" && input != "help" && input != "stats" && input != "i")
		{
			global::no();
		}

	} while (input != "s" && input != "e");
}

void barracks::westHall2()
{
	cout << "End of West Hall.\n You reach the end of the hall." << endl;

	cout << "To the east there is a door leading into a room which looks to be stocked with guns and weapons." << endl;

	cout << "To the north is the exit." << endl;
	do {
		getline(cin, input);
		if (input == "n")
		{
			barracks::westHall();
		}
		if (input == "w" && input == "s")
		{
			cout << "You run at mach 20 into a molybdenum wall shattering your spleen and die." << endl;
			cout << "  .----------------.  .----------------.  .----------------.  .----------------.   .----------------.  .----------------.  .----------------.  .----------------.  .----------------. " << endl;
			cout << " | .--------------. || .--------------. || .--------------. || .--------------. | | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |" << endl;
			cout << " | |    ______    | || |      __      | || | ____    ____ | || |  _________   | | | |     ____     | || | ____   ____  | || |  _________   | || |  _______     | || |              | |" << endl;
			cout << " | |  .' ___  |   | || |     /  \\     | || ||_   \\  /   _|| || | |_   ___  |  | | | |   .'    `.   | || ||_  _| |_  _| | || | |_   ___  |  | || | |_   __ \\    | || |      _       | |" << endl;
			cout << " | | / .'   \\_|   | || |    / /\\ \\    | || |  |   \\/   |  | || |   | |_  \\_|  | | | |  /  .--.  \\  | || |  \\ \\   / /   | || |   | |_  \\_|  | || |   | |__) |   | || |     | |      | |" << endl;
			cout << " | | | |    ____  | || |   / ____ \\   | || |  | |\\  /| |  | || |   |  _|  _   | | | |  | |    | |  | || |   \\ \\ / /    | || |   |  _|  _   | || |   |  __ /    | || |     | |      | |" << endl;
			cout << " | | \\ `.___]  _| | || | _/ /    \\ \\_ | || | _| |_\\/_| |_ | || |  _| |___/ |  | | | |  \\  `--'  /  | || |    \\ ' /     | || |  _| |___/ |  | || |  _| |  \\ \\_  | || |     | |      | |" << endl;
			cout << " | |  `._____.'   | || ||____|  |____|| || ||_____||_____|| || | |_________|  | | | |   `.____.'   | || |     \\_/      | || | |_________|  | || | |____| |___| | || |     |_|      | |" << endl;
			cout << " | |              | || |              | || |              | || |              | | | |              | || |              | || |              | || |              | || |     (_)      | |" << endl;
			cout << " | '--------------' || '--------------' || '--------------' || '--------------' | | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |" << endl;
			cout << "  '----------------'  '----------------'  '----------------'  '----------------'   '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << endl;

		}
		if (input == "e")
		{
			barracks::barracks();
		}
		global::actions();
		if (input != "n" && input != "s" && input != "w" && input != "e" && input != "help" && input != "stats" && input != "i")
		{
			global::no();
		}
	} while (input != "n" && input != "e");
}

void barracks::barracks()
{
	cout << "Barracks.\n You enter inside the room to see rack upon rack of neodynium exodus rifles (gun)." << endl;
	cout << "Most of them are locked into the rack but you spot a few that aren't." << endl;
	if (toTest = "test")
	{
	do {
		getline(cin, input);
		if (input == "pick up gun")
		{
			string toTest = "test";
			string gun = "neodynium exodus rifle";
			invPlayer[2] = gun;
			cout << "picked up gun" << endl;
		}
		if (input != "pick up gun" && input != "w")
		{
			cout << "That is not something you can do" << endl;
		}
		if (input == "w")
		{
			barracks::westHall2();
		}
	} while (input != "w")
	}
	
}

int main()
{
	cout << "Press enter to continue" << endl;
	getline(cin, input);

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
			barracks::oActions();
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
			global::no();
		}
	}

	return 0;
}
