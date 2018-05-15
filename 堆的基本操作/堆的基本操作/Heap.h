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

//�ѵĳ�ʼ��
void InitHeap(Heap* hp);

//����һ����
void CreateHeap(Heap* hp, DataType* array, int size);

//���µ���
void AdjustDown(Heap *hp,DataType parent);

//���ϵ���
void AdjustUp(Heap * hp,int child);

//��������
void swap(DataType *a,DataType* b);

// �ڶ��в���ֵΪdata��Ԫ��
void InsertHeap(Heap* hp, DataType data);

//�������
void CheckCatacity(Heap *hp);

// ��ȡ�Ѷ�Ԫ��
DataType TopHeap(Heap* hp);

//��ӡ����Ԫ��
void printDataType(Heap hp);

// ���һ�����Ƿ�Ϊ�ն�
int EmptyHeap(Heap* hp);

// ��ȡ����Ԫ�صĸ���
int SizeHeap(Heap* hp);

// ɾ���Ѷ�Ԫ��
void DeleteHeap(Heap* hp);

// ���ٶ�
void DestroyHeap(Heap* hp);
