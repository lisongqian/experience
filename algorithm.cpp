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
 * 函数HeadAdjust将元素k为根的子树进行调整
 * @tparam ElemType 数组类型模板
 * @param A 数组名
 * @param k 以k为根节点的子树
 * @param len 数组长度
 */
template<typename ElemType>
void HeadAdjust(ElemType A[], int k, int len)
{
	A[0] = A[k];                                //暂存子树的根节点
	for (int i = 2 * k; i <= len; i *= 2)       //沿key较大的子节点向下筛选
	{
		if (i < len && A[i] < A[i + 1])
			i++;                                //取key较大的子节点的下标
		if (A[0] >= A[i]) break;                //筛选结束
		else
		{
			A[k] = A[i];                        //将A[i]调整到双亲节点上
			k = i;                                //修改k值，以便继续向下筛选
		}
	}
	A[k] = A[0];                                //被筛选节点的值放入最终位置
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
