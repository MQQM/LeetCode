/*
  题目：
  给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。
  一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
  
  示例 1:
  输入:
  11110
  11010
  11000
  00000
  输出: 1
  
  示例 2:  
  输入:
  11000
  11000
  00100
  00011
  输出: 3
  
  题解：广度优先遍历（BFS）
  https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num_row = grid.size();
        if(num_row == 0){
            return 0;
        }
        int num_col = grid[0].size();
        int cnt = 0;
               
        for(int r=0; r<num_row; r++){
            for(int c=0; c<num_col; c++){
                if(grid[r][c] == '1'){
                    cnt++;                          
                    grid[r][c] = '0';
                    
                    queue<pair<int,int>> que;
                    que.push(make_pair(r,c));
                    while( !que.empty() ){
                        pair<int,int> p = que.front();
                        que.pop();
                        int row = p.first;
                        int col = p.second;      
                        
                        if(row-1 >= 0      && grid[row-1][col] == '1'){                             
                            que.push(make_pair(row-1, col));
                            grid[row-1][col] = '0';
                        }
                        if(row+1 < num_row && grid[row+1][col] == '1'){
                            que.push(make_pair(row+1,col));
                            grid[row+1][col] = '0';
                        }
                        if(col-1 >= 0      && grid[row][col-1] == '1'){
                            que.push(make_pair(row,col-1));
                            grid[row][col-1] = '0';
                        }
                        if(col+1 < num_col && grid[row][col+1] == '1'){                        
                            que.push(make_pair(row,col+1));    
                            grid[row][col+1] = '0';
                        }                        
                    }
                    
                }
            }
        }
        
        return cnt;
    }
};
