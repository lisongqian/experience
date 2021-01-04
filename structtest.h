//
// Created by Administrator on 2020/12/4.
//

#ifndef EXPERIENCE_STRUCTTEST_H
#define EXPERIENCE_STRUCTTEST_H

#include "global.h"

#if defined (WIN_BYTEALIGN)
#	pragma pack (push)
#	pragma pack (1)
#elif defined(AIX)
#	pragma align(packed)
#endif


typedef struct _SInfo
{
	union B
	{
		int N;
		short shortN;
	};
	char a[NAMELEN];
	B b;
	int RndAng:2;
}DISALIGN SInfo,*pSInfo;

#if defined (WIN_BYTEALIGN)
#	pragma pack(pop)
#elif defined(AIX)
#	pragma align(power)
#endif

class QPoint
{
public:
	QPoint() : m_x(0), m_y(0)
	{}

	QPoint(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	QPoint(const QPoint &point)
	{
		m_x = point.x();
		m_y = point.y();
	}

	int x() const
	{ return m_x; }

	int y() const
	{ return m_y; }

	void setX(int x)
	{ m_x = x; }

	void setY(int y)
	{ m_y = y; }

	QPoint &operator=(const QPoint &point)
	{
		m_x = point.x();
		m_y = point.y();
		return *this;
	}

private:
	int m_x;
	int m_y;
};


#endif //EXPERIENCE_STRUCTTEST_H
