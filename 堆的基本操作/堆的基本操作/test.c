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
    CreateHeap(&hp,array,sizeof(array)/sizeof(array[0]));//����bugû�д����Ѿͽ������Ԫ��

	//��ӡ��������
	printDataType(hp);

	//����Ѷ�Ԫ��
	printf("�Ѷ�Ԫ��Ϊ:%d\n",TopHeap(&hp));

	//����Ԫ��1
	InsertHeap(&hp,1);        
	
	//��ӡ�Ѷ�Ԫ��
	printf("�Ѷ�Ԫ��Ϊ:%d\n",TopHeap(&hp));

	//��ӡ����Ԫ��
	printDataType(hp);

	//����Ƿ�Ϊ�նѣ�1Ϊ��
	printf("����Ƿ�Ϊ�ն� %d\n",EmptyHeap(&hp));

	printf("������%d��Ԫ��\n",SizeHeap(&hp));

	//ɾ���Ѷ�Ԫ��
	DeleteHeap(&hp);

	printDataType(hp);

	//���ٶ�
	DestroyHeap(&hp);

	printDataType(hp);
}

