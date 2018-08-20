#pragma once

#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include "BSTree.h"


typedef BSTNode* S_DataType;
#define MAX_SIZE 10

typedef struct Stact
{
	S_DataType _array[MAX_SIZE];
	int _size;
}Stack;


//ջ�ĳ�ʼ��
void StackInit(Stack *s);

//Ԫ����ջ
void StackPush(Stack *s,S_DataType data);

//��ջ
void StackPop(Stack *s);

//ջ��Ԫ��
S_DataType StackTop(Stack *s);

//ջԪ�صĸ���
int StackSize(Stack * s);

//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack * s);
