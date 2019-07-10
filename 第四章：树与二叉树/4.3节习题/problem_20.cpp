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
 * buildTree: �ӱ��ʽ��ǰ�����������������й�����ʽ��
 * param preorder: ����ǰ���������
 * param inorder: ���������������
 * return: ������ı��ʽ���ĸ����
 */
TreeNode* buildTree(vector<string> &preorder, vector<string> &inorder)
{
    if(preorder.size()==0||inorder.size()==0)
    return NULL;

    // 1. ��ǰ������е���������ֵ����������������в��Ҹ�����λ��
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

    // 2. ����������и��ڵ��λ��Ϊ�磬�������������һ��Ϊ����ǰ�벿��Ϊ������������������У���벿��Ϊ�������������������
    vector<string> left, right;
    for(int i=0;i<inorder.size();i++)
    {
        if(i<index)
        left.push_back(inorder[i]);
        else if(i>index)
        right.push_back(inorder[i]);
    }


    // 3. ���ȹ������㣬Ȼ���������������������к�������������������У��ݹ��������������������
    TreeNode *root=new TreeNode(rootval);
    root->left=buildTree(preorder, left);
    root->right=buildTree(preorder, right);
    
    return root;
}

void inorderTree(TreeNode *root, string &res);
/**
 * treeConvertExp: �ӱ��ʽ�����ɱ��ʽ
 * param root: ���ĸ����
 * return: �ӱ��ʽ�����ɵ�ԭʼ��׺���ʽ
 * note: ��ԭ���ʽ������һ������������ɣ�ע����Ҫ�����ţ������ŵĹ���ܼ򵥣��ڷ���������֮ǰ�������ţ��ڷ���������֮��������ţ�������Ҫ�ر�ע�⣬������ǰ����ֵΪ����ʱ����Ҫ������ 
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

