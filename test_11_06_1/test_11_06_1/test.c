#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//1.请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
//typedef int QDataType;
//typedef struct QueueNode
//{
//	struct QueueNode* next;
//	QDataType data;
//}QNode;
//
//typedef struct Queue
//{
//	QNode* head;//方便头删
//	QNode* tail;//方便尾插
//	int size;
//}Queue;
//
//void QueueInit(Queue* pq);//或者QNode** pq
//
//void QueueDestroy(Queue* pq);
//
//void QueuePush(Queue* pq, QDataType x);
//
//void QueuePop(Queue* pq);
//
////取头部的数据
//QDataType QueueFront(Queue* pq);
//
////取尾部的数据
//QDataType QueueBack(Queue* pq);
//
//bool QueueEmpty(Queue* pq);
//int QueueSize(Queue* pq);
//
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->head = pq->tail = NULL;
//	pq->size = 0;
//}
//
//void QueueDestroy(Queue* pq)//释放掉链表
//{
//	assert(pq);
//	QNode* cur = pq->head;
//	while (cur)
//	{
//		QNode* del = cur;
//		cur = cur->next;
//		free(del);
//	}
//
//	pq->head = pq->tail = NULL;
//}
//
//void QueuePush(Queue* pq, QDataType x)
//{
//	assert(pq);
//	//只有一个接口，所以不用写BuyNode
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	if (newnode == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	else
//	{
//		newnode->data = x;
//		newnode->next = NULL;
//	}
//
//	if (pq->tail == NULL)
//	{
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//
//	pq->size++;
//}
//
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	if (pq->head->next == NULL)// 不单独处理的话，free的时候tail变成野指针了
//	{
//		free(pq->head);
//		pq->head = pq->tail = NULL;
//	}
//	else
//	{
//		QNode* del = pq->head;
//		pq->head = pq->head->next;
//
//		free(del);
//		del = NULL;
//	}
//
//	pq->size--;
//}
//
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	return pq->head->data;
//}
//
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	return pq->tail->data;
//}
//
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//
//	return pq->head == NULL && pq->tail == NULL;
//
//}
//
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//	/*QNode* cur = pq->head;
//	int n = 0;
//	while (cur)
//	{
//		++n;
//		cur = cur->next;
//	}
//
//	return n;*/
//	return pq->size;
//}
//
//
//typedef struct {
//	Queue q1;//定义成结构体而非指针
//	Queue q2;
//
//} MyStack;
//
//
//MyStack* myStackCreate() {
//	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
//	QueueInit(&obj->q1);
//	QueueInit(&obj->q2);
//	return obj;
//
//}
//
//void myStackPush(MyStack* obj, int x) {
//	if (!QueueEmpty(&obj->q1))
//	{
//		QueuePush(&obj->q1, x);
//	}
//	else
//	{
//		QueuePush(&obj->q2, x);
//	}
//
//}
//
//int myStackPop(MyStack* obj) {
//	Queue* empty = &obj->q1;
//	Queue* nonEmpty = &obj->q2;
//	if (!QueueEmpty(&obj->q1))
//	{
//		empty = &obj->q2;
//		nonEmpty = &obj->q1;
//	}
//	//非空队列前N-1个导入空队列，剩下一个就是栈顶元素
//	while (QueueSize(nonEmpty) > 1)
//	{
//		QueuePush(empty, QueueFront(nonEmpty));
//		QueuePop(nonEmpty);
//	}
//
//	int top = QueueFront(nonEmpty);
//	QueuePop(nonEmpty);
//	return top;
//}
//
//int myStackTop(MyStack* obj) {
//	if (!QueueEmpty(&obj->q1))
//	{
//		return QueueBack(&obj->q1);
//	}
//	else
//	{
//		return QueueBack(&obj->q2);
//	}
//
//}
//
//bool myStackEmpty(MyStack* obj) {
//	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj) {
//	QueueDestroy(&obj->q1);
//	QueueDestroy(&obj->q2);
//	free(obj);
//
//}
//
///**
// * Your MyStack struct will be instantiated and called as such:
// * MyStack* obj = myStackCreate();
// * myStackPush(obj, x);
//
// * int param_2 = myStackPop(obj);
//
// * int param_3 = myStackTop(obj);
//
// * bool param_4 = myStackEmpty(obj);
//
// * myStackFree(obj);
//*/






////2.请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty)
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//
//void StackInit(ST* ps);
//void StackDestroy(ST* ps);
//void StackPush(ST* ps, STDataType x);
//void StackPop(ST* ps);
//
//STDataType StackTop(ST* ps);
//bool StackEmpty(ST* ps);
//int StackSize(ST* ps);
//
//
//void StackInit(ST* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->top = ps->capacity = 0;
//}
//
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
//void StackPush(ST* ps, STDataType x)
//{
//	assert(ps);
//	// 
//	if (ps->top == ps->capacity)
//	{
//		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(ps->a, newCapacity * sizeof(STDataType));
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			exit(-1);
//		}
//
//		ps->a = tmp;
//		ps->capacity = newCapacity;
//	}
//
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//
//void StackPop(ST* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//
//	--ps->top;
//}
//
//STDataType StackTop(ST* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//
//	return ps->a[ps->top - 1];
//}
//
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//	return ps->top == 0;
//}
//int StackSize(ST* ps)
//{
//	assert(ps);
//
//	return ps->top;
//}
//
//typedef struct {
//	ST pushST;
//	ST popST;
//
//} MyQueue;
//
//
//MyQueue* myQueueCreate() {
//	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
//	StackInit(&obj->pushST);
//	StackInit(&obj->popST);
//
//	return obj;
//}
//
//void myQueuePush(MyQueue* obj, int x) {
//	StackPush(&obj->pushST, x);
//
//}
//
//void PushSTToPopST(MyQueue* obj)//把push的数据导到pop
//{
//	if (StackEmpty(&obj->popST))
//	{
//		while (!StackEmpty(&obj->pushST))
//		{
//			StackPush(&obj->popST, StackTop(&obj->pushST));
//			StackPop(&obj->pushST);
//		}
//	}
//}
//int myQueuePop(MyQueue* obj) {
//	PushSTToPopST(obj);
//	int front = StackTop(&obj->popST);
//	StackPop(&obj->popST);
//	return front;
//
//}
//
//int myQueuePeek(MyQueue* obj) {
//	PushSTToPopST(obj);
//	return StackTop(&obj->popST);
//}
//
//bool myQueueEmpty(MyQueue* obj) {
//	return StackEmpty(&obj->popST) && StackEmpty(&obj->pushST);
//
//}
//
//void myQueueFree(MyQueue* obj) {
//	StackDestroy(&obj->popST);
//	StackDestroy(&obj->pushST);
//	free(obj);
//
//}
//
///**
// * Your MyQueue struct will be instantiated and called as such:
// * MyQueue* obj = myQueueCreate();
// * myQueuePush(obj, x);
//
// * int param_2 = myQueuePop(obj);
//
// * int param_3 = myQueuePeek(obj);
//
// * bool param_4 = myQueueEmpty(obj);
//
// * myQueueFree(obj);
//*/





//3、设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
typedef struct {
    int* a;
    int front;
    int back;
    int N;

} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->a = (int*)malloc(sizeof(int) * (k + 1));
    obj->front = obj->back = 0;
    obj->N = k + 1;

    return obj;

}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->back;


}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->back + 1) % obj->N == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    obj->a[obj->back] = value;
    obj->back++;

    obj->back %= obj->N;
    return true;

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    obj->front++;
    obj->front %= obj->N;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else
        return obj->a[obj->front];



}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else if (obj->back == 0)
        return obj->a[obj->N - 1];
    else
        return obj->a[obj->back - 1];

}



void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);

}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/