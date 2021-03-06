/*
  题目：实现 int sqrt(int x) 函数。
  计算并返回 x 的平方根，其中 x 是非负整数。
  由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

  示例 1:
  输入: 4
  输出: 2

  示例 2:
  输入: 8
  输出: 2
  说明: 8 的平方根是 2.82842..., 
       由于返回类型是整数，小数部分将被舍去。

  https://leetcode-cn.com/problems/sqrtx/solution/x-de-ping-fang-gen-by-gpe3dbjds1
*/
class Solution {
public:
    int mySqrt(int x) {         
        long long i = 0;         
        long long j = x/2+1;
        while(i<=j){
            long long mid = (i+j)/2;
            long long p = mid*mid;
            if(p == x){
                return mid;
            }else if(p < x){
                i = mid+1;
            }else{
                j = mid-1;
            }           
        }
        return j;       
    }
};
