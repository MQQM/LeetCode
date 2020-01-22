/*
  题目：
  将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
  
  示例：
  输入：1->2->4, 1->3->4
  输出：1->1->2->3->4->4
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	var dummyhead ListNode = ListNode{0, nil}
	var head *ListNode = &dummyhead

	var p1 *ListNode = l1
	var p2 *ListNode = l2
	for p1 != nil && p2 != nil {
		if p1.Val < p2.Val {
			head.Next = p1
			head = p1
			p1 = p1.Next
		} else {
			head.Next = p2
			head = p2
			p2 = p2.Next
		}
	}
	if p1 != nil {
		head.Next = p1
	}
	if p2 != nil {
		head.Next = p2
	}

	return dummyhead.Next
}
