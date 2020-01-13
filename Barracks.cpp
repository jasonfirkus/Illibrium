#include "precompiled.h"
#include "declarations.h"
using namespace std;

void Barracks::oActions()
{
	do {
		end(); cout << ">>"; getline(cin, input);
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

		not_equal("n", "s", "e", "w");

	} while (input != "s" && input != "w" && input != "e" && input != "n");

}

void Barracks::oHouse()
{
	print_slow_15(" Outside The House.\n You are outside the house, you are standing on a lush green lawn.");

	print_slow_15(" There is a transparent bubble directly in front of you surrounding the perimeter of the house and lawn.");

	print_slow_15(" To the north is the living room inside the house where you started.");

	print_slow_15(" To the east is a white doorway in the bubble which looks to lead to another set of buildings."); //this continues to the main story

	print_slow_15(" To the west is a gray doorway which leads to a single building."); //This is the barracks
	Barracks::oActions();
}

void Barracks::westHall()
{
	print_slow_15(" West Hall\n It is a long glowing hallway. There are flying orbs around you providing light. You see a door at the end of the hallway.");

	print_slow_15(" To continue down the hallway go south.");

	print_slow_15(" To go back go east");

	do {
		end(); cout << ">>"; getline(cin, input);
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

		not_equal("n", "s", "e", "w");

	} while (input != "s" && input != "e");
}

void Barracks::westHall2()
{
	print_slow_15(" End of West Hall.\n You reach the end of the hall.");

	print_slow_15(" To the east there is a door leading into a room which looks to be stocked with guns and weapons.");

	print_slow_15(" To the north is the exit.");
	do {
		end(); cout << ">>"; getline(cin, input);
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

		not_equal("n", "s", "e", "w");

	} while (input != "n" && input != "e");
}

void Barracks::barracks()
{
	print_slow_15(" Barracks.\n You enter inside the room to see rack upon rack of neodynium exodus rifles (gun).");
	print_slow_15(" All of them are locked into the racks but you spot one that isn't.");
	if (barracksinv != "gun")
	{
		cout << " You already took the gun" << endl;
	}
	do {
		end(); cout << ">>"; getline(cin, input);
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
