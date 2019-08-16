/*
  题目：
  给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
  你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，
  否则不为 NULL 的节点将直接作为新二叉树的节点。
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL && t2==NULL){
            return NULL;
        }
        
        if(t1 == NULL){           
            return t2; // 这里并没有新建节点，而是用了现有节点            
        }
        if(t2 == NULL){           
            return t1;            
        }
        
        TreeNode* root = new TreeNode(t1->val + t2->val); // 两个都非空，新建了节点
        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);        
        return root;
        // 不新建节点
        // t1->val = t1->val + t2->val;
        // t1->left =  mergeTrees(t1->left, t2->left);
        // t1->right = mergeTrees(t1->right, t2->right);        
        // return t1;
    }
};
