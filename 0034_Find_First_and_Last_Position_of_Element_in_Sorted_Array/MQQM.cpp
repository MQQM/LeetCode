/*
  题目：
  给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
  你的算法时间复杂度必须是 O(log n) 级别。
  如果数组中不存在目标值，返回 [-1, -1]。

  示例 1:
  输入: nums = [5,7,7,8,8,10], target = 8
  输出: [3,4]

  示例 2:
  输入: nums = [5,7,7,8,8,10], target = 6
  输出: [-1,-1]

  不错的题解：
  https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/
*/
class Solution {
public:
    int left_bound(const vector<int>& nums, int left, int right, int target){ // [left, right)
        while(left < right){          
            int mid = left + (right-left)/2;          
            if(nums[mid] == target){              
                right = mid;          
            }else if(target < nums[mid]){           
                right = mid;         
            }else if(nums[mid] < target){            
                left = mid+1;         
            }      
        }
        return left;      
    }
    int right_bound(const vector<int>& nums, int left, int right, int target){ // [left, right)
        while(left < right){            
            int mid = left + (right-left)/2;             
            if(nums[mid] == target){          
                left = mid+1;         
            }else if(target < nums[mid]){           
                right = mid;          
            }else if(nums[mid] < target){           
                left = mid+1;         
            } 
        }
        return left-1;
    }    
    vector<int> searchRange(vector<int>& nums, int target) {                
        vector<int> res(2,-1);
        
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){                   // [left, right]
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){    
                res[0] = left_bound(nums, left, mid+1, target);
                res[1] = right_bound(nums, mid,right+1, target);
                break;
            }else if(target < nums[mid]){
                right = mid-1;
            }else if(nums[mid] < target){
                left = mid +1;
            }                
        }
        
        return res;
    }
};

