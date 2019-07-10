#include <iostream>
#include <string>
#include <vector>

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

void inorderTree(TreeNode *root, string &res);
/**
 * treeConvertExp: 从表达式树生成表达式
 * param root: 树的根结点
 * return: 从表达式树生成的原始中缀表达式
 * note: 对原表达式树进行一次中序遍历即可，注意需要加括号，加括号的规则很简单：在访问左子树之前加左括号，在访问右子树之后加右括号，但是需要特别注意，仅当当前结点的值为符号时才需要加括号 
 */
string treeConvertExp(TreeNode *root)
{
    string res;
    inorderTree(root, res);
    return res;
}

void inorderTree(TreeNode *root, string &res)
{
    if(!root)
    return;
    else
    {
        res+=((root->val=="+"||root->val=="-"||root->val=="*"||root->val=="/")?"(":"");
        
        inorderTree(root->left, res);
        res+=root->val;
        inorderTree(root->right, res);
        
        res+=((root->val=="+"||root->val=="-"||root->val=="*"||root->val=="/")?")":"");

        return;
    }
}

int main(void)
{
    vector<string> preorder1={"*", "+", "a", "b", "*", "c", "-", "d"};
    vector<string> inorder1={"a", "+", "b", "*", "c", "*", "-", "d"};
    
    vector<string> preorder2={"+", "*", "a", "b", "-", "-", "c", "d"};
    vector<string> inorder2={"a", "*", "b", "+", "-", "c", "-", "d"}; 

	TreeNode *root1=buildTree(preorder1, inorder1);
    cout<<treeConvertExp(root1)<<endl;
    
    TreeNode *root2=buildTree(preorder2, inorder2);
    cout<<treeConvertExp(root2)<<endl;
}

