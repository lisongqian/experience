//
// Created by lisongqian on 2022/1/17.
//

#ifndef EXPERIENCE_CCF_H
#define EXPERIENCE_CCF_H
#include <iostream>
using namespace std;
/**
 * 202112-1	序列查询
 * @return
 */
int so202112()
{
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

#endif //EXPERIENCE_CCF_H
