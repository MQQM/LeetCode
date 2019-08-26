/*
  题目：
  给定一个无序的整数数组，找到其中最长上升子序列的长度。

  示例:
  输入: [10,9,2,5,3,7,101,18]
  输出: 4 
  解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

  说明:
  可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。你算法的时间复杂度应该为 O(n^2)。
  
  进阶: 
  你能将算法的时间复杂度降低到 O(n log n) 吗?

  不错的题解：动态规划，时间复杂度为O(n^2)
  https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-she-ji-fang-fa-zhi-pai-you-xi-jia/
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {    
        // dp数组，dp[i]定义为 以nums[i]结尾的最长递增子序列的长度
        vector<int> dp(nums.size(), 1); 
        for(int i=0; i<nums.size(); i++){            
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){ // 新添加一个数字时，必须加在比它小的数的后面               
                    dp[i] = max(dp[i], dp[j]+1);            
                }                
            }
        }
        
        int maxe = 0;
        for(int e : dp){
            if(e > maxe){
                maxe = e;
            }
        }
        return maxe;
    }
};
