#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

//���еĴ���,���,ɾ��
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
	//HeapInit(&hp,Less); //��ʼ������

	//����С��
	CreateHeap(&hp,array,sizeof(array)/sizeof(array[0]),Less);

	//��ӡ����Ԫ��
	printHeap(hp);

	//���в���һ��Ԫ��
	InsertHeap(&hp,1);
	printHeap(hp);

	//ɾ���Ѷ�Ԫ��
	DeleteHeap(&hp);
	printHeap(hp);
}