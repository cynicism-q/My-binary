#include "Hash.h"

//��ʼ��
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


//����
void HashTableInsert(HashTable * ht,DataType data)
{
	int HashAddr = -1;      //��¼����Ĺ�ϣ��ַ
	int StartAddr = -1;     //��ʼ�����һ��Ԫ�صĵ�ַ
	assert(ht);
	if(MAX_SIZE == ht->_total)    
	{
		printf("�Ѵ���,���ܼ���������!!!\n");
		return;
	}
	
	HashAddr = HashFunc(data);
	StartAddr = HashAddr;
	while(ht->_total != MAX_SIZE)    //Ԫ�صĸ���С������
	{
		if(ht->_Table[HashAddr]._state != Exist) //Ҫ�����λ��״̬ ��Ϊ��(����ɾ�����߿�)
		{
			if(ht->_Table[HashAddr]._state == Empty)  //״̬Ϊ��,��ʾ���Բ���Ԫ��
			{
				ht->_Table[HashAddr].data = data;
				ht->_size += 1;
				ht->_total += 1;
				ht->_Table[HashAddr]._state = Exist;
				break;
			}
			//ִ�е�����˵��״̬Ϊɾ�������ﲻ�����������ҿռ���д�Ԫ�أ����ǿ��Լ������Ҵ�
			//break;
		}
		if(ht->_Table[HashAddr].data == data && ht->_Table[HashAddr]._state != Delete)
		{
			printf("��Ҫ�����Ԫ�ش���,���ܲ���!!!\n");
				break;
		}
		HashAddr += 1;

		if(MAX_SIZE == HashAddr)
			HashAddr = 0;
		if(HashAddr == StartAddr)
			break;
	}
}

//ɾ��
void HashTableDelete(HashTable * ht,DataType data)
{
	int ret = HashTableFind(ht,data);
		if(ret == -1)
			printf("û���ҵ�Ҫɾ����Ԫ��!!!\n");
		else
		{
			ht->_Table[ret]._state = Delete;
			ht->_size -= 1;
		}
}

//����
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

//Ԫ�ظ���
int HashTableSize(HashTable * ht)
{
	assert(ht);
	return ht->_size;
}

//�п�
int HashTableEmpty(HashTable * ht)
{
	assert(ht);
	return 0 == ht->_size;
}