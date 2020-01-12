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
string input;
int i;
bool _time;
void Crusher();
int main() {
	getline(cin, input);
	if (input == "north") {
		Crusher();
	}
}

void foo()
{
	do {
		cout << endl;
		getline(cin, input);
		if (input == "solve") {
			cout << "you did it\n";
			_time = true;
			exit(0);
		}
		if (input == "time") {
			cout << i << endl;
		}
	} while (input != "solve");
}

void bar(int x)
{
	for (i = 60; i > 0; i--) {
		if (_time == true) {
			exit;
		}
		Sleep(1000);
		cout << "\b\b" << i;
		if (_time == true) {
			exit;
		}
	}
	cout << "ypu died\n";
	exit(0);

}

void Crusher()
{
	cout << "the door slams behind you and the walls start slowly moving townard each other\n";
	thread first(foo);     // spawn new thread that calls foo()
	thread second(bar, 0);  // spawn new thread that calls bar(0)
	// synchronize threads:
	first.join();                // pauses until first finishes
	second.join();               // pauses until second finishes
}






/*
int main() {
	auto starttime = time(NULL);
	test();
	
	while (input != "solve" && time(NULL) < (starttime + _time)) {
		cin >> input;
		

		if (time(NULL) == (starttime + _time)) {
			cout << "out of time\n";
			exit;
		}
		
		if (input == "solve" && time(NULL) < (starttime + _time)) {
			cout << "you did it\n";
			exit;
		}
		if (input == "time" && time(NULL) < (starttime + _time)) {
			cout << "you have: " << (_time - (time(NULL) - starttime)) << " seconds\n";
		}
		
	}
	cout << "df";
}

















class Room {
public:
	void Actions(Room anRoom);
	void NorthRoom(Room aRoom);

};
Room bob();
Room start();



void Room::NorthRoom(Room aRoom) {
	aRoom;
}

void Room::Actions(Room anRoom) {
	cout << "actions\n";
	cin.ignore(100);
	input = "";
	getline(cin, input);
	if (input == "north") {
		NorthRoom(anRoom);
	}
}

void Actions(Room Room) {
	Room.Actions(Room);
}

#pragma warning(default:4716)d
Room bob() {
	Room bob;
	bob.NorthRoom(start());
	Actions(bob);
}

Room start() {
	Room start;
	cout << "start\n";
	start.NorthRoom(bob());
	Actions(start);
	
}
int main() {
	start();
}
*/
