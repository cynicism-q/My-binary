#pragma once 

#include <assert.h>
#include <string.h>
#include <stdio.h>

typedef int DataType;

#define MAX_SIZE 10

typedef enum State
{	Empty,
	Exist,
	Delete
}State;

typedef struct Elem
{
	DataType data;
	State _state;
}Elem;

typedef struct HashTable
{
	Elem _Table[MAX_SIZE];
	int _size;                 //��ЧԪ�صĸ���,��ȥɾ����
	int _total;					//Ԫ�صĸ���������ɾ����
}HashTable;

//��ϣ����
int HashFunc(DataType data);

//��ʼ��
void HashTableInit(HashTable * ht);

//����
void HashTableInsert(HashTable * ht,DataType data);

//ɾ��
void HashTableDelete(HashTable * ht,DataType data);

//����
int HashTableFind(HashTable * ht,DataType data);

//Ԫ�ظ���
int HashTableSize(HashTable * ht);

//�п�
int HashTableEmpty(HashTable * ht);



