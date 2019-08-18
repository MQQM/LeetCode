/*
  题目：
  翻转一棵二叉树。

  示例：
  输入：
       4
     /   \
    2     7
   / \   / \
  1   3 6   9
  输出：
       4
     /   \
    7     2
   / \   / \
  9   6 3   1
  
  做法：递归地交换左右孩子的指针。
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
    TreeNode* ff(TreeNode* root){
        if(root == NULL){
            return NULL;
        }
        swap(root->left, root->right);
        ff(root->left);
        ff(root->right);
        return root;
    }    
    TreeNode* invertTree(TreeNode* root) {     
        return  ff(root);
    }
};
