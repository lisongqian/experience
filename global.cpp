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
int minInt(int count, ...)
{
	if (count < 0)
		return 0;
	va_list arg_ptr;
	va_start(arg_ptr, count);

	int minNum = va_arg(arg_ptr, int);
	for (int i = 1; i < count; ++i)
	{
		int temp = va_arg(arg_ptr, int);
		if (minNum > temp)
		{
			minNum = temp;
		}
	}
	va_end(arg_ptr);
	return minNum;
}