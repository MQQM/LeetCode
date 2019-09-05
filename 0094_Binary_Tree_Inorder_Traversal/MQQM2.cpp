/*
  题目：
  给定一个二叉树，返回它的 中序 遍历。
 
  示例:
  输入: [1,null,2,3]
     1
      \
       2
      /
     3
  输出: [1,3,2]

  进阶: 递归算法很简单，你可以通过迭代算法完成吗？

  做法：非递归
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        TreeNode* p = root;
        stack<TreeNode*> stk;        
        while( !stk.empty() || p!=NULL ){
            while(p!=NULL){
                stk.push(p);
                p = p->left;
            }
            res.push_back(stk.top()->val); // 注意这里
            p = stk.top()->right;
            stk.pop();
        }
        
        return res;
    }
};
