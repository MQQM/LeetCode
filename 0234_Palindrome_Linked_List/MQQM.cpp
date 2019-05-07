/*
  题目：
  请判断一个链表是否为回文链表。

  示例 1:
  输入: 1->2
  输出: false
  
  示例 2:
  输入: 1->2->2->1
  输出: true

  进阶：
  你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

  做法：快慢指针。用两个指针找到最中间的节点，将后半部分链表反转，然后按照顺序，判断前后两部分各个节点的值是否相等。
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
    bool isPalindrome(ListNode* head){
      if(head == NULL || head->next == NULL){ // 空链表或链表只有一个节点
        return true;
      }
        
      ListNode *fast = head;
      ListNode *slow = head;
      while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
      }
    
      slow->next = reverseList(slow->next); // 将后半部分链表反转
      slow = slow->next;
    
      while(slow != NULL){
        if(head->val != slow->val)
            return false;
        head = head->next;
        slow = slow->next;
      }
      return true;
    }

  static ListNode* reverseList(ListNode *head){ // 反转链表
    ListNode *pre = NULL;
    ListNode *next = NULL;
    while(head != NULL){
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
  }
};
