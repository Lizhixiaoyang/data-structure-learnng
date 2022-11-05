#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"


//初始化
void SLInit(SL* psl)
{
	assert(psl);
	psl->a = NULL;
	psl->a = psl->capacity;
}

//打印
void SLPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d", psl->a[psl->size]);
	}
	printf("\n");
}

//制造一个检查内存空间的函数，一劳永逸
CheckCapacity(SL* psl)
{
	if (psl->size == psl->capacity)
	{
		int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType tmp =(SLDataType*)realloc(psl->a, (newCapacity) * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		psl->a = tmp;
		psl->capacity = newCapacity;
	}

}

//头插
void SLPushFront(SL* psl, SLDataType x)
{
	CheckCapacity(psl);
	int end = psl->size - 1;
	while (end >= 0)
	{
		psl->a[end + 1] = psl->a[end];
		--end;
	}
	psl->a[0] = x;
	psl->size++;
}

//头删
void SLPopFront(SL* psl)
{
	assert(psl);
	assert(psl->size);
	int begin = 1;
	while (begin < psl->size)
	{
		psl->a[begin - 1] = psl->a[begin];
		++begin;
	}
	--psl->size;
	
}

//尾插
void SLPushBack(SL* psl, SLDataType x)
{
	CheckCapacity(psl);
	int end = psl->size;
	psl->a[end] = x;
	psl->size++;
}


//尾删
void SLPopBack(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);
	psl->size--;
}


// 顺序表查找
int SLFind(SL* psl, SLDataType x)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
		{
			return i;
		}
		return -1;
	}
}


// 顺序表在pos位置插入x
void SLInsert(SL* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(psl->size);
	CheckCapacity(psl);
	size_t end = psl->size;
	while (end >= pos)//等于时相当于尾插
	{
		psl->a[end] = psl->a[end-1];
		--end;
	}
	psl->a[pos] = x;
	psl->size++;
}

// 顺序表删除pos位置的值
void SLErase(SL* psl, size_t pos)
{
	assert(psl);
	assert(pos<=psl->size);
	size_t begin = psl->a[0];
	while (begin <= pos)//等于时相当于尾插
	{
		psl->a[begin] = psl->a[begin+1];
		++begin;
	}
	psl->size--;
}

// 顺序表销毁
void SLDestory(SL* psl)
{
	assert(psl);
	
	free(psl->a);
	psl->a = NULL;
	psl->capacity = psl->size = 0;
	
}

//修改
void SLModify(SL* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(pos < psl->size);
	psl->a[pos] = x;
}