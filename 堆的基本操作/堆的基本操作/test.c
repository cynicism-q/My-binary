#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void test();

int main()
{
	test();
	return 0;
}

void test()
{
	int array[] = {53,17,78,9,45,65,87,23,31};
	Heap hp;
    CreateHeap(&hp,array,sizeof(array)/sizeof(array[0]));//出现bug没有创建堆就进行添加元素

	//打印堆内数据
	printDataType(hp);

	//输出堆顶元素
	printf("堆顶元素为:%d\n",TopHeap(&hp));

	//出入元素1
	InsertHeap(&hp,1);        
	
	//打印堆顶元素
	printf("堆顶元素为:%d\n",TopHeap(&hp));

	//打印堆内元素
	printDataType(hp);

	//检测是否为空堆，1为是
	printf("检测是否为空堆 %d\n",EmptyHeap(&hp));

	printf("堆内有%d个元素\n",SizeHeap(&hp));

	//删除堆顶元素
	DeleteHeap(&hp);

	printDataType(hp);

	//销毁堆
	DestroyHeap(&hp);

	printDataType(hp);
}

