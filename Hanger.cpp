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

void Hanger::entry()
{
	system("cls");
	end();

	print_slow(" Hanger Entry", 30);

	print_slow_15(" You walk down the corridor and come to the end. There is a doorway which you walk through into the shipping bay. It is massive.");
	print_slow_15(" The ceiling is about 100 metres high and you see many workers preparing ships for takeoff and doing maintenance.");
	print_slow_15(" There are four landing pads which each contain a ship.");
	print_slow_15(" The first ship has the least health of the bunch but has the most speed. It is blue with white highlights.");
	print_slow_15(" The second ship has the most attack power out of the bunch but the least defense. It is black with golden highlights.");
	print_slow_15(" The third ship has the most defense but least attack power. It is green with black highlights.");
	print_slow_15(" The fourth ship has the most health but least speed. It is silver and has black highlights.");
	end();

	getline(cin, input);
	do
	{



	} while (input != "");
}

