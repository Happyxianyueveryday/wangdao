/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 本题的算法较为简单：直接使用任意一种遍历遍历树中的每个结点，若当前结点存在左子树和右子树，则将计数器加1

class Solution {
public:
    int countNode(TreeNode* root) {
        int count=0;

        if(!root)
            return count;
        
        queue<TreeNode *> que;
        que.push(root);

        while(que.size())
        {
            TreeNode *root=que.front();

            if(root->left&&root->right)
                count+=1;

            if(root->left)
                que.push(root->left);
            if(root->right)
                que.push(root->right);
        }

        return count;
    }
};