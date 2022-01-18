//
// Created by lisongqian on 2022/1/17.
// CCF 第一题题解
//

#ifndef EXPERIENCE_CCF_H
#define EXPERIENCE_CCF_H

#include <iostream>

using namespace std;

/**
 * 202112-1	序列查询
 * @return
 */
int so202112() {
    long int arr[200] = {0};
    int n;
    long int N;
    cin >> n >> N;
    long int a = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        arr[i] = a;
    }
    long int sum = 0;
    int left = 0, right = 1, num = 0;
    while (right <= n) {
        num += arr[right] - arr[left]; // 数量
        sum += left * (arr[right] - arr[left]);
        if (right == n)
            sum += right * (N - num);
        left++;
        right++;
    }
    cout << sum;
    return 0;
}

/**
 * 202109-1	数组推导
 * @return
 */
int so202109() {
    long int B[100] = {0};
    int n;
    cin >> n;
    long int a = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        B[i] = a;
    }
    long int minSum = B[0], maxSum = B[0];
    for (int i = 1; i < n; i++) {
        if (B[i] == B[i - 1]) {
            minSum += 0;
            maxSum += B[i];
        } else {
            minSum += B[i];
            maxSum += B[i];
        }
    }
    cout << maxSum << endl << minSum;
    return 0;
}

/**
 * 202104-1 灰度直方图
 * @return
 */
int so202104() {
    int n, m, L;
    cin >> n >> m >> L;
    int h[256] = {0};
    int a = 0;
    for (int i = 0; i < m * n; i++) {
        cin >> a;
        h[a] ++;
    }
    for (int i = 0; i < L; ++i) {
        cout<<h[i];
        if(i<L-1)
            cout<<" ";
    }
    return 0;
}
/**
 * 202012-1 期末预测之安全指数
 * @return
 */
int so202012()
{
    int n;
    cin>>n;
    int a,b;
    int sum  =0;
    for (int i = 0; i < n; ++i) {
        cin>>a>>b;
        sum += a*b;
    }
    sum = sum>0?sum:0;
    cout<<sum;
    return 0;
}

#endif //EXPERIENCE_CCF_H
