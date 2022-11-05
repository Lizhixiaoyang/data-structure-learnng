#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"


//��ʼ��
void SLInit(SL* psl)
{
	assert(psl);
	psl->a = NULL;
	psl->a = psl->capacity;
}

//��ӡ
void SLPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d", psl->a[psl->size]);
	}
	printf("\n");
}

//����һ������ڴ�ռ�ĺ�����һ������
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

//ͷ��
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

//ͷɾ
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

//β��
void SLPushBack(SL* psl, SLDataType x)
{
	CheckCapacity(psl);
	int end = psl->size;
	psl->a[end] = x;
	psl->size++;
}


//βɾ
void SLPopBack(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);
	psl->size--;
}


// ˳������
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


// ˳�����posλ�ò���x
void SLInsert(SL* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(psl->size);
	CheckCapacity(psl);
	size_t end = psl->size;
	while (end >= pos)//����ʱ�൱��β��
	{
		psl->a[end] = psl->a[end-1];
		--end;
	}
	psl->a[pos] = x;
	psl->size++;
}

// ˳���ɾ��posλ�õ�ֵ
void SLErase(SL* psl, size_t pos)
{
	assert(psl);
	assert(pos<=psl->size);
	size_t begin = psl->a[0];
	while (begin <= pos)//����ʱ�൱��β��
	{
		psl->a[begin] = psl->a[begin+1];
		++begin;
	}
	psl->size--;
}

// ˳�������
void SLDestory(SL* psl)
{
	assert(psl);
	
	free(psl->a);
	psl->a = NULL;
	psl->capacity = psl->size = 0;
	
}

//�޸�
void SLModify(SL* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(pos < psl->size);
	psl->a[pos] = x;
}