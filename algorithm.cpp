//
// Created by lisongqian on 2020/9/28.
//
#include "global.h"
#include "algorithm.h"

template<typename ElemType>
void BuildMaxHeap(ElemType A[], int len)
{
	for (int i = len / 2; i > 0; i--)
	{
		HeadAdjust(A, i, len);
	}
}

/**
 * ����HeadAdjust��Ԫ��kΪ�����������е���
 * @tparam ElemType ��������ģ��
 * @param A ������
 * @param k ��kΪ���ڵ������
 * @param len ���鳤��
 */
template<typename ElemType>
void HeadAdjust(ElemType A[], int k, int len)
{
	A[0] = A[k];                                //�ݴ������ĸ��ڵ�
	for (int i = 2 * k; i <= len; i *= 2)       //��key�ϴ���ӽڵ�����ɸѡ
	{
		if (i < len && A[i] < A[i + 1])
			i++;                                //ȡkey�ϴ���ӽڵ���±�
		if (A[0] >= A[i]) break;                //ɸѡ����
		else
		{
			A[k] = A[i];                        //��A[i]������˫�׽ڵ���
			k = i;                                //�޸�kֵ���Ա��������ɸѡ
		}
	}
	A[k] = A[0];                                //��ɸѡ�ڵ��ֵ��������λ��
}

template<typename ElemType>
void HeapSort(ElemType A[], int len)
{
	BuildMaxHeap(A, len);
	for (int i = len; i > 1; i--)
	{
		Swap(A[i], A[1]);
		HeadAdjust(A, 1, i - 1);
	}
}
