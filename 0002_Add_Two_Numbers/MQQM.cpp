/*
  题目：
  给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
  如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
  您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

  示例：
  输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
  输出：7 -> 0 -> 8
  原因：342 + 465 = 807
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
    ListNode* gnrt_node(int sum, bool& plus1){       
        ListNode* tmp = NULL;
        if(sum >= 10){                  
            tmp = new ListNode(sum % 10);                        
            plus1 = true;                                             
        }else{
            tmp = new ListNode(sum);                                         
            plus1 = false;   
        }    
        return tmp;
    }    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }        
        //----------------
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* ret = new ListNode(-1);
        ListNode* tail = ret;
         
        bool plus1 = false;
        while(p1 != NULL || p2 != NULL){              
            if(p1 != NULL && p2 != NULL){                              
                int sum =  p1->val + p2->val + ( plus1==true ? 1 : 0 );      
                ListNode* tmp = gnrt_node(sum, plus1);                
                tail->next = tmp;                
                tail = tmp;  
                                   
                p1 = p1->next; 
                p2 = p2->next;
            }
            if(p1 != NULL && p2 == NULL){
                int sum =  p1->val + ( plus1==true ? 1 : 0 );  
                ListNode* tmp = gnrt_node(sum, plus1);                 
                tail->next = tmp;                
                tail = tmp;  
                                   
                p1 = p1->next;
            }
            if(p1 == NULL && p2 != NULL){
                int sum =  p2->val + ( plus1==true ? 1 : 0 ); 
                ListNode* tmp = gnrt_node(sum, plus1);                
                tail->next = tmp;                
                tail = tmp;                  
           
                p2 = p2->next;
            }                       
        }
        if(plus1 == true){
            ListNode* tmp = new ListNode(1);  
            tail->next = tmp;              
            tail = tmp;   
        }
        
        return ret->next;
    }
};
