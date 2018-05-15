#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

//创建堆
void CreateHeap(Heap * hp, int * array, int size,Compare com)
{
	int i = 0;
	int Root = 0;
	assert(hp);
	hp->_array = (DataType *)malloc(sizeof(DataType)*size);
	if(NULL == hp->_array)
	{
		printf("内存申请失败!!!\n");
		assert(0);
	}

	hp->_size = 0;
	hp->_capacity = size;
	hp->com = com;

	//赋值
	for(i=0; i< size; ++i)
	{
		hp->_array[i] = array[i];
		hp->_size += 1;
	}

	//找出最后一个非叶子结点
	Root = (size-1) >> 1;

	for(; Root >= 0; --Root)
		AdjustDown(hp,Root);
}

//向下调整
void AdjustDown(Heap * hp,int parent)
{
	int child = (parent << 1) + 1;
	assert(hp);

	while(child < hp->_size)
	{
		if(child+1 < hp->_size && hp->com(hp->_array[child+1],hp->_array[child]))
		{
			child += 1;
		}

		if(hp->com(hp->_array[child],hp->_array[parent]))
		{
			swap(&hp->_array[parent],&hp->_array[child]);
			parent = child;
			child = (parent+1) << 1;
		}	
		else
		{
			break;
		}
	}
}

//堆的初始化    
void HeapInit(Heap * hp,Compare com)
{
	assert(hp);
	hp->_array = (DataType *)malloc(sizeof(DataType)*3);   ////////////////////////
	if(NULL == hp->_array)
	{
		printf("内存申请失败!!!\n");
		assert(0);
	}
	hp->_size = 0;
	hp->com = com;
	hp->_capacity = 3;
}

// 在堆中插入值为data的元素
void InsertHeap(Heap* hp, DataType data)
{
	assert(hp);
	CheckCatacity(hp);
	hp->_array[hp->_size] = data;
	hp->_size += 1;

	if(hp->_size>1)
		AdjustUp(hp,hp->_size-1);
}

//向上调整
void  AdjustUp(Heap* hp,int child)
{
	int parent = (child-1) >> 1;
	while(child)
	{
		if(hp->com(hp->_array[child],hp->_array[parent]))
		{
			swap(&hp->_array[parent],&hp->_array[child]);
			child = parent;
			parent = (child-1) >> 1;
		}
		else
			break;
	}
}

//检测容量
void CheckCatacity(Heap *hp)
{
	int i=0;
	DataType * NewCatacity;
	assert(hp);

	if(hp->_size >= hp->_capacity)
	{
		NewCatacity = (DataType*)malloc(sizeof(DataType)*hp->_capacity*2);
		assert(NewCatacity);
		for(i=0; i < hp->_size; ++i)
		{
			NewCatacity[i] = hp->_array[i];
		}

			free(hp->_array);
			hp->_array = NewCatacity;
			hp->_capacity = 2*hp->_capacity;
	}
}

//小堆
int Less(int a,int b)
{
	return a < b;
}

//大堆
int Great(int a,int b)
{
	return a > b;
}

//交换
void swap(int * a,int * b)
{
	int ret = 0;
	ret = *a;
	*a = *b;
	*b = ret;
}

// 获取堆顶元素
DataType TopHeap(Heap* hp)
{
	assert(hp && hp->_size >= 1);
	return hp->_array[0];
}

// 检测一个堆是否为空堆
int EmptyHeap(Heap* hp)
{
	assert(hp);
	return 0 == hp->_size;
}

// 获取堆中元素的个数
int SizeHeap(Heap* hp)
{
	return hp->_size;
}

// 删除堆顶元素
void DeleteHeap(Heap* hp)
{
	assert(hp);
	swap(&hp->_array[0],&hp->_array[hp->_size-1]);
	hp->_size -= 1;
	AdjustDown(hp,0);
}

//打印堆内元素
void printHeap(Heap hp)
{
	int i = 0;
	for(i=0; i<hp._size; ++i)
	{
		printf("%d ",hp._array[i]);
	}
	printf("\n");
}


// 销毁堆
void DestroyHeap(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}

