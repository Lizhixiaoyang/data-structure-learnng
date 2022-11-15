#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

//1.����һ���������ͷ���pHead(��ͷ�ڵ�����ֵ�ģ���������ͼ������val��1)������Ϊn����ת������󣬷���������ı�ͷ��
/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 * };
 */

 /**
  *
  * @param pHead ListNode��
  * @return ListNode��
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

//2��һ���ڵ���Ϊ size ���� m λ�õ� n λ��֮������䷴ת��Ҫ��ʱ�临�Ӷ� O(n)O(n)���ռ临�Ӷ� O(1)O(1)��
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
 /**
  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
  *
  *
  * @param head ListNode��
  * @param m int����
  * @param n int����
  * @return ListNode��
  */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    // write code here
    if (head->next == NULL || head == NULL)
        return head;
    struct ListNode* H = malloc(sizeof(struct ListNode));
    H->next = head;
    struct ListNode* p, * temp, * cur = H;
    //��λ��ת����
    for (int i = 0; i < m - 1; i++)
    {
        cur = cur->next;
    }
    temp = cur;//�����ͷ���
    struct ListNode* q;
    cur = cur->next;//��ת�����һ���ڵ�
    q = cur;//���淴ת�����һ���ڵ�
    //ͷ�巨��ת����
    for (int i = 0; i < n - m + 1; i++)
    {
        p = cur;
        cur = cur->next;
        p->next = temp->next;
        temp->next = p;
    }
    q->next = cur;//��ת�����һ���ڵ���ԭ����ת�����ĵ�һ���ڵ�����
    return H->next;
}