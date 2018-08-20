#pragma once

typedef int DataType;

typedef struct BSTreeNode
{
	DataType _data;
	struct BSTreeNode * pLeft;
	struct BSTreeNode * pRight;
}BSTNode;

//��ʼ������������
void InitBSTree(BSTNode ** pRoot);

//����ֵΪData��Ԫ��
void InsertBSTree(BSTNode ** pRoot,DataType data);

//�ݹ����Ϊdata��Ԫ��
void InsertBSTreeD(BSTNode** pRoot,DataType data);

//ɾ��ֵΪdata�Ľ��
void DeleteBSTree(BSTNode ** pRoot,DataType data);

//ɾ���ݹ�
void DeleteBSTreeD(BSTNode ** pRoot,DataType data);

//���ҵݹ�
BSTNode * BSTreeFindD(BSTNode *pRoot, DataType data);

//���ҷǵݹ�
BSTNode * BSTreeFind(BSTNode *pRoot, DataType data);

//�������
void InOrderD(BSTNode * pRoot);

//�ǵݹ��������
void InOrder(BSTNode * pRoot);

//����һ���½��
BSTNode* BuyBSTNode(DataType data);

// ���ٶ���������
void DestroyBSTreeD(BSTNode** pRoot); 





