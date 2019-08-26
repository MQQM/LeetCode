/*
  题目：
  运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
  
  获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。  
  写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。
  当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

  进阶:
  你是否可以在 O(1) 时间复杂度内完成这两种操作？

  示例:
  LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );
  cache.put(1, 1);
  cache.put(2, 2);
  cache.get(1);       // 返回  1
  cache.put(3, 3);    // 该操作会使得密钥 2 作废
  cache.get(2);       // 返回 -1 (未找到)
  cache.put(4, 4);    // 该操作会使得密钥 1 作废
  cache.get(1);       // 返回 -1 (未找到)
  cache.get(3);       // 返回  3
  cache.get(4);       // 返回  4
  
  不错的题解
  https://leetcode-cn.com/problems/lru-cache/solution/lru-ce-lue-xiang-jie-he-shi-xian-by-labuladong/
*/
class LRUCache
{
private:
    int capacity;                                           // 缓存的容量
    list<pair<int, int>> ls;                                //双向链表
    unordered_map<int, list<pair<int, int>>::iterator> map; // 哈希表

public:
    LRUCache(int cap)
    {
        capacity = cap;
    }

    int get(int key)
    {
        auto it = map.find(key);
        if (it == map.end())
        { // 没找到，缓存中不存在
            return -1;
        }
        // 缓存中存在key
        pair<int, int> kv_pair = *map[key];
        ls.erase(map[key]); // 擦除的是一个迭代器
        ls.push_front(kv_pair);
        map[key] = ls.begin();
        return kv_pair.second;
    }

    void put(int key, int value)
    {
        auto it = map.find(key);
        if (it == map.end())
        { // 没找到，需要往双向链表中插入，所以需要判断双向链表是否满
            if (ls.size() == capacity)
            { // 双向链表是满了，需要把链表尾部节点删除
                auto last_pair = ls.back();
                map.erase(last_pair.first);
                ls.pop_back();
            }
            // 将key插入链表头部
            ls.push_front(make_pair(key, value));
            map[key] = ls.begin();
        }
        else
        { // 找到
            ls.erase(map[key]);
            ls.push_front(make_pair(key, value));
            map[key] = ls.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
