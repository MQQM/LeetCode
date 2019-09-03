/*
  题目：
  在未排序的数组中找到第k大的元素。

  做法：
  用STL中的priority_queue
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end()); 
        for(int i=1; i<k; i++){
            pq.pop();
        }
        return pq.top();        
    }
};
