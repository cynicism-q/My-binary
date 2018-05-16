#include "Hash.h"

void test();

int main()
{
	test();
	return 0;
}

void test()
{
	HashTable ht;
	int ret = 0;
	HashTableInit(&ht);
	HashTableInsert(&ht,0);
	HashTableInsert(&ht,1);
	HashTableInsert(&ht,2);
	HashTableInsert(&ht,3);
	HashTableInsert(&ht,4);
	HashTableInsert(&ht,5);
	HashTableInsert(&ht,6);
	HashTableInsert(&ht,7);
	//HashTableInsert(&ht,8);
	HashTableInsert(&ht,9);

	HashTableDelete(&ht,9);
	HashTableInsert(&ht,9);
	//HashTableInsert(&ht,99);

	

	printf("需要查找元素的下标为:%d \n",HashTableFind(&ht,9));

	printf("元素的个数为:%d\n",HashTableSize(&ht));

	if(!HashTableEmpty(&ht))
	{
		printf("不为空!!!\n");
	}
	else
		printf("为空!!!\n");



}