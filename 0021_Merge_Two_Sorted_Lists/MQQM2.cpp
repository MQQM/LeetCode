/*
  题目：
  将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

  示例：
  输入：1->2->4, 1->3->4
  输出：1->1->2->3->4->4
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode dummyhead(0);
        ListNode *head = &dummyhead;

        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while (p1 != NULL && p2 != NULL)
        {
            if (p1->val < p2->val)
            {
                head->next = p1;
                head = p1;
                p1 = p1->next;
            }
            else
            {
                head->next = p2;
                head = p2;
                p2 = p2->next;
            }
        }
        if (p1 != NULL)
        {
            head->next = p1;
        }
        if (p2 != NULL)
        {
            head->next = p2;
        }

        return dummyhead.next;
    }
};
