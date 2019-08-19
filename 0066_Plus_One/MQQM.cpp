/*
  题目：
  给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
  你可以假设除了整数 0 之外，这个整数不会以零开头。

  示例 1:
  输入: [1,2,3]
  输出: [1,2,4]
  解释: 输入数组表示数字 123。

  示例 2:
  输入: [4,3,2,1]
  输出: [4,3,2,2]
  解释: 输入数组表示数字 4321。
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();        
        int m = digits[len-1] + 1; 
        bool plus1 = false;
        if(m==10){
            digits[len-1] = 0;            
            plus1 = true;            
        }else{                    
            digits[len-1] = m;            
            plus1 = false;        
        }       
        
        int idx = len-2;
        while(plus1 == true && idx>=0){          
            int s = digits[idx] + 1;            
            if(s == 10){                
                digits[idx] = 0;
                plus1 = true;
            }else{            
                digits[idx] = s;
                plus1 = false;
            }            
            --idx;            
        }
        if(plus1 == true){
            digits.insert(digits.begin(),1);
        }
        
        return digits;
    }
};
