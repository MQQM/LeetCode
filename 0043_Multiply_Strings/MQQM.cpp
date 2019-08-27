/*
  题目：
  给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

  示例 1:
  输入: num1 = "2", num2 = "3"
  输出: "6"

  示例 2:
  输入: num1 = "123", num2 = "456"
  输出: "56088"

  说明：
  num1 和 num2 的长度小于110。
  num1 和 num2 只包含数字 0-9。
  num1 和 num2 均不以零开头，除非是数字 0 本身。
  不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

  题解：
  https://leetcode-cn.com/problems/multiply-strings/solution/c-shu-shi-cheng-fa-dai-ma-jian-ji-you-ya-yi-dong-b/
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();        
        string res(len1+len2, '0');      
        
        for(int i = len2-1; i>=0; i--){
            for(int j=len1-1; j>=0; j--){                              
                int tmp = (res[i+j+1]-'0') + (num2[i]-'0')*(num1[j]-'0');                              
                res[i+j+1] = tmp%10 + '0';
                res[i+j] += tmp/10 ;            
            }
        }
        for(int i=0; i<res.size(); i++){
            if(res[i] != '0'){
                return res.substr(i);
            }
        }        
        
        return "0";
    }
};
