/*
  题目：
  给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
  你可以假设除了数字 0 之外，这两个数字都不会以零开头。

  进阶:
  如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

  示例:
  输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
  输出: 7 -> 8 -> 0 -> 7

  题解：栈
  https://leetcode-cn.com/problems/add-two-numbers-ii/solution/lian-biao-liang-shu-xiang-jia-cpp-by-humbert/
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
    void list2stack(ListNode* h, stack<int>& stk){
        while(h!=NULL){    
            stk.push(h->val);            
            h = h->next;
        }        
    }        
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1; 
        stack<int> stk2;         
        list2stack(l1, stk1);
        list2stack(l2, stk2);
        
        ListNode head(-1);
        int carry = 0;
        while( !stk1.empty() || !stk2.empty() ){
            int val1 = 0;
            int val2 = 0;
            if( stk1.empty() ){
                val1 = 0;
            }else{
                val1 = stk1.top();
                stk1.pop();
            }            
            if( stk2.empty() ){
                val2 = 0;
            }else{
                val2 = stk2.top();
                stk2.pop();
            }
        
            int sum = val1 + val2 + carry;
            carry = sum >= 10 ? 1 : 0;
        
            ListNode* p = new ListNode(sum%10);
            p->next = head.next;
            head.next = p;                
        }
        if(carry == 1){
            ListNode* c = new ListNode(1);
            c->next = head.next;
            head.next = c;
        }
        
        return head.next;
    }
};
