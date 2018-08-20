#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void test();

int main()
{
	test();
	return 0;
}

void test()
{
	int arr[10] = {5,3,4,1,7,8,2,6,0,9};
	int i = 0;
	BSTNode * pRoot;
	InitBSTree(&pRoot);

	for(i=0; i< 10; i++)
	InsertBSTree(&pRoot,arr[i]);  //��Ԫ�ز�������������
	
	InsertBSTree(&pRoot,10);      //�ڲ���10���Ԫ��
	InOrderD(pRoot);			  //����ݹ����

	printf("\n");
	InOrder(pRoot);				  //����ǵݹ����

	printf("%d\n",*BSTreeFind(pRoot,10));  //����10���Ԫ��

	DeleteBSTree(&pRoot,5);					//ɾ��5
	printf("\n");
	InOrderD(pRoot);						//�������
	
	DeleteBSTree(&pRoot,1);					//ɾ��1��7
	DeleteBSTree(&pRoot,7);
	
	DestroyBSTreeD(&pRoot);					//���ٶ�����
}