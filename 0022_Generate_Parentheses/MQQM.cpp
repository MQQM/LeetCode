/*
  题目：
  给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
  例如，给出 n = 3，生成结果为：
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
    bool valid(const string& s){
        int b = 0;
        for(char c : s){
            if(c == '('){
                b++;                
            }else{
                b--;
            }
            if(b < 0){
                return false;
            }
        }
        return b==0;
    }
    void ff(string& arr, int pos, vector<string>& res){
        if(pos == arr.size()){
            if(valid(arr)){
                res.push_back(arr);
            }
        }else{        
            arr[pos] = '(';        
            ff(arr, pos+1, res);
            arr[pos] = ')';
            ff(arr, pos+1, res);
        }        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string arr(2*n,NULL);
        ff(arr, 0, res);        
        return res;
    }
};
