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
 * ²âÊÔ×óÒÆÓÒÒÆ
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

/**
 * ¶þÎ¬µãÐý×ª²âÊÔ
 * @return
 */
int rotateTest()
{
	QPoint o(0, 0);
	QPoint origin(-10, 10), now;
	double angle = 90.f;
	double a = PI * angle / 180.0;
	now = RotatePoint(o, origin, a);
	cout << origin.x() << "," << origin.y() << endl;
	cout << now.x() << "," << now.y() << endl;
	return 0;
}