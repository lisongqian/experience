//
// Created by LiSongqian on 2020/12/4.
//
#include <iostream>
#include <cstring>
#include "structtest.h"

using std::cout;
using std::endl;

int test()
{
	char *p = nullptr;
	auto *obj = new SInfo();
	memset(obj->a, '\0', sizeof(obj->a));
	obj->b.N = 1;
	obj->b.shortN = 2;
	cout << sizeof(p) << endl;							// DWORD ��С  8�ֽ�
	cout << sizeof(*p) << endl;							// char  ��С  1�ֽ�
	cout << sizeof(obj) << endl;						// DWORD ��С  8�ֽ�
	cout << sizeof(*obj) << endl;						// SInfo ��С 68�ֽ�
	cout << obj->b.N << " " << obj->b.shortN << endl;
	delete obj;
	return 0;
}
