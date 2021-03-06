/*
  题目：
  设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。
  你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。
  每次调用 KthLargest.add，返回当前数据流中第K大的元素。

  示例:
  int k = 3;
  int[] arr = [4,5,8,2];
  KthLargest kthLargest = new KthLargest(3, arr);
  kthLargest.add(3);   // returns 4
  kthLargest.add(5);   // returns 5
  kthLargest.add(10);  // returns 5
  kthLargest.add(9);   // returns 8
  kthLargest.add(4);   // returns 8
  
  说明: 
  你可以假设 nums 的长度≥ k-1 且k ≥ 1。

  参考：
  https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/solution/shu-ju-liu-zhong-de-di-kda-yuan-su-by-gpe3dbjds1/

  做法：
  用STL提供的priority_queue（是一个堆结构），默认构建的是大顶堆。
  这里要找出第K大元素，需要小顶堆。

  降序队列（大顶堆）
  priority_queue<int, vector<int>, less<int>> pq;

  升序队列（小顶堆）
  priority_queue<int, vector<int>, greater<int>> pq;
*/
class KthLargest
{
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int capacity;

public:
    KthLargest(int k, vector<int> &nums)
    {
        capacity = k;
        for (int num : nums)
        {
            pq.push(num);
            if (pq.size() > capacity)
            {
                pq.pop();
            }
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > capacity)
        {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
