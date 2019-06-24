/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 二叉树的后序遍历一般顺序是：左子树->右子树->根节点，而前序遍历的一般顺序是：根节点->左子树->右子树，只要稍微调整前序遍历为：根节点->右子树->左子树，再将遍历得到的序列进行反转即可

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> sta;
        vector<int> res;

        if(!root)
            return res;

        sta.push(root);

        while(sta.size())
        {
            TreeNode *now=sta.top();   
            sta.pop();

            res.push_back(now->val);
            
            if(now->left)
                sta.push(now->left);
            if(now->right)
                sta.push(now->right);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};