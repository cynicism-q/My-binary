#pragma once

typedef int DataType;

typedef struct BSTreeNode
{
	DataType _data;
	struct BSTreeNode * pLeft;
	struct BSTreeNode * pRight;
}BSTNode;

//初始化二叉搜索树
void InitBSTree(BSTNode ** pRoot);

//插入值为Data的元素
void InsertBSTree(BSTNode ** pRoot,DataType data);

//递归插入为data的元素
void InsertBSTreeD(BSTNode** pRoot,DataType data);

//删除值为data的结点
void DeleteBSTree(BSTNode ** pRoot,DataType data);

//删除递归
void DeleteBSTreeD(BSTNode ** pRoot,DataType data);

//查找递归
BSTNode * BSTreeFindD(BSTNode *pRoot, DataType data);

//查找非递归
BSTNode * BSTreeFind(BSTNode *pRoot, DataType data);

//中序遍历
void InOrderD(BSTNode * pRoot);

//非递归中序遍历
void InOrder(BSTNode * pRoot);

//创建一个新结点
BSTNode* BuyBSTNode(DataType data);

// 销毁二叉搜索树
void DestroyBSTreeD(BSTNode** pRoot); 





