#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<assert.h>

//�ȶ�һ�����ͣ������������
typedef int SLDataType;
//�Ƚ�һ��˳���
typedef struct SeqList
{
	SLDataType* a;
	size_t size;
	size_t capacity;
}SL;



//��ʼ��
void SLInit(SL* psl);

//��ӡ
void SLPrint(SL* psl);


//ͷ��
void SLPushFront(SL* psl, SLDataType x);
//ͷɾ
void SLPopFront(SL* psl);

//β��
void SLPushBack(SL* psl,SLDataType x);
//βɾ
void SLPopBack(SL* psl);


// ˳������
int SLFind(SL* psl, SLDataType x);

// ˳�����posλ�ò���x
void SLInsert(SL* psl, size_t pos, SLDataType x);

// ˳���ɾ��posλ�õ�ֵ
void SLErase(SL* psl, size_t pos);

// ˳�������
void SLDestory(SL* psl);

//�޸�
void SLModify(SL* psl, size_t pos, SLDataType x);


