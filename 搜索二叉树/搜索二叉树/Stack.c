#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void StackInit(Stack * s)
{
	assert(s);
	s->_size = 0;
}
void StackPush(Stack *s,S_DataType data)
{
	assert(s);
	if(s->_size == MAX_SIZE)
	{
		printf("ջ����,������Ԫ��!!!\n");
		return;
	}
	s->_array[s->_size++] = data;


}
void StackPop(Stack *s)
{
	assert(s);
	if(StackEmpty(s))
	{
		printf("ջ�Կ�,���ܳ�Ԫ��!!!\n");
		return;
	}
	--s->_size;
	
}
S_DataType StackTop(Stack *s)
{
	assert(s);
	if(MAX_SIZE == 0)
	{
		printf("ջΪ��,��ջ��Ԫ��!!!\n");
		assert(0);
	}
	return s->_array[s->_size-1];
}
int StackSize(Stack * s)
{
	assert(s);
	return s->_size;
}
int StackEmpty(Stack * s)
{
	assert(s);
	return 0 == s->_size;
}