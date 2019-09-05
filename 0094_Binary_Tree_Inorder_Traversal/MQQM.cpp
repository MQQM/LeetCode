/*
  题目：
  给定一个二叉树，返回它的中序 遍历。
  
  示例:
  输入: [1,null,2,3]
     1
      \
       2
      /
     3
  输出: [1,3,2]

  进阶: 递归算法很简单，你可以通过迭代算法完成吗？
  
  做法：递归
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
    void inorder(TreeNode* root, vector<int>& res){
        if(root == NULL){
            return;
        }        
        inorder(root->left, res);
        res.push_back( root->val );
        inorder(root->right, res);
    }    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);        
        return res; 
    }
};
