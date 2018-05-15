#pragma once

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>

typedef int DataType;

typedef struct Heap
{
	DataType * _array;
	int _size;
	int _capacity;
}Heap;

//堆的初始化
void InitHeap(Heap* hp);

//创建一个堆
void CreateHeap(Heap* hp, DataType* array, int size);

//向下调整
void AdjustDown(Heap *hp,DataType parent);

//向上调整
void AdjustUp(Heap * hp,int child);

//交换函数
void swap(DataType *a,DataType* b);

// 在堆中插入值为data的元素
void InsertHeap(Heap* hp, DataType data);

//检测容量
void CheckCatacity(Heap *hp);

// 获取堆顶元素
DataType TopHeap(Heap* hp);

//打印堆中元素
void printDataType(Heap hp);

// 检测一个堆是否为空堆
int EmptyHeap(Heap* hp);

// 获取堆中元素的个数
int SizeHeap(Heap* hp);

// 删除堆顶元素
void DeleteHeap(Heap* hp);

// 销毁堆
void DestroyHeap(Heap* hp);
