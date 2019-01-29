/*
  题目：
  你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
  如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
  给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
  
  参考：
  https://www.cnblogs.com/theodoric008/p/9408664.html
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if( nums.empty() ){
            return 0;
        }
        if( nums.size() == 1 ){
            return nums[0];
        }
    
        vector<int> vec(nums.size(), 0);
        vec[0] = nums[0];
        vec[1] = nums[1] > nums[0] ? nums[1] : nums[0];
        for(size_t i=2; i<nums.size(); i++){
            vec[i] = vec[i-1] > vec[i-2]+nums[i] ? vec[i-1] : vec[i-2]+nums[i];
        }        
        
        return vec[nums.size() - 1];
    }
};
