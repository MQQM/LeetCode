/*
  题目：
  给定两个数组，编写一个函数来计算它们的交集。

  示例 1:
  输入: nums1 = [1,2,2,1], nums2 = [2,2]
  输出: [2]
  
  示例 2:
  输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
  输出: [9,4]

  参考：
  https://blog.csdn.net/my_clear_mind/article/details/81514799
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(),nums1.end());
        
        set<int> s2;
        for(int i=0; i<nums2.size(); i++){
            if( s1.find(nums2[i]) != s1.end() ){
                s2.insert(nums2[i]);
            }
        }     
        
        return vector<int>(s2.begin(),s2.end());
    }
};
