#ifndef _2048_GAME_H_
#define _2048_GAME_H_

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#include"get_ikey.h"
#include"inter_face.h"
#include"glb_input.h"
#include"2048_game.h"

void right_move(int a[4][4]);
void left_move(int a[4][4]);
void up_move(int a[4][4]);
void down_move(int a[4][4]);
void left_add(int a[4][4]);
void right_add(int a[4][4]);
void up_add(int a[4][4]);
void down_add(int a[4][4]);



int check_if_same(int a[4][4]);
int check_if_zero(int a[4][4]);
void add_rand(int a[4][4]);
int game_over(int a[4][4]);



void game();
void add_arr(int a[4][4]);
int print_arr(int a[4][4]);
void array_init(int a[4][4]);

#endif