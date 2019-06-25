/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 本题的实现较为简单，直接使用二叉树的非递归中序遍历即可完成

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> sta;
        int count=0;

        TreeNode *temp=root;
        while(temp)
        {
            sta.push(temp);
            temp=temp->left;
        }

        while(sta.size())
        {
            TreeNode *now=sta.top();
            sta.pop();
            count+=1;

            if(count==k)
                return now->val;

            temp=now->right;
            while(temp)
            {
                sta.push(temp);
                temp=temp->left;
            }
        }

        return -1;
    }
};