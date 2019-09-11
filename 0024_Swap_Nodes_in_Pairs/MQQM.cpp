/*
  题目：
  给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
  你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

  示例:
  给定 1->2->3->4, 你应该返回 2->1->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode dummyhead(-1);
        dummyhead.next = head;
        ListNode *h = &dummyhead;
        ListNode *p1 = head;
        ListNode *p2 = p1->next;
        ListNode *p3 = p2->next;

        while (p1 != NULL && p2 != NULL)
        {
            h->next = p2;
            p2->next = p1;
            p1->next = p3;
            if (p3 == NULL || p3->next == NULL)
            {
                break;
            }
            h = p1;
            p1 = p3;
            p2 = p1->next;
            p3 = p2->next;
        }

        return dummyhead.next;
    }
};
