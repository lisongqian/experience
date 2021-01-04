//
// Created by lisongqian on 2020/9/28.
//

#ifndef EXPERIENCE_GLOBAL_H
#define EXPERIENCE_GLOBAL_H

#define NAMELEN 64
#define FILENAME_MAX_LEN 64
#define PI 3.1415926

#if defined(__GNUG__)    // GCC������Ԥ����ĺ�
#	ifndef DISALIGN
#		define DISALIGN __attribute__((packed))
#	endif

#else
#	define DISALIGN
#	if !defined(AIX)	// �� AIX
#		define WIN_BYTEALIGN		// WIN32 CXXʹ��һ�µĶ���궨��
#		define DISALIGN
#	endif

#endif
class QPoint;
template<typename ElemType>
bool Swap(ElemType &a, ElemType &b)
{
	ElemType temp;
	temp = a;
	a = b;
	b = temp;
	return true;
}
extern QPoint RotatePoint(QPoint origin, QPoint point, double angle);
#endif //EXPERIENCE_GLOBAL_H
