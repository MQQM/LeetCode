/*
  题目：
  给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

  示例：
  输入: S = "ADOBECODEBANC", T = "ABC"
  输出: "BANC"
  
  说明：
  如果 S 中不存这样的子串，则返回空字符串 ""。
  如果 S 中存在这样的子串，我们保证它是唯一的答案。

  https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/solution/hua-dong-chuang-kou-tong-yong-si-xiang-jie-jue-zi-
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, minLen = INT_MAX;
        int left = 0, right = 0;
        
        unordered_map<char,int> windows; // windows只关心字符串t中的字符
        unordered_map<char,int> needs; // 记录字符串t中各个字符的出现次数
        for(char c : t) needs[c]++;
        
        int match = 0;
        
        while(right < s.size()){
            char c1 = s[right];     // 取右边的一个字符
            right++;                
            if(needs.count(c1)){    // s[right]是字符串t中的字符
                windows[c1]++;      // 调整当前窗口内字符出现的次数
                if(windows[c1] == needs[c1]){ // 如果次数==所需要出现的次数，则认为已经匹配掉一个字符
                   match++; 
                }
            }
            
            // 当所有字符都匹配掉后，就：
            // 1. 看下 left 至 right 区间内的字符串是否更短
            // 2. 移动left
            while(match == needs.size()){
                if(right -left < minLen){   // 1. 
                    start = left;
                    minLen = right - left;
                }
                //
                char c2 = s[left];          // 2.
                left++;  
                if(needs.count(c2)){
                    windows[c2]--;          // 调整字符出现次数
                    if(windows[c2] < needs[c2]){
                       match--; 
                    }
                }              
            }
        }
        return minLen==INT_MAX? "" : s.substr(start,minLen);
    }
};
