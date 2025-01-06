#define _CRT_SECURE_NO_WARNINGS
#include"Game.hpp"
#include<Windows.h>

int main()
{
	system("chcp 437>nul");
	srand((unsigned)time(NULL));
	//set_console_param();
	Game g;
	g.play();
	return 0;
}