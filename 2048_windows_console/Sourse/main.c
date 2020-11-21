#include <stdio.h>
#include "user.h"



int main()
{
	STU_T user[USER_NUM_MAX]={{1001,"admin","123456"}};
	loadUser(user);
	int i=0,j=0;
	while(1)
	{
		j=option_choose();
		switch(j)
		{
		case 0:
			while(1)
			{
				i=regist_user(user);
				if (i==KEY_ENTER)
					continue;
				else
					break;
			}
			break;
		case 1:
			login_game(user);
			break;
		case 2:
			gotoxy(30,15);
			exit(0);
			break;
		default:
			break;
		}
	}
}

