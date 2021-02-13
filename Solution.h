//
// Created by LiSongqian on 2021/2/9.
//

#ifndef EXPERIENCE_SOLUTION_H
#define EXPERIENCE_SOLUTION_H

#include <vector>
#include <algorithm>
#include <queue>

using std::vector;

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
	 * @param preorder
	 * @param inorder
	 * @return
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
};


#endif //EXPERIENCE_SOLUTION_H
