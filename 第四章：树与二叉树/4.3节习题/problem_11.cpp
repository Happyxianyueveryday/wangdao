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

/**
 * deleteTree: ɾ�����ͷŸ����������ڴ� 
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
 * delNode: ������ɾ�������ֵΪval���������� 
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

