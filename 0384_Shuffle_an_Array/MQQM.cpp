/*
  题目：
  打乱一个没有重复元素的数组。

  做法：随机选择一个未取过的数，放到数组末尾。
*/
class Solution {
private:
    vector<int> resetVec;
    vector<int> retVec; 
public:
    Solution(vector<int>& nums) {
        resetVec = nums;
        retVec = nums;
        srand(time(NULL));                        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return resetVec;        
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {       
        int len = retVec.size();
        for(int i=0; i<len; i++){
            int j = rand() % len;
            int tmp = retVec[len-1-i];
            retVec[len-1-i] = retVec[j];           
            retVec[j] = tmp;            
        }        
        
        return retVec;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
