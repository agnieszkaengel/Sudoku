#include <Windows.h>

void gotoxy(int x, int y)
{
	COORD cursorposition;
	cursorposition.X = x;
	cursorposition.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorposition);
}

