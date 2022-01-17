//
// Created by lisongqian on 2020/9/28.
//
#include <iostream>
#include "global.h"
#include "structtest.h"
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;


/**
 * 测试左移右移
 * @return
 */
int moveTest()
{
	unsigned int state = 0xe0;
	unsigned int isFa = 0, iFaModel = 0, iFaStCont = 0;
	isFa = state >> 6;
	iFaModel = (state & 0x3f) >> 4;
	iFaStCont = (state & 0x0f) >> 2;
	cout << state << endl;
	cout << isFa << " " << iFaModel << " " << iFaStCont << endl;
	return 0;

}
