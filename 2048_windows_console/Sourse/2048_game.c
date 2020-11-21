#include"2048_game.h"
#include"get_ikey.h"
#include"inter_face.h"


void right_move(int a[4][4])
{
	int i ,j ,k;
	int temp;
	for( i=0 ; i<4 ; i++)
	{
		for( j=3 ; j>=0 ; j--)
		{
			for( k=j-1 ; k>=0 ; k--)
			{		
				if(a[i][j]==0&&a[i][k]!=0)
				{
					temp=a[i][k];
					a[i][k]=a[i][j];
					a[i][j]=temp;
					break;
				}
				else if(a[i][k]==0)
					continue;
			}
		}
	}

}
void left_move(int a[4][4])
{
	int i ,j ,k;
	int temp;
	for( i=0 ; i<4 ; i++)
	{
		for( j=0 ; j<4 ; j++)
		{
			for( k=j+1 ; k<4 ; k++)
			{
				if(a[i][j]==0&&a[i][k]!=0)
				{
					temp=a[i][k];
					a[i][k]=a[i][j];
					a[i][j]=temp;
					break;
				}
				else if(a[i][k]==0)
					continue;
			}
		}
	}
}
void up_move(int a[4][4])
{
	int i,j,k,temp;
	for(k = 0 ; k<4 ; k++)
	{
		for(i = 0 ; i < 4; i++)
		{
			for(j = i+1 ; j<4 ; j++)
			{
				if(a[i][k] == 0 && a[j][k] != 0)
				{
					temp=a[i][k];
					a[i][k] = a[j][k];
					a[j][k] = temp;
					break;
				}
				else if(a[j][k] == 0)
				{
					continue;
				}
			}
		}
	}	
}
void down_move(int a[4][4])
{
	int i,j,k,temp;
	for(k = 0 ; k<4 ; k++)
	{		
		for(i = 3 ; i >= 0; i--)
		{
			for(j = i-1 ; j>=0 ; j--)
			{
				if(a[i][k] == 0 && a[j][k] != 0)
				{
					temp=a[i][k];
					a[i][k] = a[j][k];
					a[j][k] = temp;
				}
				else if(a[j][k] == 0)
				{
					continue;
				}
			}
		}
	}
}
int print_arr(int a[4][4])
{
	int i,j,k=6,score=0;
	game_face();
	gotoxy(25,k);
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",a[i][j]);
			score=score+a[i][j];
		}	
		putchar('\n');
		putchar('\n');
		k=k+2;
		gotoxy(25,k);
	}
	gotoxy(24,15);
	return score;
}
void left_add(int a[4][4])
{
	int i=0,j=0;
	for (i=0;i<4;i++)
	{
		for (j=0;j<3;j++)
		{
			if (a[i][j]==a[i][j+1]&&a[i][j]!=0)
			{
				a[i][j]+=a[i][j+1];
				a[i][j+1]=0;
				left_move(a);
			}
		}
	}
}
void right_add(int a[4][4])
{
	int i=0,j=0;
	for (i=0;i<4;i++)
	{
		for (j=3;j>0;j--)
		{
			if (a[i][j]==a[i][j-1]&&a[i][j]!=0)
			{
				a[i][j]+=a[i][j-1];
				a[i][j-1]=0;
				right_move(a);
			}
		}
	}
}
void up_add(int a[4][4])
{
	int i=0,j=0;
	for (i=0;i<4;i++)
	{
		for (j=0;j<3;j++)
		{
			if (a[j][i]==a[j+1][i]&&a[j][i]!=0)
			{
				a[j][i]+=a[j+1][i];
				a[j+1][i]=0;
				up_move(a);
			}
		}
	}
}
void down_add(int a[4][4])
{
	int i=0,j=0,flag=0;
	for (i=0;i<4;i++)
	{
		for (j=3;j>0;j--)
		{
			if (a[j][i]==a[j-1][i]&&a[j][i]!=0)
			{
				a[j][i]+=a[j-1][i];
				a[j-1][i]=0;
				down_move(a);
			}
		}
	}
}
void array_init(int a[4][4])
{
	int i,j;
	for(i = 0 ; i<4 ; i++)
	{
		for(j=0 ; j<4 ; j++)
		{
			a[i][j] = 0;
		}
	}
}
int check_if_zero(int a[4][4])
{
	int i=0,j=0;
	for (i=0;i<4;i++)
	{
		for (j=0;j<4;j++)
		{
			if (a[i][j]==0)
			{
				return 1;
			}
		}
	}
	return 0;
}
void add_rand(int a[4][4])
{
	int i,j,k,flag=0;
	srand((unsigned int)time(NULL));
	flag=check_if_zero(a);
	if (flag)
	{
		while(1)
		{
			i=rand()%4;
			j=rand()%4;
			if (a[i][j]==0)
			{
				break;
			}
		}
		if ((k=rand()%10)<1)
		{
			a[i][j]=4;
		}
		else
		{
			a[i][j]=2;
		}
	}
	
}
int check_if_same(int a[4][4])
{
	int i=0,j=0;
	for (i=0;i<4;i++)
	{
		for (j=0;j<3;j++)
		{
			if(a[i][j]==a[i][j+1])
				return 1;
			if (a[j][i]==a[j+1][i])
				return 1;
		}
	}
	return 0;
}
int game_over(int a[4][4])
{
	int i=0,j=0,flag=0;
	for (i=0;i<4;i++)
	{
		for (j=0;j<4;j++)
		{
			if (a[i][j]==0)
			{
				return 0;
			}
		}
	}
	if (check_if_same(a)==0)
	{
		gotoxy(30,15);
		printf("游戏结束!");
		return 1;
	}
	return 0;
}
void game()
{
	int i,score=0,flag=0;
	int a[4][4]={{4,2,4,2},{2,4,2,4},{4,2,4,2},{2,4,2,4}};
	while(1)
	{
		system("cls");	
		score=print_arr(a);
		printf("%d",score);
		flag=game_over(a);
		if (flag==1)
		{
			printf("是否重新开始!回车键确定");
			flag=get_ikey();
			if (flag==KEY_ENTER)
			{
				array_init(a);
				continue;
			}
			if (flag==KEY_ESC)
			{
				break;
			}
		}
		i=get_ikey();
		switch(i)
		{
			case KEY_UP:		
				up_move(a);
				up_add(a);
				break;
			case KEY_DOWN:			
				down_move(a);
				down_add(a);
				break;
			case KEY_LEFT:				
				left_move(a);
				left_add(a);
				break;
			case KEY_RIGHT:				
				right_move(a);
				right_add(a);
				break;
			case KEY_ESC:
				return ;
			default:
				continue;
		}
		add_rand(a);
	}
}

void add_arr(int a[4][4])
{
}
