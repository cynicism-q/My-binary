
#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void InitBSTree(BSTNode ** pRoot)
{
	assert(pRoot);

	*pRoot = NULL;
}

//����ֵΪData��Ԫ��
void InsertBSTree(BSTNode ** pRoot,DataType data)
{
	BSTNode *pParent = NULL;
	BSTNode *pCur = NULL;

	assert(pRoot);

	if(NULL == *pRoot)
	{
		*pRoot = BuyBSTNode(data);
		return;
	}

	pCur = *pRoot;
	while(pCur)
	{
		if(pCur->_data > data)
		{
			pParent = pCur;            //����û���������pCur��pParentָ��ͬһ���ڴ�ռ䣬
			pCur = pCur->pLeft;        //pCur = pCur->pLeft,pParent->pLeft = pCur; Ϊʲô������
		}
		else if(pCur->_data < data)
		{
			pParent = pCur;
			pCur = pCur->pRight;
		}
		else
			return;
	}
	pCur = BuyBSTNode(data);
	
	//���˫�׵�ֵ������������˫�׵���ָ��ָ����
	if(pParent->_data > pCur->_data)
	{
		pParent->pLeft = pCur;
	}
	else
	{
		pParent->pRight = pCur;
	}
}

//�ݹ�
void InsertBSTreeD(BSTNode** pRoot,DataType data)
{
	assert(pRoot);
	if(NULL == *pRoot)
	{
		*pRoot = BuyBSTNode(data);
	}

	if((*pRoot)->_data > data)
		 InsertBSTreeD(&(*pRoot)->pLeft,data);
	else if((*pRoot)->_data < data)
		InsertBSTreeD(&(*pRoot)->pRight,data);
	else
		return;
}



#if 0
//ɾ��ֵΪdata�Ľ��
void DeleteBSTree(BSTNode ** pRoot,DataType data)
{
	BSTNode * pCur = NULL;
	BSTNode * pParent = NULL;
	BSTNode * pDel = NULL;

	assert(pRoot);

	if(NULL == *pRoot)
		return;

	pCur = *pRoot;

	while(pCur)
	{
		if(pCur->_data > data)
		{
			pParent = pCur;
			pCur = pCur->pLeft;
		}
		else if(pCur->_data < data)
		{
			pParent = pCur;
			pCur = pCur->pRight;
		}
		else
		{
			break;
		}
	}

	if(pCur)
	{
		pDel = pCur;
		
		//���ֻ�����ӻ������Һ���
		if(NULL == pCur->pRight)
		{
			//����Ǹ��ڵ������
			if((*pRoot)->pLeft == pCur)
				(*pRoot)->pLeft = pCur->pLeft;
			else
			{
				if(pParent->pLeft == pCur)
					pParent->pLeft = pCur->pLeft;
				else
					pParent->pRight = pCur->pLeft;
			}
		}

		//���ֻ���Һ���
		else if(pCur->pRight)
		{
			if((*pRoot)->pRight == pCur)
				(*pRoot)->pRight = pCur->pRight;
			else
			{
				if(pParent->pRight == pCur)
					pParent->pRight = pCur->pRight;
				else
					pParent->pLeft = pCur->pRight;
			}
		}

		//�������������
		else
		{
			pParent = pCur;
			pDel = pCur->pRight;

			//������������������ߵĽ��
			while(pDel->pLeft)
			{
				pParent = pDel;
				pDel = pDel->pLeft;
			}

			//�ҵ��ˣ��滻
			pCur->_data = pDel->_data;

			if(pParent->pLeft == pDel)
				pParent->pLeft = pDel->pRight;
			else
				pParent->pRight = pDel->pRight;
		}
		free(pDel);
		pDel = NULL;
	}
}
#endif

//ɾ��ֵΪdata�Ľ��
void DeleteBSTree(BSTNode ** pRoot,DataType data)
{
	BSTNode * pCur = NULL;
	BSTNode * pParent = NULL;
	assert(pRoot);
	//�Ҵ�ɾ������ڶ�����������λ��

	pCur = *pRoot;
	
	while(pCur)
	{
		if(data == pCur->_data)
		{
			break;
		}
		else if(data < pCur->_data)
		{
			pParent = pCur;
			pCur = pCur->pLeft;
		}
		else
		{
			pParent = pCur;
			pCur = pCur->pRight;
		}
	}

	if(NULL == pCur)
		return;

	//ֻ���Һ��� || Ҷ��
	if(NULL == pCur->pLeft)
	{
		if(pCur == *pRoot)  //
		{
			*pRoot = pCur->pRight;
		}
		else
		{
			//����ɾ���������˫�׵���
			if(pParent->pLeft == pCur)
				pParent->pLeft = pCur->pRight;
			else  	//����ɾ���������˫�׵���
				pParent->pRight = pCur->pRight;
		}
	}
	else if(NULL == pCur->pRight)  //ֻ������
	{
		if(pCur == *pRoot)
			*pRoot = pCur->pLeft;
		else
		{
			if(pParent->pLeft == pCur)
				pParent->pLeft = pCur->pLeft;
			else
				pParent->pRight = pCur->pLeft;
		}
	}
	else
	{
		//���Һ��Ӿ�����
		//���������������(С)�Ľ��

		BSTNode *pDel = pCur->pRight;  //d��һ�β�����Ϊ�գ���Ϊ��������������
		pParent = pCur;
		while(pDel->pLeft)
		{
			pParent = pDel;
			pDel = pDel->pLeft;
		}

		pCur->_data = pDel->_data;

		if(pDel == pParent->pLeft)
			pParent->pLeft = pDel->pRight;
		else
			pParent->pRight = pDel->pRight;

		pCur = pDel;
	}
	free(pCur);
}

void DeleteBSTreeD(BSTNode ** pRoot,DataType data)
{
	assert(pRoot);
	if(NULL == *pRoot)
		return;
	else
	{
		if(data < (*pRoot)->_data)
			DeleteBSTree(&(*pRoot)->pLeft,data);
		else if(data > (*pRoot)->_data)
			DeleteBSTree(&(*pRoot)->pRight,data);
		else
		{
			//ֻ���Һ��� || Ҷ�ӽ��
			BSTNode * pDel = *pRoot;
			if(NULL ==(*pRoot)->pLeft)
			{
				*pRoot = pDel->pRight;
				free(pDel);
			}
			else if(NULL ==pDel->pRight)
			{
				*pRoot = pDel->pLeft;
				free(pDel);
			}
			else
			{
				pDel = (*pRoot)->pRight;
				while(pDel->pLeft)
					pDel = pDel->pLeft;
				(*pRoot)->_data = pDel->_data;

				DeleteBSTree(&(*pRoot)->pRight,pDel->_data);
			}

		}
	}
}


//���ҵݹ�
BSTNode * BSTreeFindD(BSTNode *pRoot, DataType data)
{
	if(NULL == pRoot)
		return NULL;
	else
	{
		if(data == pRoot->_data)
			return pRoot;
		else if(data < pRoot->_data)
			return BSTreeFind(pRoot->pLeft,data);
		else
			return BSTreeFind(pRoot->pRight,data);
	}
}

//���ҷǵݹ�
BSTNode * BSTreeFind(BSTNode *pRoot, DataType data)
{
	if(NULL == pRoot)
		return NULL;
	while(pRoot)
	{
		if(data == pRoot->_data)
			return pRoot;
		else
		{
			if(data > pRoot->_data)
				pRoot = pRoot->pRight;
			else
				pRoot = pRoot->pLeft;
		}
	}
	return NULL;
}

//��������ݹ�
void InOrderD(BSTNode * pRoot)
{
	if(pRoot)
	{
		InOrderD(pRoot->pLeft);
		printf("%d ",pRoot->_data);
		InOrderD(pRoot->pRight);
	}
}

//�ǵݹ��������
void InOrder(BSTNode * pRoot)
{
	BSTNode * pCur = NULL;
	Stack s;
	StackInit(&s);

	pCur = pRoot;

	if(NULL == pRoot)
	{
		printf("��Ϊ��!!!\n");
		return;
	}
	while(pCur || !StackEmpty(&s))
	{
		while(pCur)
		{
			StackPush(&s,pCur);
			pCur = pCur->pLeft;
		}
		if(!StackEmpty(&s))
		{
			pCur = StackTop(&s);
			printf("%d ",pCur->_data);
			pCur = pCur->pRight;
			StackPop(&s);
		}
	}
}


//����һ���½��
BSTNode* BuyBSTNode(DataType data)
{
	BSTNode * pNewNode = (BSTNode *)malloc(sizeof(BSTNode));

	if(NULL == pNewNode)
	{
		assert(0);
	}
	pNewNode->_data = data;
	pNewNode->pRight = NULL;
	pNewNode->pLeft = NULL;

	return pNewNode;
}

// �ݹ����ٶ���������
void DestroyBSTreeD(BSTNode** pRoot)
{
	assert(pRoot);

	if(NULL == *pRoot)
		return;
	if(NULL != (*pRoot)->pLeft)
		DestroyBSTreeD(&(*pRoot)->pLeft);

	if(NULL != (*pRoot)->pRight)
		DestroyBSTreeD(&(*pRoot)->pRight);

	free(*pRoot);
	*pRoot = NULL;
}