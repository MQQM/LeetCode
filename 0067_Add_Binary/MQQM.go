/*
  题目：
  给定两个二进制字符串，返回他们的和（用二进制表示）。
  输入为非空字符串且只包含数字 1 和 0。

  示例 1:
  输入: a = "11", b = "1"
  输出: "100"

  示例 2:
  输入: a = "1010", b = "1011"
  输出: "10101"
*/
func btoi(b bool) int {
	if b {
		return 1
	}
	return 0
}
func addBinary(a string, b string) string {
	res := ""

	if len(a) < len(b) {
		a, b = b, a
	}
	// len(a) >= len(b)
	var plus1 bool = false
	i, j := len(a)-1, len(b)-1
	for i >= 0 && j >= 0 {
		ai := int(a[i] - '0')
		bj := int(b[j] - '0')
		s := ai + bj + btoi(plus1)
		switch s {
		case 3:
			res = "1" + res
			plus1 = true
		case 2:
			res = "0" + res
			plus1 = true
		case 1:
			res = "1" + res
			plus1 = false
		case 0:
			res = "0" + res
			plus1 = false
		}
		i--
		j--
	}

	if i >= 0 { // 字符串b短
		f := a[:i+1]
		if !plus1 { // 没有进位了
			res = f + res
		} else { // 还有进位
			res = stringPlusOne(f) + res
		}
	} else { // a b 长度一样
		if plus1 {
			res = "1" + res
		}
	}

	return res
}
func stringPlusOne(f string) string {
	res := ""

	var plus1 bool = true
	idx := len(f) - 1
	for plus1 && idx >= 0 {
		if f[idx] == '1' {
			res = "0" + res
			plus1 = true
		} else {
			res = "1" + res
			plus1 = false
		}
		idx--
	}
	if plus1 {
		res = "1" + res
	} else {
		res = f[:idx+1] + res
	}

	return res
}
