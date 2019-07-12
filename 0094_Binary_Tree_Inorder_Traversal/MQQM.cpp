/*
  题目：
  给定一个二叉树，返回它的中序 遍历。
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
private:
    vector<int> vec;
public:
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        inorder(root->left);
        vec.push_back( root->val );
        inorder(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);        
        return vec; 
    }
};
