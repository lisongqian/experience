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
 * 72.编辑距离
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

/**
 * 85.最大矩形
 */
void solution85()
{
	char a[4][5] = {
			{'1', '0', '1', '0', '0'},
			{'1', '0', '1', '1', '1'},
			{'1', '1', '1', '1', '1'},
			{'1', '0', '0', '1', '0'}
	};
	vector<vector<char>> matrix(4, vector<char>(5));
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			matrix[i][j] = a[i][j];
		}
	}
	cout << Solution::maximalRectangle(matrix) << endl;
}

/**
 * 1739.放置盒子
 * @return
 */
void solution1739()
{
//	cout << Solution::minimumBoxes(126) << endl;
	// 预期结果 39
	cout << Solution::minimumBoxes(37910271) << endl;
	// 完整三角堆中间变量：result=185745, left=609
	// 预期结果 186146
}

int main()
{
	solution1739();
	return 0;
}