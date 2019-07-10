#include <iostream>
#include <string>
#include <vector>

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
 * isSimilar: 判断两个给定的二叉树是否相似
 * param root1: 输入的二叉树1
 * param root2: 输入的二叉树2
 * return: 若两个输入的二叉树相似，则返回true；否则返回false
 * note: 本题直接使用定义进行判断即可：
 		 (1) 若两个输入树一个为空，一个为非空，则返回false 
		 (2) 若两个树均为空，或者两个树均为单结点树，或者两棵树的左子树和右子树对应相似，则返回true
		 (3) 其他情况，则返回false
 */
bool isSimilar(TreeNode *root1, TreeNode *root2)
{
	if(root1&&!root2 || !root1&&root2)
	return false;
    else if(!root1&&!root2 || root1&&root2&&!root1->left&&!root1->right&&!root2->left&&!root2->right || isSimilar(root1->left, root2->left)&&isSimilar(root1->right, root2->right))
    return true;
    else
    return false;
}

int main(void)
{
    vector<int> preorder1={12,5,2,9,18,15,17,16,19};
	vector<int> inorder1={2,5,9,12,15,16,17,18,19};

    vector<int> preorder2={12,5,2,10,18,15,17,16,19};
    vector<int> inorder2={2,5,10,12,15,16,17,18,19};
    
	vector<int> preorder3={12,5,2,10,18};
    vector<int> inorder3={2,5,10,12,18};

    TreeNode *root1=buildTree(preorder1, inorder1);
    TreeNode *root2=buildTree(preorder2, inorder2);
    TreeNode *root3=buildTree(preorder3, inorder3);

	
    cout<<isSimilar(root1, root2)<<endl;
    cout<<isSimilar(root1, root3)<<endl;
    cout<<isSimilar(root2, root3)<<endl;
}
