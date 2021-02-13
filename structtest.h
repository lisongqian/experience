//
// Created by LiSongqian on 2020/12/4.
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


#endif //EXPERIENCE_STRUCTTEST_H
