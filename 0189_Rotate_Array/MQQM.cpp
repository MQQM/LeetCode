/*
  题目：
  给定一个数组，将数组中的元素向右移动 k 个位置，其中 k ：是非负数。

  示例 1:
  输入: [1,2,3,4,5,6,7] 和 k = 3
  输出: [5,6,7,1,2,3,4]
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 0){
            return;
        }        
        
        k = k % len;                
        vector<int> tmp;
        for(int i=len-k; i<len; i++){
            tmp.push_back(nums[i]);
        }
        
        nums.erase(nums.begin()+len-k,nums.end());
        nums.insert(nums.begin(),tmp.begin(),tmp.end());
    }
};
