/*
  题目：
  给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。
  如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 
  给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。

  示例 1:
  输入: 
      2
     / \
    2   5
       / \
      5   7
  输出: 5
  说明: 最小的值是 2 ，第二小的值是 5 。

  示例 2:
  输入: 
      2
     / \
    2   2
  输出: -1
  说明: 最小的值是 2, 但是不存在第二小的值。

  参考：
  https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/solution/ji-bai-liao-100de-javayong-hu-by-reedfan/
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
    int findSecondMinimumValue(TreeNode *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return -1;
        }

        int left = root->left->val;
        int right = root->right->val;
        if (left == root->val)
        {
            left = findSecondMinimumValue(root->left);
        }
        if (right == root->val)
        {
            right = findSecondMinimumValue(root->right);
        }

        if (left != -1 && right != -1)
        {
            return min(left, right);
        }
        if (left != -1)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
};
