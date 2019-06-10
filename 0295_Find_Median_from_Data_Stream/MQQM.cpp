/*
  题目：
  如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
  如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
  我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
  
  参考：
  https://blog.csdn.net/lv1224/article/details/82222719
*/
class Solution {
private:
    vector<int> nums;
public:    
    void Insert(int num){
        auto it=upper_bound(nums.begin(),nums.end(),num); // 在一个区间中找到，返回大于val的第一个元素位置
        nums.insert(it,num);               
    }

    double GetMedian()    { 
        int len = nums.size();
        if(len%2==0){
            return ( nums[len/2 -1] + nums[len/2] ) / 2.0;
        } 
        else{
            return nums[len/2];
        }
    }
};
