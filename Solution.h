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
#include "global.h"

using std::vector;
using std::string;
using std::stack;
using std::max;
using std::min;

extern int minInt(int count, ...);


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
	 * ����ǰ����������й���������
	 * @param preorder ǰ������
	 * @param inorder ��������
	 * @return ���ڵ�
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
	 * �༭���롣����ͨ�������ɾ������ʹ�ô��ַ���word1��Ϊword2�����ٲ�����
	 * @param word1 ��ʼ�ַ���
	 * @param word2 Ŀ���ַ���
	 * @return ���ٲ�����
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
					// minInt��global.cpp�ж���
					dp[i][j] = minInt(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
				}
			}
		}
		return dp[word1.size()][word2.size()];
	}

	/**
	 * ������
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
	 * ���ú���
	 */
	static int minimumBoxes(int n)
	{
		unsigned long left = 0, right = n;    // ��������
		unsigned long mid = 0;                // ��������
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
		left--;// �ҵ�����������Ƕѵĸ�h
		long surplus = n - left * (left + 1) * (left + 2) / 6; // ʣ�෽��������������
		int result = left * (left + 1) / 2;// ���Ƕ�ռ�õĵ����С
		int i = 0;
		while (surplus > 0)
		{
			surplus -= ++i;
			result++;
		}
		return result;
	}
};


#endif //EXPERIENCE_SOLUTION_H
