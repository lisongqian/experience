//
// Created by LiSongqian on 2021/2/9.
//

#ifndef EXPERIENCE_SOLUTION_H
#define EXPERIENCE_SOLUTION_H
#pragma once

#include <vector>
#include <string>
#include <cstdarg>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include "global.h"

using std::vector;
using std::string;
using std::stack;
using std::map;
using std::unordered_map;
using std::set;
using std::max;
using std::min;

extern int minInt(int count, ...);

template<typename ElemType>
extern bool Swap(ElemType &a, ElemType &b);

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    /**
     * 根据前序和中序序列构建二叉树
     * @param preorder 前序序列
     * @param inorder 中序序列
     * @return 根节点
     */
    static TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
            return nullptr;
        auto* root = new TreeNode(preorder[0]);
        if (preorder.size() > 1) {
            auto rootIt = std::find(inorder.begin(), inorder.end(), root->val);
            int num = rootIt - inorder.begin();
            vector<int> leftPre(preorder.begin() + 1, preorder.begin() + num + 1);
            vector<int> leftIn(inorder.begin(), rootIt);
            vector<int> rightPre(preorder.begin() + num + 1, preorder.end());
            vector<int> rightIn(rootIt + 1, inorder.end());
            root->left = buildTree(leftPre, leftIn);
            root->right = buildTree(rightPre, rightIn);
        }
        return root;
    }

    /**
     * 编辑距离。计算通过插入和删除操作使得从字符串word1变为word2的最少操作数
     * @param word1 初始字符串
     * @param word2 目标字符串
     * @return 最少操作数
     */
    static int minDistance(string word1, string word2) {
        int count = 0;
        if (word1 == word2) {
            return count;
        }
        if (word1.empty() || word2.empty()) {
            return word1.empty() ? word2.size() : word1.size();
        }
        vector<vector<int> > dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 1; i <= word1.size(); i++) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= word2.size(); i++) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    // minInt在global.cpp中定义
                    dp[i][j] = minInt(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }

    /**
     * 最大矩形
     * @param matrix
     * @return
     */
    static int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int area = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        stack<int> s;
        vector<int> height(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, n);
        for (int i = 0; i < m; ++i) {
            int currLeft = 0, currRight = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                    left[j] = max(left[j], currLeft);
                }
                else {
                    height[j] = 0;
                    left[j] = 0;
                    currLeft = j + 1;

                }
            }
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], currRight);
                }
                else {
                    right[j] = n;
                    currRight = j;
                }
            }
            for (int j = 0; j < n; ++j) {
                area = max(area, (right[j] - left[j]) * height[j]);
            }
        }
        return area;
    }

    /**
     * 放置盒子
     */
    static int minimumBoxes(int n) {
        unsigned long left = 0, right = n;    // 大数处理
        unsigned long mid = 0;                // 大数处理
        while (left < right) {
            mid = (left + right) / 2;
            if ((unsigned long long) mid * (mid + 1) * (mid + 2) / 6 < n) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        left--;// 找到满足最大三角堆的高h
        long surplus = n - left * (left + 1) * (left + 2) / 6; // 剩余方块数，大数处理
        int result = left * (left + 1) / 2;// 三角堆占用的地面大小
        int i = 0;
        while (surplus > 0) {
            surplus -= ++i;
            result++;
        }
        return result;
    }

    /**
     * 数组的最小偏移量
     * @param nums
     * @return
     */
    static int minimumDeviation(vector<int> &nums) {
        set<int> s;
        for (int num: nums)
            s.insert(num % 2 == 0 ? num : num * 2);
        auto minNum = s.begin();
        auto maxNum = --s.end();
        int diff = *maxNum - *minNum;
        while (*maxNum % 2 == 0) {
            int temp = *maxNum / 2;
            s.erase(maxNum);
            s.insert(temp);
            minNum = s.begin();
            maxNum = --s.end();
            diff = min(diff, *maxNum - *minNum);
        }
        return diff;
    }

    static void dfs(vector<int> &side, int n, int k, int i, string &res) {
        int currNode = i % static_cast<int>(pow(k, n - 1));
        for (int j = 0; j < k; ++j) {
            int t = currNode * k + j;
            if (!side[t]++) // 仅遍历没有走过的边
            {
                dfs(side, n, k, t, res);
                res += j + '0';
            }
        }
    }

    /**
     * 破解保险箱
     * @param n 密码位数
     * @param k k个数字
     * @return 密码串
     */
    static string crackSafe(int n, int k) {
        int node = pow(k, n - 1);            /* 节点个数 */
        vector<int> side(node * k, 0);    /* 边数标志，用来指示每条边是否遍历过 */
        string res;
        dfs(side, n, k, 0, res);        /* 从 n -1 个 0 的节点开始寻找 */
        res.append(n - 1, '0');            /* 补充起始节点字符串 */
        return res;                            /* 无需 reverse，翻转前后均为正确答案 */
    }

    /**
     * 括号生成
     * @param n
     * @return
     */
    vector<string> generateParenthesis(int n) {
        strList.clear();
        recursive("", 0, 0, n);
        return strList;
    }

    vector<string> strList;

    void recursive(string str, int left, int right, int n) {
        if (left == n && right == n) {
            strList.push_back(str);
            return;
        }
        if (left < n) {
            recursive(str + "(", left + 1, right, n);
        }
        if (left > right) {
            recursive(str + ")", left, right + 1, n);
        }
    }

    /**
     * 剑指 Offer 03. 数组中重复的数字
     * @param nums
     * @return
     */
    int findRepeatNumber(vector<int> &nums) {
        map<int, int> m;
        for (auto i: nums) {
            auto it = m.find(i);
            if (it == m.end()) {
                m[i] = 1;
            }
            else {
                m[i]++;
                if (m[i] == 2) {
                    return i;
                }
            }
        }
        return -1;
    }

    /**
     * 剑指 Offer 53 - I. 在排序数组中查找数字 I
     * @param nums
     * @param target
     * @return
     */
    int search(vector<int> &nums, int target) {
        if (nums.empty()) return 0;
        int sum = 0;
        int left = 0, right = nums.size() - 1;
        int i = (left + right) / 2;
        while (left < right) {
            if (nums[i] < target)
                left = i + 1;
            else if (nums[i] > target)
                right = i - 1;
            else
                break;
            i = (left + right) / 2;
        }
        for (int j = i; j < nums.size() && nums[j] == target; ++j) {
            sum++;
        }
        for (int j = i - 1; j >= 0 && nums[j] == target; --j) {
            sum++;
        }
        return sum;
    }

    /**
     * 剑指 Offer 53 - II. 0～n-1中缺失的数字
     * @param nums
     * @return
     */
    int missingNumber(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        int i = (left + right) / 2;
        while (left <= right) {
            if (i < nums[i])//左边少值
            {
                right = i - 1;
            }
            else {
                left = i + 1;
            }
            i = (left + right) / 2;
        }
        return left;
    }


    /**
     * 437. 路径总和 III
     * @param root
     * @param targetSum
     * @return
     */
    vector<long> prefix = {0};

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        int ret = 0;
        if (root->val == targetSum) {
            ret++;
        }
        prefix.push_back(root->val);
        ret += dfs(root->left, targetSum);
        ret += dfs(root->right, targetSum);
        return ret;
    }

    int dfs(TreeNode* root, int target) {
        int ret = 0;
        if (root != nullptr) {
            long last = prefix[prefix.size() - 1];
            for (int item: prefix) {
                if (last - item + root->val == target) {
                    ret++;
                }
            }
            prefix.push_back(prefix[prefix.size() - 1] + root->val);
            ret += dfs(root->left, target);
            ret += dfs(root->right, target);
            prefix.pop_back();
        }
        return ret;
    }

    /**
     * 455. 分发饼干
     * @param g
     * @param s
     * @return
     */
    int findContentChildren(vector<int> &g, vector<int> &s) {
        int ret = 0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int i = 0;
        for (int item: g) {
            for (; i < s.size(); ++i) {
                if (item <= s[i]) {
                    ret++;
                    i++;
                    break;
                }
            }
        }
        return ret;
    }

    string convertToBase7(int num) {
        string a;
        if (num == 0) {
            a = "0";
            return a;
        }
        bool flag = false;
        if (num < 0) {
            flag = true;
            num = -num;
        }
        while (num > 0) {
            int target = num % 7;
            a += std::to_string(target);
            num = num / 7;
        }
        if (flag) {
            a += "-";
        }
        std::reverse(a.begin(), a.end());
        return a;
    }

    int distributeCandies(vector<int> &candyType) {
        set<int> s(candyType.begin(), candyType.end());
        return min(s.size(), candyType.size() / 2);
    }

    bool checkPossibility(vector<int> &nums) {
        int ret = 0;
        for (int i = 1; i < nums.size(); ++i) {
            // i-2 i-1 i i+1
            if (nums[i - 1] > nums[i]) {
                if (i < 2 || nums[i] >= nums[i - 2]) {
                    ret++;

                }
                else if (i >= nums.size() - 1 || nums[i - 1] <= nums[i + 1]) {
                    ret++;
                }
                else {
                    return false;
                }
                if (ret > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * 面试题 17.09. 第 k 个数
     * @param k
     * @return
     */
    int getKthMagicNumber(int k) {
        vector<int> results(k + 1, 1);
        int k3 = 1, k5 = 1, k7 = 1;
        for (int i = 2; i <= k; ++i) {
            int num = std::min(std::min(results[k3] * 3, results[k5] * 5), results[k7] * 7);
            if (num == results[k3] * 3) {
                k3++;
            }
            else if (num == results[k5] * 5) {
                k5++;
            }
            else if (num == results[k7] * 7) {
                k7++;
            }
            if (num == results[i - 1]) {
                i--;
                continue;
            }
            results[i] = num;
        }
        return results[k];
    }

    /**
     * 面试题 17.23. 最大黑方阵
     * @param matrix
     * @return
     */
    vector<int> findSquare(vector<vector<int>> &matrix) {
        vector<vector<int>> right(matrix.size(), vector<int>(matrix.size()));
        vector<vector<int>> bottom(matrix.size(), vector<int>(matrix.size()));
        vector<int> result(3, 0);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                int k = j, temp = 0;
                while (k < matrix.size() && matrix[i][k++] == 0) temp++;
                right[i][j] = temp;
                k = i, temp = 0;
                while (k < matrix.size() && matrix[k++][j] == 0) temp++;
                bottom[i][j] = temp;
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                int edge = std::min(right[i][j], bottom[i][j]);
                for (int k = edge; k > 0; --k) {
                    // 右上角点                   左下角点
                    if (bottom[i][j + k - 1] >= k && right[i + k - 1][j] >= k) {
                        if (k > result[2]
                            || (k == result[2] && i < result[0])
                            || (k == result[2] && i == result[0] && j < result[1])) {
                            result = {i, j, k};
                        }
                        break;
                    }
                }
            }
        }
        if (result[2] == 0) {
            result.clear();
        }
        return result;
    }

};


#endif //EXPERIENCE_SOLUTION_H
