/*
  题目：
  给定一个经过编码的字符串，返回它解码后的字符串。
  编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
  你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
  此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

  示例:
  s = "3[a]2[bc]", 返回 "aaabcbc".
  s = "3[a2[c]]", 返回 "accaccacc".
  s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

  题解参考：
  https://leetcode-cn.com/problems/decode-string/solution/ti-jie-czhan-by-youlookdeliciousc
*/
class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<int> nums;
        stack<string> strs;        
        int num = 0;
        for(int i=0; i<s.size(); i++){
            if('0' <= s[i] && s[i] <= '9' ){
                num = num*10 + s[i]-'0'; // 需要重复的次数
            }else if( s[i] == '[' ){
                nums.push(num);
                num = 0;
                strs.push(res);          // 需要进行重复操作的之前的字符串
                res = "";
            }else if( ('a'<=s[i]&&s[i]<='z') || ('A'<=s[i]&&s[i]<='Z') ){
                res += s[i];             // 需要重复的字符串
            }else{ // s[i] == ']'        // 此时次数在nums栈中，要重复地字符串在res中
                int times = nums.top();
                nums.pop();
                while(times--){
                    strs.top() += res;
                }
                res = strs.top();
                strs.pop();
            }            
        }                
        return res;
    }
};
