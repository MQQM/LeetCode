/*
  题目：
  给出二叉搜索树的根节点，该二叉树的节点值各不相同，修改二叉树，
  使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

  输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
  输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

  提示：
  树中的节点数介于 1 和 100 之间。
  每个节点的值介于 0 和 100 之间。
  给定的树为二叉搜索树。
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
class Solution
{
public:
    int sum = 0;
    TreeNode *bstToGst(TreeNode *root)
    { // 递归的方法
        if (root == NULL)
        {
            return NULL;
        }
        bstToGst(root->right);

        sum += root->val;
        root->val = sum;

        bstToGst(root->left);
        return root;
    }
};

class Solution
{
public:
    TreeNode *bstToGst(TreeNode *root)
    { // 非递归的方法
        int sum = 0;

        stack<TreeNode *> stk;
        TreeNode *p = root;
        while (!stk.empty() || p != NULL)
        {
            while (p != NULL)
            {
                stk.push(p);
                p = p->right;
            }

            sum += stk.top()->val;
            stk.top()->val = sum;

            p = stk.top()->left;
            stk.pop();
        }
        return root;
    }
};
