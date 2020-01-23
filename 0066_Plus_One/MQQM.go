/*
  题目：
  给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
  你可以假设除了整数 0 之外，这个整数不会以零开头。
  
  示例 1:
  输入: [1,2,3]
  输出: [1,2,4]
  解释: 输入数组表示数字 123。
  
  示例 2:
  输入: [4,3,2,1]
  输出: [4,3,2,2]
  解释: 输入数组表示数字 4321。
*/
func plusOne(digits []int) []int {
	var plus1 bool = true
	
	idx := len(digits) - 1
	for plus1 && idx >= 0 {
		if digits[idx] == 9 {
			digits[idx] = 0
			plus1 = true
		} else {
			digits[idx] += 1
			plus1 = false
		}
		idx--
	}

	if plus1 {
		return append([]int{1}, digits...)
	}
	return digits
}
