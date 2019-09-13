// LeetCode 705 设计哈希集合
/*
  题目：
  不使用任何内建的哈希表库设计一个哈希集合
  具体地说，你的设计应该包含以下的功能
  add(value)：向哈希集合中插入一个值。
  contains(value) ：返回哈希集合中是否存在这个值。
  remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

  示例:
  MyHashSet hashSet = new MyHashSet();
  hashSet.add(1);         
  hashSet.add(2);         
  hashSet.contains(1);    // 返回 true
  hashSet.contains(3);    // 返回 false (未找到)
  hashSet.add(2);          
  hashSet.contains(2);    // 返回 true
  hashSet.remove(2);          
  hashSet.contains(2);    // 返回  false (已经被删除)

  注意：
  所有的值都在 [1, 1000000]的范围内。
  操作的总数目在[1, 10000]范围内。
  不要使用内建的哈希集合库。

  参考：
  https://leetcode-cn.com/problems/design-hashset/solution/c-zhong-ji-wu-di-bian-tai-jian-dan-ban-ben-by-user/
*/
class MyHashSet
{
private:
    int arr[1000001];

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        fill(arr, arr + 1000001, 0);
    }

    void add(int key)
    {
        arr[key] = 1;
    }

    void remove(int key)
    {
        arr[key] = 0;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        return arr[key] == 1 ? true : false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
