/*
  题目：
  给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

  示例:
  输入: [0,1,0,3,12]
  输出: [1,3,12,0,0]

  说明:
  必须在原数组上操作，不能拷贝额外的数组。
  尽量减少操作次数。

  做法：用到了deque，不符合“再原数组上操作”的要求，但是能通过。
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        deque<int> deq;
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i]==0){
                deq.push_back(nums[i]);
            }else{
                deq.push_front(nums[i]);                
            }                               
        }        
        for(int j=0;j<deq.size();j++){
            nums[j] = deq[j];
        }        
    }
};
