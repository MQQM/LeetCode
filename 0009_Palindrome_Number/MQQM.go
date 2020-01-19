/*
  题目：
  判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
  
  做法：利用第7题的整数反转。
*/
func isPalindrome(y int) bool {
    if y<0 {
        return false
    }
    // 下面是 y>=0 时
    x := y 
    
    x_rev := 0 // 反转    
    for x!=0 {    
        g := x % 10
        x_rev = x_rev*10 + g        
        x /= 10                 
    }
    
    if y!= x_rev{
        return false
    }
    return true   
}
