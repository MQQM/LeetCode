/*
  题目：
  给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
  
  注意:
  假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
*/
func reverse(x int) int {
	res := 0
  
	for x != 0 {
		g := x % 10
		res = res*10 + g
		x /= 10
	}
  
	if res > math.MaxInt32 || res < math.MinInt32 {
		res = 0
	}
  
	return res
}
