#ifndef _GBL_INPUT_H_
#define _GBL_INPUT_H_

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "get_ikey.h"


/*iMaxLen 代表字符长度;iPutType: 1，指只能输入数字
2,指只能输入字母  3,指既能输入数字又能输入字母
 isPlanintext: 1指输入明文且输入的字符长度可小于设置
 的字符长度,  其他数指输入密文且必须输满设置的字符长度 */
int glb_putString(char acStr[], int iMaxLen, int iPutType, int isPlaintext);



#endif