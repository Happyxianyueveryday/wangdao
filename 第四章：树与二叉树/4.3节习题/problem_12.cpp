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
 * getAnsOfNode: ��ø���ֵ�Ľ�㣨��Ŀ����ֻ��һ��ָ��ֵ�Ľ�㣩�����и����
 * param root: ��ǰ���ĸ����
 * param nodeval: Ŀ�����ֵ
 * return: Ŀ��������и����
 * note: ����ʵ����ֻ��Ҫʹ��һ�κ������������ɣ�һ����ǰ����ֵ��Ŀ������ȣ���ֱ�ӳ�ջֱ��ջΪ��Ϊֹ����ջ����Щ������Ŀ����ĸ����
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


