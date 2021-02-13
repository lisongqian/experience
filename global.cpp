//
// Created by LiSongqian on 2020/9/28.
//
#include <iostream>
#include "global.h"

using std::cout;
using std::endl;

void printTree(TreeNode *root)
{
	if (root != nullptr)
	{
		cout << root->val << endl;
		printTree(root->left);
		printTree(root->right);
	}
}