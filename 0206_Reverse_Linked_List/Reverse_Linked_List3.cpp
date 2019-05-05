/*
  题目：
  反转一个单链表。
  
  示例:
  输入: 1->2->3->4->5->NULL
  输出: 5->4->3->2->1->NULL
  
  进阶:
  你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
  
  执行用时：28ms, 内存消耗：9.3MB。 
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){ // 空链表 
            return NULL;
        }
        
        ListNode* feakHead = new ListNode(0);
        feakHead->next = head;
        
        while(head->next != NULL){ // 只要head后还有节点，取一个插入至feakHead后。
            ListNode* p = head->next;
            head->next = p->next;
        
            p->next = feakHead->next;
            feakHead->next = p;
        }        
       
        return feakHead->next;             
    }
};
