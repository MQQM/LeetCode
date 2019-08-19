/*
  题目：
  给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。在杨辉三角中，每个数是它左上方和右上方的数的和。

  示例:
  输入: 5
  输出:
  [
       [1],
      [1,1],
     [1,2,1],
    [1,3,3,1],
   [1,4,6,4,1]
  ]
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {         
        vector<vector<int>> res;        
        if(numRows == 0){
            return res;
        }
        
        res.push_back(vector<int>(1,1)); // 第0行，1个1
        for(int k=1; k<=numRows-1; k++){            
            vector<int> tmp(k+1);            
            tmp[0] = res[k-1][0];            
            for(int j=1; j<=k-1;j++){
                tmp[j] = res[k-1][j-1] + res[k-1][j];            
            }
            tmp[k] = res[k-1][k-1];
            
            res.push_back(tmp);
        }        
        return res;
    }
};
