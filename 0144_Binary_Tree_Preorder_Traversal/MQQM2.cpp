/*
  题目：
  给定一个二叉树，返回它的 前序 遍历。
  
  示例:
  输入: [1,null,2,3]  
     1
      \
       2
      /
     3 
  输出: [1,2,3]
  
  进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 
  做法：这个方法是非递归的
  https://www.cnblogs.com/hlk09/p/9779246.html
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        
        stack<TreeNode*> stk;
        TreeNode* p = root;
        while( !stk.empty() || p!=NULL ){ // 注意这里           
            while(p!=NULL){             
                res.push_back(p->val);
                stk.push(p);             
                p=p->left;
            }
            p = stk.top()->right;
            stk.pop();            
        }
                
        return res;
    }
};
