#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

//队列的创建,添加,删除
void test();

int main()
{
	test();
	return 0;
}

void test()
{
	Heap hp;
	DataType array[] = {53,17,78,9,45,65,87,23,31};
	//HeapInit(&hp,Less); //初始化程序

	//创建小堆
	CreateHeap(&hp,array,sizeof(array)/sizeof(array[0]),Less);

	//打印堆中元素
	printHeap(hp);

	//堆中插入一个元素
	InsertHeap(&hp,1);
	printHeap(hp);

	//删除堆顶元素
	DeleteHeap(&hp);
	printHeap(hp);
}