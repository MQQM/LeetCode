/*
  题目：
  给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
  你应当保留两个分区中每个节点的初始相对位置。

  示例:
  输入: head = 1->4->3->2->5->2, x = 3
  输出: 1->2->2->4->3->5
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode dummyhead1(0);
        ListNode dummyhead2(0);
        ListNode *dh1 = &dummyhead1;
        ListNode *dh2 = &dummyhead2;

        for (ListNode *p = head; p != NULL;)
        {
            ListNode *pp = p->next;

            p->next = NULL;
            if (p->val < x)
            {
                dh1->next = p;
                dh1 = p;
            }
            else
            {
                dh2->next = p;
                dh2 = p;
            }

            p = pp;
        }
        
        dh1->next = dummyhead2.next;
        return dummyhead1.next;
    }
};
