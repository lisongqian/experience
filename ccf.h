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
    vector <point> a;
    a.clear();
    vector <point> b;
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

/**
 * 201812-1	小明上学
 * @return
 */
int so201812() {
    int r, y, g, n;
    cin >> r >> y >> g >> n;
    int sum = 0;
    int k, t;
    for (int i = 0; i < n; ++i) {
        cin >> k >> t;
        switch (k) {
            case 0://道路
            {
                sum += t;
                break;
            }
            case 1://红灯
            {
                sum += t;
                break;
            }
            case 2://黄灯
            {
                sum += t + r;
                break;
            }
            case 3://绿灯
            {
                break;
            }
            default:
                break;
        }
    }
    cout << sum << endl;
    return 0;
}

/**
 * 201809-1 卖菜
 * @return
 */
int so201809() {
    int arr[1000] = {0};
    int n, price;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> price;
        arr[i] = price;
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            cout << (arr[i] + arr[i + 1]) / 2 << " ";
        } else if (i == n - 1) {
            cout << (arr[i - 1] + arr[i]) / 2 << endl;
        } else {
            cout << (arr[i - 1] + arr[i] + arr[i + 1]) / 3 << " ";
        }
    }
    return 0;
}

/**
 * 201803-1 跳一跳
 * @return
 */
int so201803() {
    int num;
    cin >> num;
    int score = 0;
    bool center = false;
    int pre = 0;
    while (num != 0) {
        switch (num) {
            case 1: {
                center = false;
                pre = 0;
                score++;
                break;
            }
            case 2: {
                if (center) {
                    score += pre;
                }
                score += 2;
                pre += 2;
                center = true;
                break;
            }
            default:
                break;
        }
        cin >> num;
    }
    cout << score << endl;
    return 0;
}

/**
 * 201712-1 最小差值
 * @return
 */
int so201712() {
    int n, num;
    cin >> n;
    int arr[1000] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> num;
        int j = i - 1;
        for (; j >= 0; j--) {
            if (num > arr[j])
                break;
        }
        for (int k = i; k > j + 1; k--)
            arr[k] = arr[k - 1];
        arr[j + 1] = num;
    }
    int result = arr[1] - arr[0];
    for (int i = 2; i < n; ++i) {
        int temp = arr[i] - arr[i - 1];
        if (result > temp)
            result = temp;
    }
    cout << result << endl;
    return 0;
}

/**
 * 201709-1 打酱油
 * @return
 */
int so201709() {
    int n;
    cin >> n;
    int sum = 0;
    sum = (n / 50) * 7 + (n % 50 / 30) * 4 + n % 50 % 30 / 10;
    cout << sum << endl;
    return 0;
}

/**
 * 201703-1 分蛋糕
 * @return
 */
int so201703() {
    int n, k;
    cin >> n >> k;
    int people = 0, g = 0;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (flag) {
            people++;
            flag = false;
        }
        g += a;
        if (g >= k) {
            flag = true;
            g = 0;
        }
    }
    cout << people << endl;
    return 0;
}

/**
 * 201612-1 中间数
 * @return
 */
int so201612() {
    int n;
    cin >> n;
    int arr[1000] = {0};
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        int j = i - 1;
        for (; j >= 0; --j) {
            if (a > arr[j])
                break;
        }
        for (int k = i; k > j + 1; --k) {
            arr[k] = arr[k - 1];
        }
        arr[j + 1] = a;
    }
    int mid = arr[n / 2];
    int small = 0, big = 0;
    for (int i = n / 2; i >= 0; --i) {
        if (arr[i] < mid) {
            small = i + 1;
            break;
        }
    }
    for (int i = n / 2; i < n; ++i) {
        if (arr[i] > mid) {
            big = n - i;
            break;
        }
    }
    if (small == big)
        cout << mid << endl;
    else
        cout << -1 << endl;
    return 0;
}

/**
 * 201609-1 最大波动
 * @return
 */
int so201609() {
    int n;
    cin >> n;
    int pre, a, result = 0;
    cin >> pre;
    for (int i = 1; i < n; ++i) {
        cin >> a;
        int temp = a - pre > 0 ? a - pre : pre - a;
        if (temp > result)
            result = temp;
        pre = a;
    }
    cout << result << endl;
    return 0;
}

/**
 * 201604-1 折点计划
 * @return
 */
int so201604() {
    int n, pre, a;
    cin >> n;
    int sum = 0;
    bool optimistic = true;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (i != 0) {
            if (i == 1) optimistic = a - pre > 0;
            bool temp = a - pre > 0;
            if (optimistic != temp) {
                sum++;
                optimistic = temp;
            }
        }
        pre = a;
    }
    cout << sum << endl;
    return 0;
}

/**
 * 201512-1 数位之和
 * @return
 */
int so201512() {
    long int n;
    cin >> n;
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    cout << sum << endl;
    return 0;
}

/**
 * 201509-1 数列分段
 * @return
 */
int so201509() {
    int n, pre, a, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (i == 0) {
            pre = a;
            sum++;
        }
        if (a != pre)
            sum++;
        pre = a;
    }
    cout << sum << endl;
    return 0;
}

/**
 * 201503-1 图像旋转
 * @return
 */
int so201503() {
    int n, m;
    cin >> n >> m;
    static int a[1000][1000]; //Note: 使用全局变量，避免局部变量的大数组导致堆栈溢出
    int num;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> num;
            a[i][j] = num;
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; ++j) {
            cout << a[j][i];
            if (j != n - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}

/**
 * 201412-1 门禁系统
 * @return
 */
int so201412() {
    int n;
    cin >> n;
    int arr[1000];
    int a, sum = 1;
    for (int i = 0; i < n; ++i) {
        sum = 1;
        cin >> a;
        arr[i] = a;
        for (int j = 0; j < i; ++j) {
            if (arr[j] == a) sum++;
        }
        cout << sum;
        if (i != n - 1) cout << " ";
    }
    return 0;
}

/**
 * 201409-1 相邻数对
 * @return
 */
int so201409() {
    int n;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        int j = i - 1;
        for (; j >= 0; j--) {
            if (temp > a[j])
                break;
        }
        for (int k = i; k > j + 1; k--) {
            a[k] = a[k - 1];
        }
        a[j + 1] = temp;
    }
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] + 1 == a[i])
            sum++;
    }
    cout << sum << endl;
    return 0;
}

/**
 * 201403-1 相反数
 * @return
 */
int so201403() {
    int n, a, sum = 0;
    int arr[500];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        for (int j = 0; j < i; ++j) {
            if (a + arr[j] == 0)
                sum++;
        }
        arr[i] = a;
    }
    cout << sum << endl;
    return 0;
}
/**
 * 201312-1 出现次数最多的数
 * @return
 */
#include <map>

int so201312() {
    int n;
    cin >> n;
    map<int, int> m;
    m.clear();
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (m.find(a) == m.end()) {
            m[a] = 1;
        } else
            m[a]++;
    }
    int key, value = -1;
    for (auto & iter : m) {
        if (iter.second > value) {
            key = iter.first;
            value = iter.second;
        } else if (iter.second == value && iter.first < key)
            key = iter.first;
    }
    cout << key << endl;
    return 0;
}

#endif //EXPERIENCE_CCF_H
