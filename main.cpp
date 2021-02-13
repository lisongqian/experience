#include <iostream>
#include <vector>
#include "global.h"

using namespace std;

/**
 * 105.前序和中序遍历构建二叉树
 */
void solution105()
{
	vector<int> p = {3, 9, 20, 15, 7};
	vector<int> i = {9, 3, 15, 20, 7};
	TreeNode *root = Solution::buildTree(p, i);
	printTree(root);
}
/**
 * 编辑距离
 */
void solution72()
{
	string inputStr = "ACT,AGCT";
	string word1, word2;
	int splitIndex = inputStr.find(',');
	word1 = inputStr.substr(0, splitIndex);
	word2 = inputStr.substr(splitIndex + 1, inputStr.size());
	cout << Solution::minDistance(word1, word2) << endl;
}

int main()
{
	solution72();
	return 0;
}