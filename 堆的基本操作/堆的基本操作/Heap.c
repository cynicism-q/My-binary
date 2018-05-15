#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void InitHeap(Heap* hp)
{
	assert(hp);
	hp->_array = (DataType *)malloc(sizeof(DataType)*3);
}

//创建一个堆
void CreateHeap(Heap* hp, DataType* array, int size)
{
	int root = (size-1-1)>>1;
	int i = 0;
	assert(hp); 
	hp->_array = (DataType *)malloc(sizeof(DataType)*size);
	if(NULL == hp->_array)
	{
		printf("内存申请失败!!!\n");
		assert(0);
	}
	hp->_size = 0;
	hp->_capacity = size;

	//赋值
	for(i=0; i < size; ++i)
	{
		hp->_array[i] = array[i];
		hp->_size += 1;
	}

	//调整
	for(; root>=0; --root)
		AdjustDown(hp,root);
}

//向下调整
void AdjustDown(Heap *hp,DataType parent)
{
	int child = (parent<<1)+1;

	if(NULL == hp)
		return;

	while(child < hp->_size)
	{
		//找到两个孩子中最小的一个
		if(child+1 < hp->_size && hp->_array[child+1] < hp->_array[child])
		{
			child += 1;
		}
		//如果双亲大于孩子，则交换
		if(hp->_array[parent] > hp->_array[child])
		{
			swap(&hp->_array[parent],&hp->_array[child]);
			parent = child;                               //交换完毕后，再将孩子双亲,调整变动过的双亲结点
			child = (parent<<1)+1;                                                   
		}
		else
		{
			break;	
		}
	}
}

void swap(DataType *a,DataType* b)
{
	int ret = 0;
	ret = *a;
	*a = *b;
	*b = ret;
}

// 在堆中插入值为data的元素
void InsertHeap(Heap* hp, DataType data)
{
	if(NULL == hp)
		return;
	CheckCatacity(hp);
	hp->_array[hp->_size] = data;
	hp->_size++;

	if (hp->_size > 1)
		AdjustUp(hp, hp->_size - 1);
}

void AdjustUp(Heap * hp,int child)
{
	int parent = (child-1)>>1;
	while(child)
	{
		if(hp->_array[child] < hp->_array[parent])
		{
			swap(&hp->_array[child],&hp->_array[parent]);
			child = parent;
			parent = (child-1)>>1;
		}
		else
			break;	
	}	
}

//检测容量
void CheckCatacity(Heap *hp)
{
	int i = 0;
	DataType * pNewCatacity;
	assert(hp);
	if(hp->_size >= hp->_capacity)
	{
		pNewCatacity = (DataType *)malloc(sizeof(DataType)*2*hp->_capacity);
		assert(pNewCatacity);
		for(i=0; i<hp->_size; ++i)
		{
			pNewCatacity[i] = hp->_array[i];
		}
		free(hp->_array);
		hp->_array = pNewCatacity;
		hp->_capacity = (hp->_capacity)*2;
	}

}

//获取堆顶元素
DataType TopHeap(Heap* hp)
{
	assert(hp && hp->_size >= 1);
	return hp->_array[0];
}

//打印堆中元素
void printDataType(Heap hp)
{
	int i = 0;
	if(hp._size == 0)
		printf("堆为空,无元素打印!!!");
	for(i=0; i<hp._size; ++i)
	{
		printf("%d ",hp._array[i]);
	}
	printf("\n");
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
	assert(hp);
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

// 销毁堆
void DestroyHeap(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_capacity = 0;
	hp->_size = 0;
	hp->_array = NULL;
}
