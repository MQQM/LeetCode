/*
  题目：
  给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
  例如，给出 n = 3，生成结果为：
  [
    "((()))",
    "(()())",
    "(())()",
    "()(())",
    "()()()"
  ]
   
  题解：
  https://leetcode-cn.com/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode
*/
class Solution {
public:
    void backtrack(vector<string>& res, string s, int open, int close, int max){
        if(s.size() == max*2){
            res.push_back(s);
            return;
        }
        if(open < max){
            backtrack(res, s+'(', open+1, close, max);            
        }
        if(close < open){
            backtrack(res, s+')', open, close+1, max);
        }        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "",0,0,n);        
        return res;
    }
};
