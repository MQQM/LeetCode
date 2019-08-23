/*
  题目：
  给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

  示例 1:
  输入: coins = [1, 2, 5], amount = 11
  输出: 3 
  解释: 11 = 5 + 5 + 1

  示例 2:
  输入: coins = [2], amount = 3
  输出: -1

  说明:
  你可以认为每种硬币的数量是无限的。

  不错的题解：
  https://leetcode-cn.com/problems/coin-change/solution/dong-tai-gui-hua-tao-lu-xiang-jie-by-wei-lai-bu-ke/
*/

// 带备忘录的递归算法
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, -2);   
        return helper(coins, amount, memo);
    }
    int helper(vector<int>& coins, int amount, vector<int>& memo){
        if(amount == 0){
            return 0;
        }
        if(memo[amount] != -2){ // 备忘录里有记录
            return memo[amount];
        }
        
        int ans = INT_MAX;
        for(int coin : coins){
            if(amount < coin){
                continue;
            }
            int subProb = helper(coins, amount-coin, memo);
            if(subProb == -1){ // 子问题无解
                continue;
            }
            ans = min(ans, subProb+1);
        }
            
        memo[amount] = (ans==INT_MAX) ? -1 : ans;
        return memo[amount];
    }
};
