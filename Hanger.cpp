#include "precompiled.h"
#include "declarations.h"
using namespace std;

bool keyA_Pressed = false;
bool keyT_Pressed = false;
bool keyT2_Pressed = false;
bool keyA2_Pressed = false;
bool keyC_Pressed = false;
bool keyK_Pressed = false;
bool keySpace_Pressed = false;
bool keyG_Pressed = false;
bool keyU_Pressed = false;
bool keyA3_Pressed = false;
bool keyR_Pressed = false;
bool keyD_Pressed = false;

bool timerHangerDone = false;

int finalDamageGuard = GuardShip::easyReturnDamage() - Player::defense + Global::extraDamage();

void Hanger::landingBay()
{
	system("cls");
	SP_

	print_slow(" Landing Bay", 30);
	print_slow_15(" You walk down the corridor and come to the end. There is a doorway which you walk through into the shipping bay. It is massive.");
	print_slow_15(" The ceiling is about 100 metres high and you see many workers preparing ships for takeoff and doing maintenance.");
	print_slow_15(" There are four landing pads which each contain a ship. Each one has a guard protecting it. But you see some boxes that allow might allow you to sneak past then guard unoticed.");
	print_slow_15(" Or you can try to outright overpower the guard.");
	SP_
	print_slow_15(" The first ship has the least health of the bunch but has the most speed. It is blue with white highlights.");
	print_slow_15(" The second ship has the most attack power out of the bunch but the least defense. It is black with golden highlights.");
	print_slow_15(" The third ship has  the most defense but least attack power. It is green with black highlights.");
	print_slow_15(" The fourth ship has the most health but least speed. It is silver and has black highlights.");

	SP_
		WAIT
		SP_

		do
		{
			SP_ cout << ">>"; getline(cin, input);
			SP_
			if (input == "get on first ship")
			{
				Hanger::firstShip();
			}
			if (input == "get on second ship")
			{
				Hanger::secondShip();
			}
			if (input == "get on third ship")
			{
				Hanger::thirdShip();
			}
			if (input == "get on fourth ship")
			{
				Hanger::fourthShip();
			}
			if (input == "sneak on first ship")
			{
				Hanger::ifStealthy();
			}
			if (input == "sneak on second ship")
			{
				Hanger::ifStealthy();
			}
			if (input == "sneak on third ship")
			{
				Hanger::ifStealthy();
			}
			if (input == "sneak on fourth ship")
			{
				Hanger::ifStealthy();
			}
			Global::actions();
			if (input != "get on first ship" && input != "get on second ship" && input != "get on third ship" && input != "get on fourth ship"
				&& input != "sneak on first ship" && input != "sneak on second ship" && input != "sneak on third ship" && input != "sneak on fourth ship")
			{
				print("Nani? Doiu imidesu ka?");
			}

		} while (input != "get on first ship" && input != "get on second ship" && input != "get on third ship" && input != "get on fourth ship"
		&& input != "sneak on first ship" && input != "sneak on second ship" && input != "sneak on third ship" && input != "sneak on fourth ship");
}

void Hanger::firstShip()
{
	print("You get closer and spot the guard");
	do
	{
		getline(cin, input);
		if (input == "attack guard")
		{
			Hanger::playerAttacks();
		}
		if (input == "n")
		{
			Hanger::landingBay();
		}
		Global::actions();
		not_equal("n", "attack guard", "adadadadadadwd", "diajdoijawd");
	} while (input != "attack guard" && input != "n");

	Player::health = Player::health - finalDamageGuard;
	cout << "The guard shoots back at you. It does " << finalDamageGuard << " damage" << endl;

	do
	{
		getline(cin, input);
		if (input == "attack guard")
		{
			SP_
			srand(time(NULL));

			int random = ((rand() % 5) + 1);
			int finalDamage = Player::damage + gunBonus + random - GuardShip::easyReturnDefense();
			GuardShip::minusVariables("health", finalDamage);

			cout << "You attack the guard with your gun. It does " << finalDamage << " damage" << endl;
			if (GuardShip::easyReturnHealth > 0)
			{
				print("u kil boi");
				exit(0);
			}
			else
			{
				print("You killed the guard");
				exit(0);
			}
		}
		if (input == "n")
		{
			Hanger::landingBay();
		}
		Global::actions();
		not_equal("n", "attack guard", "adadadadadadwd", "diajdoijawd");
	} while (input != "attack guard" && input != "n");
}

void Hanger::secondShip()
{

}

void Hanger::thirdShip()
{

}

void Hanger::fourthShip()
{

}

void Hanger::ifStealthy()
{
	srand(time(NULL));
	int yesno = ((rand() % 3) + 1);

	string ranOutOfTime = " You didn't attack the guard in time.";
	string pressedButton = " You attack the guard.";
	string options = " '1' to attack the guard";
	string timeDesc = " seconds until the guard reaches you.";

	if (yesno == 1)
	{
		print(" You snuck past the guard!");//////////
	}
	else
	{
		print(" You weren't sneaky enough.\n The guard heard a sound coming from the boxes and he starts walking over to them.");
		SP_
		WAIT
		SP_
		thread one(Timer::hangerGuard);
		while (timerHangerDone != true)
		{
			SHORT keyA = GetKeyState('A');
			SHORT keyT = GetKeyState('T');
			SHORT keyT2 = GetKeyState('T');
			SHORT keyA2 = GetKeyState('A');
			SHORT keyC = GetKeyState('C');
			SHORT keyK = GetKeyState('K');
			SHORT keySpace = GetKeyState(VK_SPACE);
			SHORT keyG = GetKeyState('G');
			SHORT keyU = GetKeyState('U');
			SHORT keyA3 = GetKeyState('A');
			SHORT keyR = GetKeyState('R');
			SHORT keyD = GetKeyState('D');
			if (keyA & 0x8000)
			{
				keyA_Pressed = true;
			}
			if (keyT & 0x8000)
			{
				keyT_Pressed = true;
			}
			if (keyT2 & 0x8000)
			{
				keyT2_Pressed = true;
			}
			if (keyA2 & 0x8000)
			{
				keyA2_Pressed = true;
			}
			if (keyC & 0x8000)
			{
				keyC_Pressed = true;
			}
			if (keyK & 0x8000)
			{
				keyK_Pressed = true;
			}
			if (keySpace & 0x8000)
			{
				keySpace_Pressed = true;
			}
			if (keyG & 0x8000)
			{
				keyG_Pressed = true;
			}
			if (keyU & 0x8000)
			{
				keyU_Pressed = true;
			}
			if (keyA3 & 0x8000)
			{
				keyA3_Pressed = true;
			}
			if (keyR & 0x8000)
			{
				keyR_Pressed = true;
			}
			if (keyD & 0x8000)
			{
				keyD_Pressed = true;
			}
		}
		one.join();
	}
}

void Hanger::playerAttacks()
{
	SP_
	srand(time(NULL));

	int random = ((rand() % 5) + 1);
	int finalDamage = Player::damage + gunBonus + random - GuardShip::easyReturnDefense();
	GuardShip::minusVariables("health", finalDamage);

	cout << "You attack the guard with your gun. It does " << finalDamage << " damage" << endl;

	cout << "The guard has ";
	GuardShip::showVariables("health");
	cout << " health left" << endl;


}

void Timer::hangerGuard()
{
	ULARGE_INTEGER initialTime;
	ULARGE_INTEGER currentTime;
	FILETIME ft;
	GetSystemTimeAsFileTime(&ft);
	initialTime.LowPart = ft.dwLowDateTime;
	initialTime.HighPart = ft.dwHighDateTime;
	LONGLONG countdownStartTime = 50000000; 
	LONGLONG displayedNumber = 6; 

	while (true)
	{
		GetSystemTimeAsFileTime(&ft); 
		currentTime.LowPart = ft.dwLowDateTime;
		currentTime.HighPart = ft.dwHighDateTime;

		//// Game Logic ////
		LONGLONG elapsedTime = currentTime.QuadPart - initialTime.QuadPart;
		LONGLONG currentNumber_100ns = countdownStartTime - elapsedTime;

		if (currentNumber_100ns <= 0)
		{
			CLS

			P_ "You didn't attack the guard in time." T_

			timerHangerDone = true;

			Player::health = Player::health - finalDamageGuard;
			SP_
			cout << " The guard walks around the boxes and shoots you in the back. It does " << finalDamageGuard << " damage." << endl;

			break;
		}
		if (keyA_Pressed == true && keyT_Pressed == true && keyT2_Pressed == true && keyA2_Pressed == true
			&& keyC_Pressed == true && keyK_Pressed == true && keySpace_Pressed == true && keyG_Pressed == true
			&& keyU_Pressed == true && keyA3_Pressed == true && keyR_Pressed == true && keyD_Pressed == true)
		{
			CLS
			P_ "You jump out of cover and blast the guard at point-blank range." T_
			SP_

			
		}
		LONGLONG currentNumber_s = currentNumber_100ns / 10000000 + 1;
		CLS
			cout << "You have " << currentNumber_s << " seconds until the guard reaches you." << endl;
		displayedNumber = currentNumber_s;

		if (keyA_Pressed == true)
		{ //You cannnot fix the multiple typing do to the screen refreshing maybe if s
			cout << "a";
		}
		if (keyT_Pressed == true)
		{
			cout << "t";
		}
		if (keyT2_Pressed == true)
		{
			cout << "t";
		}
		if (keyA2_Pressed == true)
		{
			cout << "a";
		}
		if (keyC_Pressed == true)
		{
			cout << "c";
		}
		if (keyK_Pressed == true)
		{
			cout << "k";
		}
		if (keySpace_Pressed == true)
		{
			cout << " ";
		}
		if (keyG_Pressed == true)
		{
			cout << "g";
		}
		if (keyU_Pressed == true)
		{
			cout << "u";
		}
		if (keyA3_Pressed == true)
		{
			cout << "a";
		}
		if (keyR_Pressed == true)
		{
			cout << "r";

		}
		if (keyD_Pressed == true)
		{
			cout << "d";

		}
		Sleep(70);
	}
	SP_
		system("pause");

	//Put this in the function that you are calling the timer function
	/*thread one(Timer::hangerGuard);
	while (timerDone != true)
	{
		SHORT keyA = GetKeyState('A');
		SHORT keyT = GetKeyState('T');
		SHORT keyT2 = GetKeyState('T');
		SHORT keyA2 = GetKeyState('A');
		SHORT keyC = GetKeyState('C');
		SHORT keyK = GetKeyState('K');
		SHORT keySpace = GetKeyState(VK_SPACE);
		SHORT keyG = GetKeyState('G');
		SHORT keyU = GetKeyState('U');
		SHORT keyA3 = GetKeyState('A');
		SHORT keyR = GetKeyState('R');
		SHORT keyD = GetKeyState('D');
		if (keyA & 0x8000)
		{
			keyDPressed = true;
		}
		if (keyT & 0x8000)
		{
			keyOPressed = true;
		}
		if (keyT2 & 0x8000)
		{
			keyD2Pressed = true;
		}
		if (keyA2 & 0x8000)
		{
			keyGPressed = true;
		}
		if (keyC & 0x8000)
		{
			keyEPressed = true;
		}
		if (keyK & 0x8000)
		{
			keyEPressed = true;
		}
		if (keySpace & 0x8000)
		{
			keyEPressed = true;
		}
		if (keyG & 0x8000)
		{
			keyEPressed = true;
		}
		if (keyU & 0x8000)
		{
			keyEPressed = true;
		}
		if (keyA3 & 0x8000)
		{
			keyEPressed = true;
		}
		if (keyR & 0x8000)
		{
			keyEPressed = true;
		}
		if (keyD & 0x8000)
		{
			keyEPressed = true;
		}
	}
	one.join();*/
}

void refresh()
{
	while (timerHangerDone != true)
	{
		CLS
			Sleep(70);
	}
}

void seconds()
{
	ULARGE_INTEGER initialTime;
	ULARGE_INTEGER currentTime;
	FILETIME ft;
	GetSystemTimeAsFileTime(&ft);
	initialTime.LowPart = ft.dwLowDateTime;
	initialTime.HighPart = ft.dwHighDateTime;
	LONGLONG countdownStartTime = 100000000; // 100 Nano seconds
	LONGLONG displayedNumber = 11; // Prevent 31 to be displayed

	GetSystemTimeAsFileTime(&ft); // 100 nano seconds
	currentTime.LowPart = ft.dwLowDateTime;
	currentTime.HighPart = ft.dwHighDateTime;

	//// Game Logic ////
	LONGLONG elapsedTime = currentTime.QuadPart - initialTime.QuadPart;
	LONGLONG currentNumber_100ns = countdownStartTime - elapsedTime;
	LONGLONG currentNumber_s = currentNumber_100ns / 10000000 + 1;

	cout << "You have " << currentNumber_s << " seconds until the guard reaches you." << endl;
	displayedNumber = currentNumber_s;
	Sleep(70);
}
