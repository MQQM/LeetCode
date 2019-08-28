/*
  题目：
  将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
  比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
  L   C   I   R
  E T O E S I I G
  E   D   H   N
  之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
  请你实现这个将字符串进行指定行数变换的函数：string convert(string s, int numRows);

  示例 1:
  输入: s = "LEETCODEISHIRING", numRows = 3
  输出: "LCIRETOESIIGEDHN"

  示例 2:
  输入: s = "LEETCODEISHIRING", numRows = 4
  输出: "LDREOEIIECIHNTSG"
  解释:
  L     D     R
  E   O E   I I
  E C   I H   N
  T     S     G
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){ // 只允许一行，直接返回
            return s;
        }
                
        vector<string> vs(numRows, "");
        int idx = 0;
        bool updown = true; // true <--> down
        for(int i=0; i<s.size(); i++){     
            vs[idx] = vs[idx] + s[i];
            if(updown == true){ // down
                idx++;
                if(idx == numRows -1){
                    updown = false;
                }
            }else{ // up
                idx--;                
                if(idx == 0){
                    updown = true;
                }                
            }                      
        }
        
        string res = "";
        for(string e : vs){
            res = res + e;
        }        
        return res;
    }
};
