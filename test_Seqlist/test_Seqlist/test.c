#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

//����ͷ��
void test1()
{
	SL s;
	SLInit(&s);
	SLPushFront(&s, 10);
	SLPushFront(&s, 20);
	SLPushFront(&s, 30);
	SLPrint(&s);
}


//����β��
void test2()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 10);
	SLPushBack(&s, 20);
	SLPushBack(&s, 30);

	SLPrint(&s);
}




int main()
{
	
	test1();
	test2();

	return 0;
}