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

/**
 * 72.�༭����
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
 * 85.������
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
 * 1739.���ú���
 * @return
 */
void solution1739()
{
//	cout << Solution::minimumBoxes(126) << endl;
	// Ԥ�ڽ�� 39
	cout << Solution::minimumBoxes(37910271) << endl;
	// �������Ƕ��м������result=185745, left=609
	// Ԥ�ڽ�� 186146
}

int main()
{
	solution1739();
	return 0;
}