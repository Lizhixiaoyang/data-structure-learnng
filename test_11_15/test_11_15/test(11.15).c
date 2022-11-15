#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

//1.给定一个单链表的头结点pHead(该头节点是有值的，比如在下图，它的val是1)，长度为n，反转该链表后，返回新链表的表头。
/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 * };
 */

 /**
  *
  * @param pHead ListNode类
  * @return ListNode类
  */
struct ListNode* ReverseList(struct ListNode* pHead) {
    struct ListNode* cur = pHead, * newhead = NULL;
    while (cur)
    {
        struct ListNode* next = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = next;

    }

    return newhead;
    if (cur == NULL)
    {
        return NULL;
    }


}

//2将一个节点数为 size 链表 m 位置到 n 位置之间的区间反转，要求时间复杂度 O(n)O(n)，空间复杂度 O(1)O(1)。
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
 /**
  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
  *
  *
  * @param head ListNode类
  * @param m int整型
  * @param n int整型
  * @return ListNode类
  */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    // write code here
    if (head->next == NULL || head == NULL)
        return head;
    struct ListNode* H = malloc(sizeof(struct ListNode));
    H->next = head;
    struct ListNode* p, * temp, * cur = H;
    //定位反转区间
    for (int i = 0; i < m - 1; i++)
    {
        cur = cur->next;
    }
    temp = cur;//区间的头结点
    struct ListNode* q;
    cur = cur->next;//反转区间第一个节点
    q = cur;//保存反转区间第一个节点
    //头插法反转链表
    for (int i = 0; i < n - m + 1; i++)
    {
        p = cur;
        cur = cur->next;
        p->next = temp->next;
        temp->next = p;
    }
    q->next = cur;//反转区间第一个节点与原链表反转区间后的第一个节点相连
    return H->next;
}