/*
  题目：
  给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

  示例 :
  给定二叉树  
            1
           / \
          2   3
         / \     
        4   5    
  返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

  注意：两结点之间的路径长度是以它们之间边的数目表示。
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
    int depth(TreeNode* root){
        if(root == NULL){
            return 0;
        }                
        int dep_left =  depth(root->left);
        int dep_right = depth(root->right);      
        return max(dep_left, dep_right) +1;              
    }
    
    void ffff(TreeNode* root, int& max_dia){          
        if(root==NULL){
            return;
        }
        
        int dia_left =  depth(root->left) - 1;    
        int dia_right = depth(root->right) -1;        
        int dia = dia_left + dia_right + 2;        
        if(dia> max_dia){
            max_dia = dia;
        }
        ffff(root->left, max_dia);
        ffff(root->right,max_dia);           
    }
    
    int diameterOfBinaryTree(TreeNode* root) {         
        int max_dia = 0;               
        ffff(root, max_dia);                          
        return max_dia;
    }
};
