/*
  题目：
  实现 strStr() 函数。
  给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
  
  说明:
  当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
  对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
*/
func strStr(haystack string, needle string) int {
	if needle == "" {
		return 0
	}

	len1 := len(haystack)
	len2 := len(needle)

	for i := 0; i <= len1-len2; i++ {
		j := 0
		for ; j < len2; j++ {
			if haystack[i+j] != needle[j] {
				break
			}
		}
		if j == len2 {
			return i
		}
	}

	return -1
}
