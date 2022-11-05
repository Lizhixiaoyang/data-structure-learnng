#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<assert.h>

//先定一个类型，方便后续更改
typedef int SLDataType;
//先建一个顺序表
typedef struct SeqList
{
	SLDataType* a;
	size_t size;
	size_t capacity;
}SL;



//初始化
void SLInit(SL* psl);

//打印
void SLPrint(SL* psl);


//头插
void SLPushFront(SL* psl, SLDataType x);
//头删
void SLPopFront(SL* psl);

//尾插
void SLPushBack(SL* psl,SLDataType x);
//尾删
void SLPopBack(SL* psl);


// 顺序表查找
int SLFind(SL* psl, SLDataType x);

// 顺序表在pos位置插入x
void SLInsert(SL* psl, size_t pos, SLDataType x);

// 顺序表删除pos位置的值
void SLErase(SL* psl, size_t pos);

// 顺序表销毁
void SLDestory(SL* psl);

//修改
void SLModify(SL* psl, size_t pos, SLDataType x);


