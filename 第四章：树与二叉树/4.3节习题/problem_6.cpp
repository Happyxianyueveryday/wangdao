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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size()||!inorder.size())
            return NULL;
        
        // 1. 前序遍历序列的首元素就是根结点
        TreeNode *root=new TreeNode(preorder[0]);   
        preorder.erase(preorder.begin());    // 弹出根结点

        // 2. 在中序遍历序列中查找根结点的值的位置，该位置左侧为根结点的左子树，该位置右侧为根结点的右子树
        vector<int> left, right;
        int index=-1;
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==root->val)
            {
                index=i;
                break;
            }
        }
        for(int i=0;i<inorder.size();i++)
        {
            if(i<index)
                left.push_back(inorder[i]);
            if(i>index)
                right.push_back(inorder[i]);
        }

        // 3. 递归生成根结点的左子树和右子树
        root->left=buildTree(preorder, left);
        root->right=buildTree(preorder, right);

        return root;
    }
};