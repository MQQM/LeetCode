/*
  题目：
  给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。
  一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

  示例 1:
  输入:
  11110
  11010
  11000
  00000
  输出: 1

  示例 2:  
  输入:
  11000
  11000
  00100
  00011
  输出: 3

  做法：https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode
*/
class Solution {
public:    
    void dfs(vector<vector<char>>& grid, int r, int c){
        grid[r][c] = '0';
        
        int num_row = grid.size();
        int num_col = grid[0].size();                    
        if( r-1 >= 0 &&      grid[r-1][c]=='1') dfs(grid, r-1, c);
        if( r+1 < num_row && grid[r+1][c]=='1') dfs(grid, r+1, c);
        if( c-1 >= 0 &&      grid[r][c-1]=='1') dfs(grid, r, c-1);
        if( c+1 <num_col &&  grid[r][c+1]=='1') dfs(grid, r, c+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int num_row = grid.size();
        if(num_row == 0){
            return 0;
        }
        int num_col = grid[0].size();
        
        int cnt=0;
        for(int r=0; r<num_row; r++){
            for(int c=0; c<num_col; c++){
                if(grid[r][c] == '1'){                   
                    ++cnt;
                    dfs(grid, r, c);
                }
            }
        }        
        return cnt;
    }
};
