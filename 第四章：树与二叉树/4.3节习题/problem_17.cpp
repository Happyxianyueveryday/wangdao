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
 * buildTree: �ӱ��ʽ��ǰ�����������������й�����ʽ��
 * param preorder: ����ǰ���������
 * param inorder: ���������������
 * return: ������ı��ʽ���ĸ����
 */
TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if(preorder.size()==0||inorder.size()==0)
    return NULL;

    // 1. ��ǰ������е���������ֵ����������������в��Ҹ�����λ��
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

    // 2. ����������и��ڵ��λ��Ϊ�磬�������������һ��Ϊ����ǰ�벿��Ϊ������������������У���벿��Ϊ�������������������
    vector<int> left, right;
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
 * isSimilar: �ж����������Ķ������Ƿ�����
 * param root1: ����Ķ�����1
 * param root2: ����Ķ�����2
 * return: ����������Ķ��������ƣ��򷵻�true�����򷵻�false
 * note: ����ֱ��ʹ�ö�������жϼ��ɣ�
 		 (1) ������������һ��Ϊ�գ�һ��Ϊ�ǿգ��򷵻�false 
		 (2) ����������Ϊ�գ�������������Ϊ�������������������������������������Ӧ���ƣ��򷵻�true
		 (3) ����������򷵻�false
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
