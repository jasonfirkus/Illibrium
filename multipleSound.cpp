#include <cstdlib>
#include <string>
#include <iostream>
#include <chrono>
#include <Windows.h>
#include <time.h>
#include <thread>
#include <Mmsystem.h>
#include <mciapi.h>
using namespace std;

#pragma comment(lib, "Winmm.lib")

int main()
{
	mciSendString(TEXT("open \"nyan.mp3\" type mpegvideo alias nyanAudio"), NULL, 0, NULL);
	mciSendString(TEXT("open \"explode.mp3\" type mpegvideo alias explode"), NULL, 0, NULL);
	mciSendString(TEXT("play nyanAudio"), NULL, 0, NULL);
	mciSendString(TEXT("play explode repeat"), NULL, 0, NULL);
	
	cin.get();
}

