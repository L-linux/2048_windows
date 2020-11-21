
#include "gotoxy.h"

void gotoxy(int x, int y) 
{
	 HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	 COORD coord = {x, y};
	 
	 SetConsoleCursorPosition(hOut, coord); 
} 
