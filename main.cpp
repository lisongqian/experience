
#include <iostream>
#include "calgorithm.h"

int main()
{
	//�����������1��λ�ÿ�ʼ����,0��λΪ�ݴ�����
	int arr[] = {-1, 0, 8, 4, 2};
	int len = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, len - 1);
	for (int i = 1; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
	return 0;
}
