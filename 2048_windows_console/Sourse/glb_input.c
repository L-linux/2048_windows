#include "glb_input.h"

int glb_putString(char acStr[], int iMaxLen, int iPutType, int isPlaintext)
{
	int ch, i = 0, flag = 0;
	while (1)
	{
		ch = _getch();
		if (ch == KEY_BACKSPACE && i > 0)
		{
			printf("\b \b");
			i--;
			acStr[i] = 0;
			continue;
		}
		if (ch == KEY_ENTER && (isPlaintext == 1 || i == iMaxLen) && i > 0)
		{
			return 13;
		}
		if (ch == KEY_ESC)
		{
			return 27;
		}
		if (i < iMaxLen)
		{
			switch (iPutType)
			{
			case 1:
				if (ch >= '0' && ch <= '9')
				{
					if (isPlaintext == 1)
					{
						putchar(ch);
						acStr[i++] = ch;
						acStr[i] = 0;
					}
					else
					{
						putchar('*');
						acStr[i++] = ch;
						acStr[i] = 0;
					}
				}
				break;
			case 2:
				if (ch >= 'A' && ch <= 'z')
				{
					if (isPlaintext == 1)
					{
						putchar(ch);
						acStr[i++] = ch;
						acStr[i] = 0;

					}
					else
					{
						putchar('*');
						acStr[i++] = ch;
						acStr[i] = 0;
					}
				}
				break;
			case 3:
				if (ch >= 'A' && ch <= 'z' || ch >= '0' && ch <= '9')
				{
					if (isPlaintext == 1)
					{
						putchar(ch);
						acStr[i++] = ch;
						acStr[i] = 0;
					}
					else
					{
						putchar('*');
						acStr[i++] = ch;
						acStr[i] = 0;
					}
				}
				break;
			default:
				break;
			}
		}
	}
	return 0;
}
