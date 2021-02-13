//
// Created by LiSongqian on 2021/2/9.
//

#ifndef EXPERIENCE_SOLUTION_H
#define EXPERIENCE_SOLUTION_H
#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include "global.h"
#include "Solution.h"

using std::vector;
using std::string;
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
};


#endif //EXPERIENCE_SOLUTION_H