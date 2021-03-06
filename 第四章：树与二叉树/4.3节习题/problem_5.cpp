/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 二叉树的高度和最大深度的求解算法是一致的: 使用递归方法进行求解即可，树root的最大深度等于左子树和右子树中的深度较大值加1
// 如果需要使用非递归算法，基本思想也非常简单，直接进行一次层次遍历即可，总共计算到多少层，就是所求的高度

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        else
        {
            int left=maxDepth(root->left);
            int right=maxDepth(root->right);
            return ((left>right)?left:right)+1;
        }
    }
};