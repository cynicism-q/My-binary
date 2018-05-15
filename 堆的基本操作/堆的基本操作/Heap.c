#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void InitHeap(Heap* hp)
{
	assert(hp);
	hp->_array = (DataType *)malloc(sizeof(DataType)*3);
}

//����һ����
void CreateHeap(Heap* hp, DataType* array, int size)
{
	int root = (size-1-1)>>1;
	int i = 0;
	assert(hp); 
	hp->_array = (DataType *)malloc(sizeof(DataType)*size);
	if(NULL == hp->_array)
	{
		printf("�ڴ�����ʧ��!!!\n");
		assert(0);
	}
	hp->_size = 0;
	hp->_capacity = size;

	//��ֵ
	for(i=0; i < size; ++i)
	{
		hp->_array[i] = array[i];
		hp->_size += 1;
	}

	//����
	for(; root>=0; --root)
		AdjustDown(hp,root);
}

//���µ���
void AdjustDown(Heap *hp,DataType parent)
{
	int child = (parent<<1)+1;

	if(NULL == hp)
		return;

	while(child < hp->_size)
	{
		//�ҵ�������������С��һ��
		if(child+1 < hp->_size && hp->_array[child+1] < hp->_array[child])
		{
			child += 1;
		}
		//���˫�״��ں��ӣ��򽻻�
		if(hp->_array[parent] > hp->_array[child])
		{
			swap(&hp->_array[parent],&hp->_array[child]);
			parent = child;                               //������Ϻ��ٽ�����˫��,�����䶯����˫�׽��
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

// �ڶ��в���ֵΪdata��Ԫ��
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

//�������
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

//��ȡ�Ѷ�Ԫ��
DataType TopHeap(Heap* hp)
{
	assert(hp && hp->_size >= 1);
	return hp->_array[0];
}

//��ӡ����Ԫ��
void printDataType(Heap hp)
{
	int i = 0;
	if(hp._size == 0)
		printf("��Ϊ��,��Ԫ�ش�ӡ!!!");
	for(i=0; i<hp._size; ++i)
	{
		printf("%d ",hp._array[i]);
	}
	printf("\n");
}

// ���һ�����Ƿ�Ϊ�ն�
int EmptyHeap(Heap* hp)
{
	assert(hp);
	return 0 == hp->_size;
}

// ��ȡ����Ԫ�صĸ���
int SizeHeap(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

// ɾ���Ѷ�Ԫ��
void DeleteHeap(Heap* hp)
{
	assert(hp);
	swap(&hp->_array[0],&hp->_array[hp->_size-1]);
	hp->_size -= 1;
	AdjustDown(hp,0);
}

// ���ٶ�
void DestroyHeap(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_capacity = 0;
	hp->_size = 0;
	hp->_array = NULL;
}
