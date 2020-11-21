#include "user.h"


void print(STU_T user[])
{
	int i=0;
	while(user[i].id!=0)
	{
		printf("%d\t%s\t%s\n",user[i].id,user[i].name,user[i].pwd);
		i++;
	}	
}
void login_game(STU_T user[])
{
	int i=0,j=0,k=0,flag=0;
	char str[20]={0};
	char str1[20]={0};
	while(1)
	{
		i=0;
		inter_face();
		gotoxy(34,7);
		flag=glb_putString(str,9,3,1);
		if (flag==KEY_ESC)
		{
			break;
		}
		gotoxy(34,10);
		flag=glb_putString(str1,6,1,0);
		if (flag==KEY_ESC)
		{
			break;
		}
		while (user[i].id!=0)
		{
			j=strcmp(str,user[i].name)==0&&strcmp(str1,user[i].pwd)==0;
			if (j)
			{
				break ;
			}
			i++;
		}
		if(j==1)
		{
			gotoxy(20,12);
			printf("登录成功 ");
			printf(".");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			game();
			continue;
		}
		else
		{
			gotoxy(20,12);
			printf("账户名或密码错误,按回车键重新输入");
			while(flag=get_ikey())
			{
				if (flag==KEY_ESC)
				{
					return;
				}
				if (flag==KEY_ENTER)
				{
					break;
				}
			}
		}	
	}
}

int saveUser(STU_T *user) {
	FILE* user_file;
	int ret = fopen_s(&user_file,USERINFO_FILE, "ab+");
	if (user_file == NULL)
	{
		gotoxy(8, 21);
		perror("open file failed\n");
		return FALSE;
	}
	int i = 0;
	int write_size = fwrite((void *)user,sizeof(STU_T),1,user_file);
	fclose(user_file);
	return TRUE;
}

int loadUser(STU_T *user)
{
	FILE* user_file;
	int ret = fopen_s(&user_file, USERINFO_FILE, "rb+");
	if (user_file == NULL)
	{
		gotoxy(8, 21);
		perror("open file failed\n");
		return FALSE;
	}
	STU_T tmp_user = { 0 };
	int i = 0;
	while (i < USER_NUM_MAX) {
		if (user[i].id != 0) {
			++i;
			continue;
		}
		int read_size = fread_s(&tmp_user, sizeof(tmp_user), sizeof(tmp_user), 1, user_file);
		if (read_size == 0)
		{
			break;
		}
		user[i] = tmp_user;
		memset(&tmp_user, 0, sizeof(tmp_user));
		++i;
	}
	fclose(user_file);
	return TRUE;
}

int showUser(STU_T* user)
{

	return 0;
}

int regist_user(STU_T user[])
{
	int i=0,j=0,k=0,count=0;
	char name[10]={0};
    char pwd1[10]={0};
    char pwd2[10]={0};
	regist_face();
	gotoxy(35,6);
	while(i < USER_NUM_MAX)
	{
		if(user[i].id==0)
		{
			printf("%d",user[--i].id+1);
			i++;
			break;
		}
		i++;
	}
	while(i < USER_NUM_MAX)
	{
		gotoxy(45,9);
		printf("输入1~9个字母或数字且不能为空");
		gotoxy(35,9);	
		k=glb_putString(name,9,3,1);
		if (k==KEY_ESC)
		{
			return 27;
		}
		count=0;
		while (user[count].id!=0)
		{
			if(strcmp(name,user[count].name)==0)
			{
				gotoxy(45,9);	
				printf("                             ");
				gotoxy(45,9);
				printf("账户名已存在!请重新输入");
				Sleep(1000);
				gotoxy(35,9);
				printf("                                      ");
				break;   
			}
			else
				count++;
		}
		if (user[count].id==0)
			break;
	}
	gotoxy(45,9);	
	printf("                             ");
	while(i < USER_NUM_MAX)
	{
		gotoxy(45,12);
		printf("输入6位纯数字");
		gotoxy(35,12);
		k=glb_putString(pwd1,6,1,0);
		if (k==KEY_ESC)
		{
			return 27;
		}
		gotoxy(45,12);
		printf("                             ");
		gotoxy(45,15);
		printf("再次输入您的密码");
		gotoxy(35,15);
		k=glb_putString(pwd2,6,1,0);
		if (k==KEY_ESC)
		{
			return 27;
		}
		gotoxy(45,15);
		printf("                             ");
		if (strcmp(pwd1,pwd2)==0)
		{
			user[i].id=1001+i;
			memcpy(user[i].name, name, sizeof(name));
			memcpy(user[i].pwd, pwd2, sizeof(pwd2));
			saveUser(&user[i]);
			gotoxy(45,16);
			printf("注册成功");
			gotoxy(64,18);
			printf("继续注册");
			while(1)
			{
				k=get_ikey();
				if (k==KEY_ESC)
					return 27;
				if (k==KEY_ENTER)
					return 13;
			}
		}
		else
		{
			gotoxy(20,16);
			printf("密码不一致,请重新输入  ");
			Sleep(1000);
			gotoxy(20,16);
			printf("                          ");
			gotoxy(35,15);
			printf("                  ");
			gotoxy(35,12);
			printf("                  ");
		}
	}
}

int option_choose()
{
	int i = 0;
	int ikey=0;
	login_face();
	gotoxy(32,6);
	printf("*");
	while(1)
	{
		ikey = get_ikey();
		if (ikey==KEY_ESC)
		{
			return 27;
		}
		if(ikey == KEY_ENTER)
		{
			return i;
		}
		if(ikey == KEY_UP)
		{
			if(i>0)
			{
				i--;
				printf("\b \b");
				gotoxy(32,6+3*i);
				printf("*");
			}
			else
			{
				i=2;
				printf("\b \b");
				gotoxy(32,6+3*i);
				printf("*");
			}
		}
		if(ikey == KEY_DOWN)
		{
			if(i<2)
			{
				i++;
				printf("\b \b");
				gotoxy(32,6+3*i);
				printf("*");
			}
			else
			{
				i=0;
				printf("\b \b");
				gotoxy(32,6+3*i);
				printf("*");
			}
		}
	}
}
