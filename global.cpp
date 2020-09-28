//
// Created by lisongqian on 2020/9/28.
//

#include <memory.h>
#include "global.h"

template<typename ElemType>
bool Swap(ElemType &a, ElemType &b)
{
	ElemType temp;
	memcpy(temp, a, sizeof(ElemType));
	memcpy(a, b, sizeof(ElemType));
	memcpy(b, temp, sizeof(ElemType));
	return true;
}
