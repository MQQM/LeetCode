/*
  题目：
  编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。
  
  示例 1:
  输入: ["flower","flow","flight"]
  输出: "fl"
  
  示例2:
  输入: ["dog","racecar","car"]
  输出: ""
  解释: 输入不存在公共前缀。
  
  说明:
  所有输入只包含小写字母 a-z 。
  
  参考：https://blog.csdn.net/SoulOH/article/details/81877995
*/
func longestCommonPrefix(strs []string) string {
	if strs == nil || len(strs) == 0 {
		return ""
	}

	s0 := strs[0]
	idx := 0

	for ; idx < len(s0); idx++ {
		c := s0[idx]
		for j := 1; j < len(strs); j++ {
			if len(strs[j]) == idx || strs[j][idx] != c {
				return s0[0:idx]
			}
		}
	}

	return s0
}
