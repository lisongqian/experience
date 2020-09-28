#include <iostream>
#include "algorithm.h"

using namespace std;
using namespace algorithm;

int main()
{
	int arr[] = {1, 2, 3, 2};
	int len = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " " << endl;
	}
	return 0;
}
