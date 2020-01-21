/*
  题目：
  给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
  
  说明：
  有效字符串需满足：左括号必须用相同类型的右括号闭合。左括号必须以正确的顺序闭合。
  注意空字符串可被认为是有效字符串。
*/
func isValid(s string) bool {
	if len(s) == 0 {
		return true
	}

	m := map[byte]byte{
		'(': ')',
		'[': ']',
		'{': '}',
	}

	var stk []byte
	for i := 0; i < len(s); i++ {
		si := s[i]
		if si == '(' || si == '[' || si == '{' {
			stk = append(stk, si)
			continue
		}
		if si == ')' || si == ']' || si == '}' {
			if len(stk) == 0 || m[stk[len(stk)-1]] != si {
				return false
			} else {
				stk = stk[:len(stk)-1]
			}
		}
	}
	
	if len(stk) == 0 {
		return true
	}

	return false

}
