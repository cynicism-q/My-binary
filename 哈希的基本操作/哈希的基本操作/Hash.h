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
	int _size;                 //有效元素的个数,除去删除的
	int _total;					//元素的个数，包括删除的
}HashTable;

//哈希计算
int HashFunc(DataType data);

//初始化
void HashTableInit(HashTable * ht);

//插入
void HashTableInsert(HashTable * ht,DataType data);

//删除
void HashTableDelete(HashTable * ht,DataType data);

//查找
int HashTableFind(HashTable * ht,DataType data);

//元素个数
int HashTableSize(HashTable * ht);

//判空
int HashTableEmpty(HashTable * ht);



