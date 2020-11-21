#include"get_ikey.h"


int get_ikey()
{
	int ikey;
	ikey = _getch();

		if(ikey == 224)
		{
			ikey= _getch();
			switch(ikey)
			{
			case KEY_UP:
					return 72;
					break;
			case KEY_DOWN:
				    return 80;
					break;
			case KEY_LEFT:
				    return 75;
					break;
			case KEY_RIGHT:
					return 77;
					break;
			default:
				break;
			}
		}
		if (ikey==27)
		{
			return 27;
		}
		if (ikey==13)
		{
			return 13;
		}
		return 0;
}
