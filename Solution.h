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
#include <cmath>
#include "global.h"

using std::vector;
using std::string;
using std::stack;
using std::set;
using std::max;
using std::min;

extern int minInt(int count, ...);

template<typename ElemType>
extern bool Swap(ElemType &a, ElemType &b);

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode() : val(0), left(nullptr), right(nullptr)
	{}

	explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{}

	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
	{}
};

class Solution
{
public:
	/**
	 * 根据前序和中序序列构建二叉树
	 * @param preorder 前序序列
	 * @param inorder 中序序列
	 * @return 根节点
	 */
	static TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
			return nullptr;
		auto *root = new TreeNode(preorder[0]);
		if (preorder.size() > 1)
		{
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
	static int minDistance(string word1, string word2)
	{
		int count = 0;
		if (word1 == word2)
		{
			return count;
		}
		if (word1.empty() || word2.empty())
		{
			return word1.empty() ? word2.size() : word1.size();
		}
		vector<vector<int> > dp(word1.size() + 1, vector<int>(word2.size() + 1));
		for (int i = 1; i <= word1.size(); i++)
		{
			dp[i][0] = i;
		}
		for (int i = 1; i <= word2.size(); i++)
		{
			dp[0][i] = i;
		}
		for (int i = 1; i <= word1.size(); i++)
		{
			for (int j = 1; j <= word2.size(); j++)
			{
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
				{
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
	static int maximalRectangle(vector<vector<char> > &matrix)
	{
		if (matrix.empty() || matrix[0].empty())
		{
			return 0;
		}
		int area = 0;
		int m = matrix.size();
		int n = matrix[0].size();
		stack<int> s;
		vector<int> height(n, 0);
		vector<int> left(n, 0);
		vector<int> right(n, n);
		for (int i = 0; i < m; ++i)
		{
			int currLeft = 0, currRight = n;
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == '1')
				{
					height[j]++;
					left[j] = max(left[j], currLeft);
				}
				else
				{
					height[j] = 0;
					left[j] = 0;
					currLeft = j + 1;

				}
			}
			for (int j = n - 1; j >= 0; j--)
			{
				if (matrix[i][j] == '1')
				{
					right[j] = min(right[j], currRight);
				}
				else
				{
					right[j] = n;
					currRight = j;
				}
			}
			for (int j = 0; j < n; ++j)
			{
				area = max(area, (right[j] - left[j]) * height[j]);
			}
		}
		return area;
	}

	/**
	 * 放置盒子
	 */
	static int minimumBoxes(int n)
	{
		unsigned long left = 0, right = n;    // 大数处理
		unsigned long mid = 0;                // 大数处理
		while (left < right)
		{
			mid = (left + right) / 2;
			if ((unsigned long long) mid * (mid + 1) * (mid + 2) / 6 < n)
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		left--;// 找到满足最大三角堆的高h
		long surplus = n - left * (left + 1) * (left + 2) / 6; // 剩余方块数，大数处理
		int result = left * (left + 1) / 2;// 三角堆占用的地面大小
		int i = 0;
		while (surplus > 0)
		{
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
	static int minimumDeviation(vector<int> &nums)
	{
		set<int> s;
		for (int num : nums)
			s.insert(num % 2 == 0 ? num : num * 2);
		auto minNum = s.begin();
		auto maxNum = --s.end();
		int diff = *maxNum - *minNum;
		while (*maxNum % 2 == 0)
		{
			int temp = *maxNum / 2;
			s.erase(maxNum);
			s.insert(temp);
			minNum = s.begin();
			maxNum = --s.end();
			diff = min(diff, *maxNum - *minNum);
		}
		return diff;
	}

	static void dfs(vector<int> &side, int n, int k, int i, string &res)
	{
		int currNode = i % static_cast<int>(pow(k, n - 1));
		for (int j = 0; j < k; ++j)
		{
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
	static string crackSafe(int n, int k)
	{
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
	vector<string> generateParenthesis(int n)
	{
		strList.clear();
		recursive("", 0, 0, n);
		return strList;
	}

	vector<string> strList;

	void recursive(string str, int left, int right, int n)
	{
		if (left == n && right == n)
		{
			strList.push_back(str);
			return;
		}
		if (left < n)
		{
			recursive(str + "(", left + 1, right, n);
		}
		if (left > right)
		{
			recursive(str + ")", left, right + 1, n);
		}
	}
};


#endif //EXPERIENCE_SOLUTION_H
