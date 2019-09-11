/*
  题目：
  对链表进行插入排序。

  示例 1：
  输入: 4->2->1->3
  输出: 1->2->3->4

  示例 2：
  输入: -1->5->3->4->0
  输出: -1->0->3->4->5
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
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        { // 空链表 或 链表只有一个节点
            return head;
        }
        // 至少两个节点

        ListNode dummyhead(0);
        dummyhead.next = head;

        ListNode *q = dummyhead.next;
        ListNode *p = q->next;
        while (p != NULL)
        {
            if (q->val <= p->val)
            {
                q = p;
                p = p->next;
            }
            else
            {
                q->next = p->next;
                //----
                ListNode *dh = &dummyhead;
                ListNode *dh_n = dh->next;
                while (dh_n != NULL)
                {
                    if (p->val < dh_n->val)
                    {
                        dh->next = p;
                        p->next = dh_n;
                        break;
                    }
                    dh = dh_n;
                    dh_n = dh_n->next;
                }
                //----
                p = q->next;
            }
        }

        return dummyhead.next;
    }
};
