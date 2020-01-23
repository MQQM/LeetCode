//仅为解法之一
/*
  题目：
  给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
  
  示例:
  输入: [-2,1,-3,4,-1,2,1,-5,4],
  输出: 6
  解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
  
  参考：
  https://www.cnblogs.com/jimmycheng/p/7204034.html
*/
const INT_MAX = int(^uint(0) >> 1)
const INT_MIN = ^INT_MAX
func maxSubArray(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	var sum float64 = 0
	var max_sum float64 = float64(INT_MIN)
	for i := 0; i < len(nums); i++ {
		sum = math.Max(float64(nums[i]), sum+float64(nums[i]))
		max_sum = math.Max(sum, max_sum)
	}
	return int(max_sum)
}
