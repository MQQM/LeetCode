/*
  题目：
  给定一个二叉树，它的每个结点都存放着一个整数值。找出路径和等于给定数值的路径总数。
  路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
  二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

  示例：
  root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8  
        10
       /  \
      5   -3
     / \    \
    3   2   11
   / \   \
  3  -2   1
  返回 3。和等于 8 的路径有:
  1.  5 -> 3
  2.  5 -> 2 -> 1
  3.  -3 -> 11

  题解参考：
  https://leetcode-cn.com/problems/path-sum-iii/solution/da-jia-du-shuang-zhong-di-gui-wo-zhi-yong-yi-ge-di
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:    
    void fff(TreeNode* root, int sum, vector<int>& data, int& cnt){
        if(root == NULL){
            return;
        }
        
        data.push_back(root->val);
        int ss = 0;
        for(int k=data.size()-1; k>=0; k--){
            ss += data[k];
            if(ss == sum){
                cnt++;
            }
        }
        fff(root->left, sum, data, cnt);
        fff(root->right, sum, data, cnt);                
        data.pop_back();
    }    
    int pathSum(TreeNode* root, int sum) {
        vector<int> data;
        int cnt = 0;
        fff(root, sum, data, cnt);
        return cnt;
    }
};
