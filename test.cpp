//
// Created by lisongqian on 2020/9/28.
//
#include <iostream>

#ifdef WIN32
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <arpa/inet.h>
#endif

#include "global.h"

using namespace std;


/**
 * 大小端转换
 * @return
 */
int main() {
    union {
        int i[2];
        long k;
        char c[4];
    } r{}, *s = &r;
    s->i[0] = 0x39383736;
    s->i[1] = 0x383940;
    cout << s->c << endl;
// x86为小端模式，需转换为大端(即网络序)
    s->i[0] = htonl(s->i[0]);
    s->i[1] = htonl(s->i[1]);
    cout << s->c << endl;
    return 0;
}
