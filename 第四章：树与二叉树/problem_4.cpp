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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        queue<pair<TreeNode *, int> > que;

        if(!root)
            return res;
        
        que.push(make_pair(root, 0));

        while(que.size())
        {
            pair<TreeNode *, int> now=que.front();
            que.pop();

            if(now.second>=res.size())
            {
                vector<int> temp;
                res.push_back(temp);
                res[now.second].push_back(now.first->val);
            }
            else
                res[now.second].push_back(now.first->val);

            if(now.first->left)
                que.push(make_pair(now.first->left, now.second+1));
            if(now.first->right)
                que.push(make_pair(now.first->right, now.second+1));
        }

        reverse(res.begin(), res.end());

        return res;
    }
};