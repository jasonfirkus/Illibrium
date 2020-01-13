#include "precompiled.h"
#include "declarations.h"
using namespace std;

bool timerDone = false;
bool stop = false;
bool keyDPressed = false;
bool keyOPressed = false;
bool keyD2Pressed = false;
bool keyGPressed = false;
bool keyEPressed = false;

void Guard::airlock()
{
	print_slow_15(" Airlock.");
	print_slow_15(" The airlock is a small white room. There are a couple space suits and an array of tools. ");
	print_slow_15(" To the south is a corridor leaing to a bigger building");
	print_slow_15(" To the east is another corridor which goes to a small building.");

	//If you've already taken a suit then this says "You already took a space suit"
	if (airlockInv != " Space Suit")
	{
		cout << " You already took a space suit" << endl;
	}
	do {

		end(); cout << ">>"; getline(cin, input);
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
		else
		{
			cout << "You already picked up a space suit" << endl;
		}
		Global::actions();

		not_equal("s", "e", "w", "pick up space suit");

	} while (input != "s" && input != "e" && input != "w");
}

void Guard::guardFight()
{
	end();

	print_slow(" Main Hub.", 15);
	print_slow(" The corridor opens up into a massive rooom. The walls are white with blue accents. The ceiling is about 7 metres high.", 15);
	print_slow(" To the south is another corridor leading to the shipping bay. Blocking the corridor is a guard who looks to be holding a gun.", 15);
	print_slow(" To the east is another corridor leading to a different bay.", 15);

	end();
	system("pause");
	do
	{
		end(); cout << ">>"; getline(cin, input);
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
		if (input == "s")
		{
			print("You walk towards the guard who becomes very confused and tells you to stop."); 
			P_ "You ignore him and continue walking straight into him. The guard raises his gun and fires at you" T_

			Guard::walkedIntoGuard();
		}
		Global::actions();

		not_equal("n", "attack guard", "examine guard", "e");

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
	print_slow("Corridor.", 30);
	print_slow("You walk down the corridor and at the end you find another corridor with a door at the end. In front of the door is a guard.", 15);

	do
	{
		end(); cout << ">>"; getline(cin, input);
		if (input == "examine guard")
		{
			Guard::examineImpossible();
		}
		if (input == "attack guard")
		{
			Guard::attackImpossible();
		}
		if (input == "w")
		{
			cout << "You try to run away but the guard has 1 billion speed and easily catches up with you." << endl;
			Sleep(500);

			cout << "The guard runs up and eats you. You died." << endl;
			Global::gameOver();
		}
		Global::actions();

		not_equal("examine guard", "attack guard", "w", "");
	} while (input != "examine guard" && input != "w" && input != "attack guard");
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

	end(); cout << ">>"; getline(cin, input);
	Guard::corridorImpossible();
}

void Guard::attackImpossible()
{
	cout << "Choose a weapon to attack the guard with" << endl;
	do
	{
		end(); cout << ">>"; getline(cin, input);
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
		end(); cout << ">>"; getline(cin, input);
		if (input == "gun")
		{
			end();
			
			int finalDamage = player.damage + gunBonus + Global::extraDamage(); - guard.easyReturnDefense();
			guard.minusVariables("health", finalDamage);

			cout << "You attack the guard with your gun. It does " << finalDamage << " damage" << endl;

			cout << "The guard has ";
			guard.showVariables("health");
			cout << " health left" << endl;

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
		}
		if (input == "fist")
		{
			end();

			int randomes = ((rand() % 5) + 1);
			int finalDamageFist = player.damage + randomes - guard.easyReturnDefense();
			guard.minusVariables("health", finalDamageFist);

			cout << "You fisted the guard with your fist. It does " << finalDamageFist << " damage." << endl;

			cout << "The guard has ";
			guard.showVariables("health");
			cout << " health left" << endl;

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
			Guard::guardAttacks();
		}
		Global::actions();

		not_equal("gun", "fist", "", "");

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


		//// Game Logic ////
		LONGLONG elapsedTime = currentTime.QuadPart - initialTime.QuadPart;
		LONGLONG currentNumber_100ns = countdownStartTime - elapsedTime;

		if (currentNumber_100ns <= 0)
		{
			system("cls");

			cout << "You took too long, the guard's shot hit you." << endl;
			Guard::failDodge();

			timerDone = true;
			break;
		}
		if (keyDPressed == true && keyOPressed == true && keyD2Pressed == true && keyGPressed == true && keyEPressed == true)
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
				player.health = 30;

				break;
			}
			else
			{
				cout << "You failed to dodge the guard's shot" << endl;
				Guard::failDodge();

				break;
			}
		}
		LONGLONG currentNumber_s = currentNumber_100ns / 10000000 + 1;
		system("cls");

		cout << "You have " << currentNumber_s << " seconds to dodge the guard's shot" << endl;
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

	Hanger::landingBay();
}

void Guard::failDodge()
{
	GuardEasy guard;
	Player player;

	int finalDamageGuard = guard.easyReturnDamage() - player.defense;
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
}

void Guard::damageGuard()
{
	Player player;
	GuardEasy guard;

	int random = ((rand() % 5) + 1);
	int finalDamage = player.damage + gunBonus + random - guard.easyReturnDefense();

	system("pause");
	system("cls");
	do
	{
		cout << "The guard has ";
		guard.showVariables("health");
		cout << " health left" << endl;

		end(); cout << ">>"; getline(cin, input);
		if (input == "attack guard")
		{
			guard.minusVariables("health", finalDamage);
		}
		Global::actions();

		not_equal("attack guard", "", "", "");

	} while (input != "attack guard");
	end();

	cout << "You attack the guard with your gun. It does " << finalDamage << " damage" << endl;
	end();
}

void Guard::walkedIntoGuard()
{
	GuardEasy guard;
	Player player;

	int finalDamageGuard = guard.easyReturnDamage() - player.defense;
	player.health = player.health - finalDamageGuard;

	end();
	cout << "The guard's shot hits you in the chest. It does " << finalDamageGuard << " damage." << endl;

	end();
	Guard::damageGuard();

	print("The guard attacks back. He shoots at you");
	Guard::guardAttacks();
}
