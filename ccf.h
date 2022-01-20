//
// Created by lisongqian on 2022/1/17.
// CCF 第一题题解
//

#ifndef EXPERIENCE_CCF_H
#define EXPERIENCE_CCF_H
#pragma once

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
        h[a]++;
    }
    for (int i = 0; i < L; ++i) {
        cout << h[i];
        if (i < L - 1)
            cout << " ";
    }
    return 0;
}

/**
 * 202012-1 期末预测之安全指数
 * @return
 */
int so202012() {
    int n;
    cin >> n;
    int a, b;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        sum += a * b;
    }
    sum = sum > 0 ? sum : 0;
    cout << sum;
    return 0;
}

/**
 * 202009-1 称检测点查询
 * @return
 */

int so202009() {
    struct point {
        int index;
        int d;//距离
    };

    int n, x, y;
    cin >> n >> x >> y;
    int xi, yi;
    point arr[200] = {0, 0};
    for (int i = 1; i <= n; ++i) {
        cin >> xi >> yi;
        point p = {i, (x - xi) * (x - xi) + (y - yi) * (y - yi)};
        int j = i - 1;
        for (; j >= 0; j--) {
            if (p.d >= arr[j].d)
                break;
        }
        for (int k = i; k > j + 1; k--)
            arr[k] = arr[k - 1];
        arr[j + 1] = p;
    }
    for (int i = 1; i <= 3; ++i) {
        cout << arr[i].index << endl;
    }
    return 0;
}

/**
 * 202006-1	线性分类器
 * @return
 */
int so202006() {
/**测试用例
9 3
1 1 A
1 0 A
1 -1 A
2 2 B
2 3 B
0 1 A
3 1 B
1 3 B
2 0 A
0 2 -3
-3 0 2
-3 1 1
 */
    struct point {
        int x;
        int y;
    };
    long int n;
    int m;
    cin >> n >> m;
    vector<point> a;
    a.clear();
    vector<point> b;
    b.clear();
    int x, y;
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        getchar();
        cin >> c;
        if (c == 'A') {
            a.push_back({x, y});
        } else if (c == 'B') {
            b.push_back({x, y});

        }
    }
    int theta0, theta1, theta2;
    for (int i = 0; i < m; ++i) {
        cin >> theta0 >> theta1 >> theta2;
        bool yes = true;
        bool optimistic = (theta0 + theta1 * a[0].x + theta2 * a[0].y) > 0;
        for (int j = 1; j < a.size(); ++j) {
            bool temp = (theta0 + theta1 * a[j].x + theta2 * a[j].y) > 0;
            if (temp != optimistic) {
                yes = false;
                cout << "No" << endl;
                break;
            }
        }
        if (yes) // A点落在同侧时
        {
            for (int j = 1; j < b.size(); ++j) {
                bool temp = (theta0 + theta1 * b[j].x + theta2 * b[j].y) > 0;
                if (temp == optimistic) {// 要求B点不能落在跟A同侧
                    yes = false;
                    cout << "No" << endl;
                    break;
                }
            }
        }
        if (yes)
            cout << "Yes" << endl;
    }
    return 0;
}

/**
 * 201912-1 报数
 * @return
 */
int so201912() {
    int n;
    int arr[4] = {0};
    cin >> n;
    int num = 1, count = 0;
    for (int i = 0; count < n; i = (i + 1) % 4, num++) {
        if (num % 7 == 0 || num % 10 == 7 || num / 10 % 10 == 7 || num / 100 % 10 == 7)
            arr[i]++;
        else
            count++;
    }
    for (int i: arr) {
        cout << i << endl;
    }
    return 0;
}

/**
 * 201909-1	小明种苹果
 * @return
 */
int so201909() {
    int n, m;
    cin >> n >> m;
    long int appleTree = 0;
    long int appleSum = 0;
    int appleIndex = 0;
    int appleIndexDeleteSum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> appleTree;
        appleSum += appleTree;
        long int deleteNum = 0;
        long int deleteSum = 0;
        for (int j = 0; j < m; ++j) {
            cin >> deleteNum;
            deleteSum += -deleteNum; // 取正数
            appleSum += deleteNum;
        }
        if (deleteSum > appleIndexDeleteSum) {
            appleIndex = i;
            appleIndexDeleteSum = deleteSum;
        }
    }
    cout << appleSum << " " << appleIndex + 1 << " " << appleIndexDeleteSum << endl;
    return 0;
}

/**
 * 201903-1 小中大
 * @return
 */
int so201903() {
    int n;
    cin >> n;
    vector<long int> arr;
    arr.clear();
    long int input;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        arr.push_back(input);
    }
    long int max = arr[0] > arr[arr.size() - 1] ? arr[0] : arr[arr.size() - 1];
    long int min = arr[0] < arr[arr.size() - 1] ? arr[0] : arr[arr.size() - 1];
    cout << max << " ";
    if (n % 2 == 0) {
        if ((arr[arr.size() / 2 - 1] + arr[arr.size() / 2]) % 2 != 0)
            printf("%.1f", (arr[arr.size() / 2 - 1] + arr[arr.size() / 2]) / 2.0);
        else
            cout << (arr[arr.size() / 2 - 1] + arr[arr.size() / 2]) / 2;
    } else
        cout << arr[(arr.size() - 1) / 2];
    cout << " " << min;
    return 0;
}

#endif //EXPERIENCE_CCF_H
