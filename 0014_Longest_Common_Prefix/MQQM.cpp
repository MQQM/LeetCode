/*
  题目：
  编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。

  示例 1:
  输入: ["flower","flow","flight"]
  输出: "fl"

  示例2:
  输入: ["dog","racecar","car"]
  输出: ""
  解释: 输入不存在公共前缀。

  说明:
  所有输入只包含小写字母 a-z 。
  
  参考：https://blog.csdn.net/SoulOH/article/details/81877995
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        
        string s0 = strs[0];
        int index = 0;
        
        for(; index<s0.length(); index++){        
            char c = s0[index];
            for(string str : strs){
                if(str.length() == index || c != str[index]){
                    return s0.substr(0,index);
                }                    
            }
        }          
        
        return s0.substr(0,index);
    }
};
