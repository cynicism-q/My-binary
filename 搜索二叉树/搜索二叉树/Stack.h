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


//栈的初始化
void StackInit(Stack *s);

//元素入栈
void StackPush(Stack *s,S_DataType data);

//出栈
void StackPop(Stack *s);

//栈顶元素
S_DataType StackTop(Stack *s);

//栈元素的个数
int StackSize(Stack * s);

//判断栈是否为空
int StackEmpty(Stack * s);
