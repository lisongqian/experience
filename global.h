//
// Created by lisongqian on 2020/9/28.
//

#ifndef EXPERIENCE_GLOBAL_H
#define EXPERIENCE_GLOBAL_H

template<typename ElemType>
bool Swap(ElemType &a, ElemType &b)
{
	ElemType temp;
	temp = a;
	a = b;
	b = temp;
	return true;
}

#endif //EXPERIENCE_GLOBAL_H
