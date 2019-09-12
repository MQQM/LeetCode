/*
  题目：
  给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

  示例 1:
  输入: nums = [1,1,1,2,2,3], k = 2
  输出: [1,2]

  示例 2:
  输入: nums = [1], k = 1
  输出: [1]

  说明：
  你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
  你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

  做法：
  遍历一趟，记录每个元素出现的次数，生成一个unordered_map。
  遍历这个unordered_map，把其元素放入priority_queue(这是一个队列，且队列首元素一直都是最大的)。
  
  参考：
  https://blog.csdn.net/a2331046/article/details/52445088
*/
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> um;
        for (int num : nums)
        {
            um[num]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto it : um)
        {
            pq.push(make_pair(it.second, it.first));
        }

        vector<int> res;
        for (int i = 1; i <= k; i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
