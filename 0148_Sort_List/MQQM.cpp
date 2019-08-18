/*
  题目：
  在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

  示例 1:
  输入: 4->2->1->3
  输出: 1->2->3->4

  示例 2:
  输入: -1->5->3->4->0
  输出: -1->0->3->4->5

  题解参考：
  https://leetcode-cn.com/problems/sort-list/solution/148-pai-xu-lian-biao-bottom-to-up-o1-kong-jian-by-
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* cut(ListNode* head, int n) {
        auto p = head;
        while (--n && p) {
            p = p->next;
        }        
        if (!p){            
            return nullptr;
        }
        
        auto next = p->next;
        p->next = nullptr;
        return next;
    }    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        auto p = &dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;       
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }         
    ListNode* sortList(ListNode* head) {           
        auto p = head;
        int length = 0;
        while (p) {            
            ++length;
            p = p->next;
        }
        
        ListNode dummyHead(0);
        dummyHead.next = head;     
        for (int size = 1; size < length; size <<= 1) {
            auto cur = dummyHead.next;
            auto tail = &dummyHead;
            
            while (cur) {
                auto left = cur;
                auto right = cut(left, size); 
                cur = cut(right, size); 
                
                tail->next = merge(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        return dummyHead.next;
    }  
};
