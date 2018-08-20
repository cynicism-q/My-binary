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
	InsertBSTree(&pRoot,arr[i]);  //将元素插入搜索二叉树
	
	InsertBSTree(&pRoot,10);      //在插入10这个元素
	InOrderD(pRoot);			  //中序递归遍历

	printf("\n");
	InOrder(pRoot);				  //中序非递归遍历

	printf("%d\n",*BSTreeFind(pRoot,10));  //查找10这个元素

	DeleteBSTree(&pRoot,5);					//删除5
	printf("\n");
	InOrderD(pRoot);						//中序遍历
	
	DeleteBSTree(&pRoot,1);					//删除1和7
	DeleteBSTree(&pRoot,7);
	
	DestroyBSTreeD(&pRoot);					//销毁二叉树
}