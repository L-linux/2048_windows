#ifndef _GBL_INPUT_H_
#define _GBL_INPUT_H_

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "get_ikey.h"


/*iMaxLen �����ַ�����;iPutType: 1��ָֻ����������
2,ָֻ��������ĸ  3,ָ����������������������ĸ
 isPlanintext: 1ָ����������������ַ����ȿ�С������
 ���ַ�����,  ������ָ���������ұ����������õ��ַ����� */
int glb_putString(char acStr[], int iMaxLen, int iPutType, int isPlaintext);



#endif