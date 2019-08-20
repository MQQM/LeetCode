/*
  题目：
  不使用运算符 + 和 - ，计算两整数 a 、b 之和。

  示例 1:
  输入: a = 1, b = 2
  输出: 3

  示例 2:
  输入: a = -2, b = 3
  输出: 1

  https://leetcode-cn.com/problems/sum-of-two-integers/solution/cshi-xian-xiang-jie-by-zi-lun
*/
class Solution {
public:
    int getSum(int a, int b) {
        while(b){                   
            int c = a ^ b;       
            int d = ((unsigned int)(a & b)) << 1;       
            a = c;        
            b = d;        
        }
        return a;
    }
};
