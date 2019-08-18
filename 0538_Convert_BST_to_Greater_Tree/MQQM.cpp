/*
  题目：
  给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

  例如：
  输入: 二叉搜索树:
                5
              /   \
             2     13
  输出: 转换为累加树:
               18
              /   \
            20     13
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
    void ffffff(TreeNode* root, long& sum){
        if(root == NULL){
            return;
        }
         
        ffffff(root->right, sum);
        root->val += sum;
        sum = root->val;
        ffffff(root->left, sum);            
    }
    TreeNode* convertBST(TreeNode* root) {                
        long sum = 0;        
        ffffff(root,sum);               
        return root;                        
    }
};
