#include "Hash.h"

//初始化
void HashTableInit(HashTable * ht)
{
	int i = 0;
	assert(ht);
	for(i=0; i<MAX_SIZE; ++i)
	{
		ht->_Table[i].data = 0;
		ht->_Table[i]._state = Empty;
	}
	ht->_size = 0;
	ht->_total = 0;
}

int HashFunc(DataType data)
{
	return data % MAX_SIZE;
}


//插入
void HashTableInsert(HashTable * ht,DataType data)
{
	int HashAddr = -1;      //记录计算的哈希地址
	int StartAddr = -1;     //开始插入第一个元素的地址
	assert(ht);
	if(MAX_SIZE == ht->_total)    
	{
		printf("已存满,不能继续存数据!!!\n");
		return;
	}
	
	HashAddr = HashFunc(data);
	StartAddr = HashAddr;
	while(ht->_total != MAX_SIZE)    //元素的个数小于容量
	{
		if(ht->_Table[HashAddr]._state != Exist) //要插入的位置状态 不为满(就是删除或者空)
		{
			if(ht->_Table[HashAddr]._state == Empty)  //状态为空,表示可以插入元素
			{
				ht->_Table[HashAddr].data = data;
				ht->_size += 1;
				ht->_total += 1;
				ht->_Table[HashAddr]._state = Exist;
				break;
			}
			//执行到这里说明状态为删除，这里不继续在向下找空间进行存元素，但是可以继续查找存
			//break;
		}
		if(ht->_Table[HashAddr].data == data && ht->_Table[HashAddr]._state != Delete)
		{
			printf("需要插入的元素存在,不能插入!!!\n");
				break;
		}
		HashAddr += 1;

		if(MAX_SIZE == HashAddr)
			HashAddr = 0;
		if(HashAddr == StartAddr)
			break;
	}
}

//删除
void HashTableDelete(HashTable * ht,DataType data)
{
	int ret = HashTableFind(ht,data);
		if(ret == -1)
			printf("没有找到要删除的元素!!!\n");
		else
		{
			ht->_Table[ret]._state = Delete;
			ht->_size -= 1;
		}
}

//查找
int HashTableFind(HashTable * ht,DataType data)
{
	int HashAddr = -1;
	int StartAddr = -1;

	assert(ht);
	HashAddr = HashFunc(data);
	StartAddr = HashAddr;

	while(ht->_size)
	{
		if(ht->_Table[HashAddr]._state != Empty)
		{
			if(ht->_Table[HashAddr]._state == Exist && ht->_Table[HashAddr].data == data)
			{
				return HashAddr;
			}
			HashAddr += 1;

			if(MAX_SIZE == HashAddr)
				HashAddr = 0;
			if(HashAddr == StartAddr)
				break;
		}
		if(ht->_Table[HashAddr]._state == Empty)
			break;
	}
	return -1;
}

//元素个数
int HashTableSize(HashTable * ht)
{
	assert(ht);
	return ht->_size;
}

//判空
int HashTableEmpty(HashTable * ht)
{
	assert(ht);
	return 0 == ht->_size;
}