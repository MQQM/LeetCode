/*
  题目：
  给定一个二叉树，返回它的 后序 遍历。
  
  示例:
  输入: [1,null,2,3]  
     1
      \
       2
      /
     3 
  输出: [3,2,1]

  进阶: 递归算法很简单，你可以通过迭代算法完成吗？

  做法：这个方法是递归的
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
    void postorder(TreeNode* root, vector<int>& res){                
        if(root == NULL){        
            return;        
        }             
        postorder(root->left, res);
        postorder(root->right, res);  
        res.push_back(root->val); 
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};
