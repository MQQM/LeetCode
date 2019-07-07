/*
  题目：
  给定两个无序数组，编写一个函数来计算它们的交集。

  示例 1:
  输入: nums1 = [1,2,2,1], nums2 = [2,2]
  输出: [2,2]
  示例 2:
  输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
  输出: [4,9]
  
  参考：
  https://blog.csdn.net/my_clear_mind/article/details/81515029
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        for(int i=0; i<nums1.size(); i++){
            m[nums1[i]]++;
        }
        
        vector<int> rst;
        for(int i=0; i<nums2.size(); i++){
            if(m[nums2[i]] > 0){
                rst.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }        
        
        return rst;
    }
};
