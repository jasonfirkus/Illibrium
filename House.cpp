#include "precompiled.h"
#include "declarations.h"
using namespace std;

void House::livingRoom()
{
	print_slow(" Living Room. \n  You are in the middle of the living room, to the east is a floating couch.", 15);
	print_slow(" To the north is the dining room", 15);
	print_slow(" To the south is the backyard of the house", 15);
	end(); cout << ">>"; getline(cin, input);

	House::action();
}

void House::openPackage()
{
	cout << " You open the package and find a black disc the size of a hockey puck and a note. It contains the first part of what seems to be a password." << endl;

	House::packActions();

	while (input != "s")
	{
		end(); cout << ">>"; getline(cin, input);
		if (input == "s")
		{
			House::livingRoom();
		}
		if (input == "n" && input == "w" && input == "e")
		{
			cout << "That is a wall" << endl;
		}
		Global::actions();

		not_equal("s", "n", "w", "e");
	}
}

void House::backstory()
{
	//This is explaining the three password segments and the Quantum order from the black disc

	end();

	print_slow_15(" A blue holographic figure appears out of the disc and speaks to you. It says 'included in this package is a note that contains the key to saving world from the Quantum Order.");

	print_slow_15(" The Quantum Order wants to gain absolute control of the world through the use of qauntum computers.");

	print_slow_15(" They will be able to see everyone's information and will keep a constant watch over the entire world. Nobody will be free from their eyes.");

	print_slow_15(" The only way to stop them is to use the password in the absolute point terminal which will cause a chain reaction that will destroy all ");

	print_slow_15(" quantum computers around the world. The password has been split into three segments.");

	print_slow_15(" The note included in this package has the first segment.");

	print_slow_15(" You must find the other two segments and free humanity from the Quantum Order.");

	print_slow_no_space(" Help us ", 15);
	print_slow_no_space(name, 15);
	print_slow_no_space(" you are our only hope. (not stolen shamelessly from Star Wars btw)", 15);
}

void House::packActions()
{
	do
	{
		end(); cout << ">>"; getline(cin, input);
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
	} while (input != "s");
}

void House::dineRoomHouse()
{
	srand(time(0));
	int rands = ((rand() % 4) + 1);
	print_slow_15(" Dining room.\n You go to the dining table and see a package");
	print_slow_no_space(" You see ", 30);
	if (rands <= 2)
	{
		print_slow_no_space("your golden brown puppy", 30);
	}
	if (rands > 2)
	{
		print_slow_no_space(" a golden brown puppy", 30);
	}
	print_slow_15(" sitting next to the table. This puppy's liver has special healing properties and will heal you if eaten.");

	do
	{
		end(); cout << ">>"; getline(cin, input);
		if (input == "open package")
		{
			House::openPackage();
		}
		if (input == "s")
		{
			House::livingRoom();
		}
		if (input == "attack puppy")
		{
			print("YOU ATTACKED THE INNOCENT CUTE LITTLE puppy, HOW DARE YOU.");
			P_ "You kill the puppy and it's liver falls onto the ground" T_

		}
		if (input == "n" && input == "w" && input == "e")
		{
			cout << "That is a wall" << endl;
		}
		not_equal("open package", "attack puppy", "s", "");

	} while (input != "s");
}

void House::killPuppy()
{
	while (input != "s")
	{
		getline(cin, input);
		if (input == "take liver")
		{
			invPlayer[10] = "liver";
		}
	}
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
