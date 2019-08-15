/*
  题目：
  给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
  找到所有在 [1, n] 范围之间没有出现在数组中的数字。
  您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

  示例:
  输入:
  [4,3,2,7,8,2,3,1]
  输出:
  [5,6]
  
  做法：把各个元素看做索引位，将索引位上的元素置为负数。后再检查出现的正数。
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()){
            return res;            
        }
        
        for(int i = 0; i<nums.size(); i++){
            int idx = abs(nums[i]) - 1; 
            nums[idx] = nums[idx] > 0 ? -nums[idx] : nums[idx];
        }
        
        for(int j=0; j<nums.size(); j++){
            if(nums[j] > 0){
                res.push_back(j+1);
            }
        }        
        return res;
    }
};
