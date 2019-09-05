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
  
  进阶: 递归算法很简单，你可以通过迭代算法完成吗？
  
  非递归做法：
  后序遍历是：左-右-根，颠倒下顺序（可以用栈实现）就是：根-右-左。这就可以参考“先序遍历的非递归实现”。
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
    vector<int> postorderTraversal(TreeNode* root) {        
        stack<TreeNode*> res; // res这个栈 全pop出来 就是后序遍历
        
        stack<TreeNode*> stk;
        TreeNode* p = root;        
        while( !stk.empty() || p!=NULL ){            
            while( p!=NULL ){                 
                res.push(p);
                stk.push(p);              
                p = p->right;                
            }
            p = stk.top()->left;
            stk.pop();                
        }        
        
        vector<int> ret;
        while( !res.empty() ){
            ret.push_back( res.top()->val );
            res.pop();            
        }       
        return ret;
    }
};
