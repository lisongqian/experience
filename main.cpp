#include <iostream>
#include <algorithm>
#include <vector>
#include "global.h"
#include "ccf.h"

using namespace std;

/**
 * 105.前序和中序遍历构建二叉树
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 */
void solution105() {
    vector<int> p = {3, 9, 20, 15, 7};
    vector<int> i = {9, 3, 15, 20, 7};
    TreeNode *root = Solution::buildTree(p, i);
    printTree(root);
}

/**
 * 72.编辑距离
 * https://leetcode-cn.com/problems/building-boxes/
 */
void solution72() {
    string inputStr = "ACT,AGCT";
    string word1, word2;
    int splitIndex = inputStr.find(',');
    word1 = inputStr.substr(0, splitIndex);
    word2 = inputStr.substr(splitIndex + 1, inputStr.size());
    cout << Solution::minDistance(word1, word2) << endl;
}

/**
 * 85.最大矩形
 * https://leetcode-cn.com/problems/maximal-rectangle/
 */
void solution85() {
    char a[4][5] = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };
    vector<vector<char>> matrix(4, vector<char>(5));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = a[i][j];
        }
    }
    cout << Solution::maximalRectangle(matrix) << endl;
}

/**
 * 1739.放置盒子
 * https://leetcode-cn.com/problems/building-boxes/
 */
void solution1739() {
    cout << Solution::minimumBoxes(37910271) << endl;
    // 完整三角堆中间变量：result=185745, left=609
    // 预期结果 186146
}

/**
 * 1675. 数组的最小偏移量
 * https://leetcode-cn.com/problems/minimize-deviation-in-array/
 */
void solution1675() {
    vector<int> vec = {4, 1, 5, 20, 3};
    cout << Solution::minimumDeviation(vec) << endl;
}

/**
 * 753. 破解保险箱
 * https://leetcode-cn.com/problems/cracking-the-safe/
 */
void solution753() {
    cout << Solution::crackSafe(2, 2) << endl;
}

/**
 * 22. 括号生成
 * https://leetcode-cn.com/problems/generate-parentheses/
 */
void solution22() {
    auto s = new Solution();
    vector<string> result = s->generateParenthesis(3);
    for (auto &it: result)
        cout << it << endl;
}

bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}

/**
 * 数组组成最大数
 *
 */
void solutoinMaxArrNum() {
    vector<string> a = {"10", "1", "2"};
    /* 提交时使用
    string str;
    cin >> str;
    str = str.substr(1, str.length() - 2);
    str += ',';
    string temp = "";
    a.clear();
    for (auto &item:str)
    {
        if (item == ',')
        {
            a.push_back(temp);
            temp = "";
        }
        else
        {
            temp += item;
        }
    }
     */
    sort(a.begin(), a.end(), cmp);
    for (auto &item: a)
        cout << item;
    cout << endl;
}

int main() {
    so201312();
    return 0;
}
