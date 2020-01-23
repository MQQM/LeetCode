/*
  题目：
  假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
  每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
  
  参考：
  https://blog.csdn.net/haimianxiaodao/article/details/52608536?utm_source=blogxgwz6
*/
func climbStairs(n int) int {
	if n <= 2 {
		return n
	}

	n1 := 1
	n2 := 2
	res := 0
	for i := 3; i <= n; i++ {
		res = n1 + n2
		n1 = n2
		n2 = res
	}
	return res
}
