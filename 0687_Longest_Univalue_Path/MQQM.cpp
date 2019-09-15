/*
  题目：
  给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。
  注意：两个节点之间的路径长度由它们之间的边数表示。
  
  示例 1:
  输入:
              5
             / \
            4   5
           / \   \
          1   1   5
  输出:
  2

  示例 2:
  输入:
              1
             / \
            4   5
           / \   \
          4   4   5
  输出:
  2

  注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。

  参考：
  https://leetcode-cn.com/problems/longest-univalue-path/solution/jian-dan-yi-dong-ban-by-a380922457-7/
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
    int ans = 0;
    int gg(TreeNode *p)
    {
        if (p == NULL)
        {
            return 0;
        }

        int left = gg(p->left);
        int right = gg(p->right);
        // 回溯
        left = (p->left != NULL && p->left->val == p->val) ? left + 1 : 0;
        right = (p->right != NULL && p->right->val == p->val) ? right + 1 : 0;

        ans = max(ans, left + right);
        return max(left, right);
    }
    int longestUnivaluePath(TreeNode *root)
    {
        gg(root);
        return ans;
    }
};
