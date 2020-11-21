#ifndef _USER_H_
#define _USER_H_


#include <stdio.h>
#include"get_ikey.h"
#include"inter_face.h"
#include"glb_input.h"
#include"2048_game.h"


typedef struct stu_t
{
	int id;
	char name[10];
	char pwd[10];
}STU_T;
void print(STU_T user[]);
void login_game(STU_T user[]);
int regist_user(STU_T user[]);
int option_choose();              //上下选择，返回i=0，1，2


#endif