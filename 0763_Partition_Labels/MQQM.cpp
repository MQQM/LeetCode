/*
  题目：
  字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

  示例 1: 
  输入: S = "ababcbacadefegdehijhklij"
  输出: [9,7,8]
  解释:
  划分结果为 "ababcbaca", "defegde", "hijhklij"。每个字母最多出现在一个片段中。
  像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

  注意:
  S的长度在[1, 500]之间。
  S只包含小写字母'a'到'z'。

  参考：
  https://blog.csdn.net/fuxuemingzhu/article/details/79265829
*/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<int,int> um;
        for(int i=0; i<S.size(); i++){
            um[S[i]] = i;               // 记录下各个字符的最后出现位置
        }
        
        vector<int> res;
        int start = 0, end =0;    
        for(int j=0; j<S.size(); j++){
            end = max(end, um[S[j]]);
            if(j == end){               // end不动了，j追上来了，说明这里该断开了
                res.push_back(end - start + 1);                
                start = end + 1;
            }            
        }        
        return res;
    }
};
