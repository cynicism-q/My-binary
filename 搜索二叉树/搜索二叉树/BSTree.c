
#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void InitBSTree(BSTNode ** pRoot)
{
	assert(pRoot);

	*pRoot = NULL;
}

//插入值为Data的元素
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
			pParent = pCur;            //这里没有想清楚，pCur和pParent指向同一块内存空间，
			pCur = pCur->pLeft;        //pCur = pCur->pLeft,pParent->pLeft = pCur; 为什么不是呢
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
	
	//如果双亲的值大于它，则让双亲的左指针指向它
	if(pParent->_data > pCur->_data)
	{
		pParent->pLeft = pCur;
	}
	else
	{
		pParent->pRight = pCur;
	}
}

//递归
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
//删除值为data的结点
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
		
		//如果只有左孩子或者无右孩子
		if(NULL == pCur->pRight)
		{
			//如果是根节点的左孩子
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

		//如果只有右孩子
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

		//如果有两个孩子
		else
		{
			pParent = pCur;
			pDel = pCur->pRight;

			//查找右子树里面最左边的结点
			while(pDel->pLeft)
			{
				pParent = pDel;
				pDel = pDel->pLeft;
			}

			//找到了，替换
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

//删除值为data的结点
void DeleteBSTree(BSTNode ** pRoot,DataType data)
{
	BSTNode * pCur = NULL;
	BSTNode * pParent = NULL;
	assert(pRoot);
	//找带删除结点在二叉搜索树的位置

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

	//只有右孩子 || 叶子
	if(NULL == pCur->pLeft)
	{
		if(pCur == *pRoot)  //
		{
			*pRoot = pCur->pRight;
		}
		else
		{
			//检测带删除结点是其双亲的左
			if(pParent->pLeft == pCur)
				pParent->pLeft = pCur->pRight;
			else  	//检测带删除结点是其双亲的右
				pParent->pRight = pCur->pRight;
		}
	}
	else if(NULL == pCur->pRight)  //只有左孩子
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
		//左右孩子均存在
		//在右子树找最左侧(小)的结点

		BSTNode *pDel = pCur->pRight;  //d第一次不可能为空，因为左右子树都存在
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
			//只有右孩子 || 叶子结点
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


//查找递归
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

//查找非递归
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

//中序遍历递归
void InOrderD(BSTNode * pRoot)
{
	if(pRoot)
	{
		InOrderD(pRoot->pLeft);
		printf("%d ",pRoot->_data);
		InOrderD(pRoot->pRight);
	}
}

//非递归中序遍历
void InOrder(BSTNode * pRoot)
{
	BSTNode * pCur = NULL;
	Stack s;
	StackInit(&s);

	pCur = pRoot;

	if(NULL == pRoot)
	{
		printf("树为空!!!\n");
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


//创建一个新结点
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

// 递归销毁二叉搜索树
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