/*
  题目：
  给定一个单链表 L：L0→L1→…→Ln-1→Ln ，将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
  你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

  示例 1:
  给定链表 1->2->3->4, 重新排列为 1->4->2->3.
  示例 2:
  给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

  做法：用快门指针分成前后两段链表，将后半段链表反转，然后按照指定顺序排列。
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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* pr = slow->next;
        slow->next = NULL;
        pr = reverseList(pr);
        
        ListNode* pf = head; // front pointer 
        while(pf && pr){
            ListNode* pfNext = pf->next;
            ListNode* prNext = pr->next;
            
            pf->next = pr;
            pr->next = pfNext;
            
            pf = pfNext;
            pr = prNext;  
        }
    }
    
    ListNode* reverseList(ListNode* head){
        if(head==NULL || head->next == NULL){
            return head;
        }
        
        ListNode* h = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return h;        
    }
};
