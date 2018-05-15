#pragma once

#include <assert.h>
#include <stdio.h>
#include <malloc.h>

typedef int DataType;

//函数指针类型
typedef int (*Compare)(DataType a,DataType b);

typedef struct Heap
{
	DataType * _array;     //整形指针,用来指向元素存储的空间
	int _capacity;		   //上面空间的大小
	int _size;			   //有效元素的个数
	Compare com;		   //定义一个函数指针类型
}Heap;

//堆的创建
void CreateHeap(Heap * hp, DataType * array, int size,Compare com);

//堆的初始化
void HeapInit(Heap * hp,Compare com);

//小堆
int Less(DataType a,DataType b);

//大堆
int Great(DataType a,DataType b);

//向下调整
void AdjustDown(Heap * hp,int parent);

//向上调整
void  AdjustUp(Heap* hp,int child);

//交换
void swap(int * a,int * b);

// 在堆中插入值为data的元素
void InsertHeap(Heap* hp, DataType data);

//检测容量
void CheckCatacity(Heap *hp);

// 获取堆顶元素
DataType TopHeap(Heap* hp);

// 检测一个堆是否为空堆
int EmptyHeap(Heap* hp);

// 获取堆中元素的个数
int SizeHeap(Heap* hp);

// 删除堆顶元素
void DeleteHeap(Heap* hp);

// 销毁堆
void DestroyHeap(Heap* hp);

//打印堆中元素
void printHeap(Heap hp);
