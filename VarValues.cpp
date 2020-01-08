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

int GuardEasy::health = 11;
int GuardEasy::damage = 10;
int GuardEasy::defense = 5;

int Player::speed = 100;
int Player::damage = 5;
int Player::defense = 5;
int Player::health = 20;

int GuardImpossible::speed = 100000;
int GuardImpossible::damage = 100000;
int GuardImpossible::defense = 100000;
int GuardImpossible::health = 100000;