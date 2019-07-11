#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    TreeNode(string _val):val(_val),left(NULL),right(NULL)
    {
    }

    string val;
    TreeNode *left;
    TreeNode *right;
};

/**
 * buildTree: 从表达式的前序遍历和中序遍历序列构造表达式树
 * param preorder: 树的前序遍历序列
 * param inorder: 树的中序遍历序列
 * return: 所构造的表达式树的根结点
 */
TreeNode* buildTree(vector<string> &preorder, vector<string> &inorder)
{
    if(preorder.size()==0||inorder.size()==0)
    return NULL;

    // 1. 从前序遍历中弹出根结点的值，在中序遍历序列中查找根结点的位置
    string rootval=preorder[0];
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
    vector<string> left, right;
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
 * deleteTree: 删除并释放给定子树的内存 
 */
void deleteTree(TreeNode *root)
{
	if(!root)
	return;
	else
	{
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
		
		return;
	}
}

/**
 * delNode: 从树中删除根结点值为val的所有子树 
*/
TreeNode *delNode(TreeNode *root, string val)
{
	if(!root)
	return root;
	else if(root->val==val)
	{
		deleteTree(root);
		return NULL;
	}
	else
	{
		root->left=delNode(root->left,val);
		root->right=delNode(root->right, val);
		
		return root;
	}
}

void printTree(TreeNode *root)
{
	if(!root)
	return;
	
	queue<TreeNode *> que;
	
	que.push(root);
	
	while(que.size())
	{
		TreeNode *now=que.front();
		que.pop();
		cout<<now->val<<" ";
		
		if(now->left)
		que.push(now->left);
		if(now->right)
		que.push(now->right);
	}
	
	cout<<endl;
	
	return;
}

int main(void)
{
    vector<string> preorder1={"*", "+", "a", "b", "*", "c", "-", "d"};
    vector<string> inorder1={"a", "+", "b", "*", "c", "*", "-", "d"};
    
    vector<string> preorder2={"+", "*", "a", "b", "-", "-", "c", "d"};
    vector<string> inorder2={"a", "*", "b", "+", "-", "c", "-", "d"}; 

	TreeNode *root1=buildTree(preorder1, inorder1);
    root1=delNode(root1, "-");
    printTree(root1);
    
    TreeNode *root2=buildTree(preorder2, inorder2);
    root2=delNode(root2, "-");
    printTree(root2);
}

