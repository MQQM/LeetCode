/*
  题目：
  给定一个二叉树，原地将它展开为链表。
  例如，给定二叉树
      1
     / \
    2   5
   / \   \
  3   4   6
  将其展开为：
  1
   \
    2
     \
      3
       \
        4
         \
          5
           \
            6
  
  做法：
  用来前序遍历的非递归方法。而题目指明要原地修改，不是很符合题意，但是可行。
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
    void flatten(TreeNode* root) {
        stack<TreeNode*> stk;
        stack<TreeNode*> res;
        TreeNode* p = root;
        while( !stk.empty() || p != NULL){
            while(p != NULL){                
                res.push(p);
                stk.push(p);
                p = p->left;
            }            
            p = stk.top()->right;
            stk.pop();
        }
        
        TreeNode* pp = NULL;
        while( !res.empty() ){
            res.top()->right = pp;
            res.top()->left = NULL;
            
            pp = res.top();
            res.pop();                    
        }
    }
};
