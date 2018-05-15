#pragma once

#include <assert.h>
#include <stdio.h>
#include <malloc.h>

typedef int DataType;

//����ָ������
typedef int (*Compare)(DataType a,DataType b);

typedef struct Heap
{
	DataType * _array;     //����ָ��,����ָ��Ԫ�ش洢�Ŀռ�
	int _capacity;		   //����ռ�Ĵ�С
	int _size;			   //��ЧԪ�صĸ���
	Compare com;		   //����һ������ָ������
}Heap;

//�ѵĴ���
void CreateHeap(Heap * hp, DataType * array, int size,Compare com);

//�ѵĳ�ʼ��
void HeapInit(Heap * hp,Compare com);

//С��
int Less(DataType a,DataType b);

//���
int Great(DataType a,DataType b);

//���µ���
void AdjustDown(Heap * hp,int parent);

//���ϵ���
void  AdjustUp(Heap* hp,int child);

//����
void swap(int * a,int * b);

// �ڶ��в���ֵΪdata��Ԫ��
void InsertHeap(Heap* hp, DataType data);

//�������
void CheckCatacity(Heap *hp);

// ��ȡ�Ѷ�Ԫ��
DataType TopHeap(Heap* hp);

// ���һ�����Ƿ�Ϊ�ն�
int EmptyHeap(Heap* hp);

// ��ȡ����Ԫ�صĸ���
int SizeHeap(Heap* hp);

// ɾ���Ѷ�Ԫ��
void DeleteHeap(Heap* hp);

// ���ٶ�
void DestroyHeap(Heap* hp);

//��ӡ����Ԫ��
void printHeap(Heap hp);
