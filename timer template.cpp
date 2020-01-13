#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <map>
#include <conio.h>
using namespace std;

bool timerDone = false;
bool stop = false;
bool keyDPressed = false;
bool keyOPressed = false;
bool keyD2Pressed = false;
bool keyGPressed = false;
bool keyEPressed = false;

void timer()
{
	ULARGE_INTEGER initialTime;
	ULARGE_INTEGER currentTime;
	FILETIME ft;
	GetSystemTimeAsFileTime(&ft);
	initialTime.LowPart = ft.dwLowDateTime;
	initialTime.HighPart = ft.dwHighDateTime;
	LONGLONG countdownStartTime = 100000000; // Add 6 zeroes to however long you want the timer to run
	LONGLONG displayedNumber = 11; //This is the the number above +1 without the zeroes

	while (true)
	{
		GetSystemTimeAsFileTime(&ft);
		currentTime.LowPart = ft.dwLowDateTime;
		currentTime.HighPart = ft.dwHighDateTime;
		LONGLONG elapsedTime = currentTime.QuadPart - initialTime.QuadPart;
		LONGLONG currentNumber_100ns = countdownStartTime - elapsedTime;

		if (currentNumber_100ns <= 0) //If time runs out
		{
			system("cls");

			cout << "You ran out of time" << endl;

			timerDone = true;
			break;
		}
		if (keyDPressed == true && keyOPressed == true && keyD2Pressed == true && keyGPressed == true && keyEPressed == true) //If user types dodge
		{
			system("cls");

			cout << "You dodged the shot" << endl;
			break;
		}


		LONGLONG currentNumber_s = currentNumber_100ns / 10000000 + 1;
		system("cls");

		cout << "You have " << currentNumber_s << " seconds" << endl;
		displayedNumber = currentNumber_s;
		if (keyDPressed == true) //For printing the letter the user typed
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
	cout << endl;
	cout << "Done timer" << endl;

}

int main()
{
	thread one(timer);  //Start separate thread with function timer
	while (timerDone != true)
	{
		SHORT keyD = GetKeyState('D');
		SHORT keyO = GetKeyState('O');
		SHORT keyD2 = GetKeyState('D');
		SHORT keyG = GetKeyState('G');
		SHORT keyE = GetKeyState('E');
		//To see if the user types dodge
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
	exit(0);
}
