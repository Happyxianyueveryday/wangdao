#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    TreeNode(int _val):val(_val),left(NULL),right(NULL)
    {
    }

    int val;
    TreeNode *left;
    TreeNode *right;
};

/**
 * buildTree: 从表达式的前序遍历和中序遍历序列构造表达式树
 * param preorder: 树的前序遍历序列
 * param inorder: 树的中序遍历序列
 * return: 所构造的表达式树的根结点
 */
TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if(preorder.size()==0||inorder.size()==0)
    return NULL;

    // 1. 从前序遍历中弹出根结点的值，在中序遍历序列中查找根结点的位置
    int rootval=preorder[0];
    preorder.erase(preorder.begin());
    int index=-1;

    for(int i=0;i<inorder.size();i++)
    {
        if(inorder[i]==rootval)
        {
            index=i;
            break;
        }
    }

    // 2. 以中序遍历中根节点的位置为界，将中序遍历序列一分为二，前半部分为左子树的中序遍历序列，后半部分为右子树的中序遍历序列
    vector<int> left, right;
    for(int i=0;i<inorder.size();i++)
    {
        if(i<index)
        left.push_back(inorder[i]);
        else if(i>index)
        right.push_back(inorder[i]);
    }


    // 3. 首先构造根结点，然后从左子树的中序遍历序列和右子树的中序遍历序列，递归地生成左子树和右子树
    TreeNode *root=new TreeNode(rootval);
    root->left=buildTree(preorder, left);
    root->right=buildTree(preorder, right);
    
    return root;
}

/**
 * getAnsOfNode: 获得给定值的结点（题目假设只有一个指定值的结点）的所有父结点
 * param root: 当前树的根结点
 * param nodeval: 目标结点的值
 * return: 目标结点的所有父结点
 * note: 本题实际上只需要使用一次后序遍历即可完成，一旦当前结点的值和目标结点相等，则直接出栈直到栈为空为止，出栈的这些结点就是目标结点的父结点
 */
vector<TreeNode *> getAnsOfNode(TreeNode *root, int nodeval)
{
	vector<TreeNode *> res;
	
	if(!root)
	return res;
	
	stack<TreeNode *> sta;
	TreeNode *temp=root;
	
	while(temp)
	{
		sta.push(temp);
		temp=temp->left;
	}
	sta.push(temp);
	
	while(sta.size())
	{
		TreeNode *now=sta.top();
		sta.pop();
		
		if(now&&now->val==nodeval)
		{
			while(sta.size())
			{
				res.push_back(sta.top());
				sta.pop();
			}
			return res;
		}
		else if(sta.size()&&sta.top()->right!=now)
		{
			TreeNode *temp=sta.top()->right;
			
			while(temp)
			{
				sta.push(temp);
				temp=temp->left;
			}
			sta.push(temp);
		}
	}
	
	return res;
}

int main(void)
{
    vector<int> preorder={12,5,2,9,18,15,17,16,19};
	vector<int> inorder={2,5,9,12,15,16,17,18,19};

    TreeNode *root=buildTree(preorder, inorder);

    vector<TreeNode *> res=getAnsOfNode(root, 16);

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]->val<<" ";
    }
    cout<<endl;
}


