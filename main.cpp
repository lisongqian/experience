#include <iostream>

using namespace std;
/*
   The operating system, must be one of: (I_OS_x)
     DARWIN   - Any Darwin system (macOS, iOS, watchOS, tvOS)
	 ANDROID  - Android platform
	 WIN32    - Win32 (Windows 2000/XP/Vista/7 and Windows Server 2003/2008)
	 WINRT    - WinRT (Windows Runtime)
	 CYGWIN   - Cygwin
	 LINUX    - Linux
	 FREEBSD  - FreeBSD
	 OPENBSD  - OpenBSD
	 SOLARIS  - Sun Solaris
	 AIX      - AIX
     UNIX     - Any UNIX BSD/SYSV system
*/
#if defined(_WIN32) || defined(__WIN32__) || defined(__WIN32)
	#ifndef WIN32
	#define WIN32
	#endif
#elif defined(_WIN64) || defined(__WIN64__) || defined(__WIN64)
	#ifndef WIN64
	#define WIN64
	#endif
#elif defined(_LINUX) || defined(__LINUX__) || defined(__LINUX)
	#ifndef LINUX
	#define LINUX
	#endif
#endif
