#include <iostream>
#include <vector>
#include "global.h"

using namespace std;

/**
 * 105.ǰ��������������������
 */
void solution105()
{
	vector<int> p = {3, 9, 20, 15, 7};
	vector<int> i = {9, 3, 15, 20, 7};
	TreeNode *root = Solution::buildTree(p, i);
	printTree(root);
}

int main()
{
	return 0;
}