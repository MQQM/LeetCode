/*
  题目：
  给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

  注意：
  num1 和num2 的长度都小于 5100.
  num1 和num2 都只包含数字 0-9.
  num1 和num2 都不包含任何前导零。
  你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
*/
class Solution {
public:
    string addStrings(string num1, string num2) {                  
        int len1 = num1.size();
        int len2 = num2.size();
        if(len1 > len2){
            num2 = string(len1-len2, '0') + num2;
        }else if(len1 < len2){
            num1 = string(len2-len1, '0') + num1;
        }            
        // len1 == len2        
        string res = "";

        char carry = '0';
        while( !num1.empty() && !num2.empty() ){             
            int a = num1.back() - '0';        
            num1.pop_back();        
            int b = num2.back() - '0';      
            num2.pop_back();        
            //
            int sum = a + b + (carry-'0');                              
            string sum_str = to_string(sum);                                
            res = sum_str.back() + res;
            sum_str.pop_back();
            carry = sum_str.empty() ? '0' : sum_str[0];
        }
        if( carry != '0' ){        
            res = carry + res;
        }
        
        return res;
    }
};
