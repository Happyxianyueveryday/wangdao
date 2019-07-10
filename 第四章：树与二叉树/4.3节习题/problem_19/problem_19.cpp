#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

/**
 * real_calTreeWPL: 生成各个叶子结点的值与到根结点的路径长度的乘积
 * param root: 树中的当前结点
 * param step: 当前结点到树的根结点的路径长度
 * param lis: 各个叶子结点的值与到根结点的路径长度的乘积的列表
 */
void real_calTreeWPL(TreeNode *root, int step, vector<int> &lis)
{
    if(!root)
    return;

    // 1. 若当前的结点为叶子结点，则计算叶子结点的值和到根结点的路径长度的乘积，并加入到结果链表中
    else if(!root->left&&!root->right)
    {
        int res=root->val*step;
        lis.push_back(res);
        return;
    }

    // 2. 若当前的结点为非叶子结点，则进一步递归访问当前结点的左子树和右子树
    else
    {
        real_calTreeWPL(root->left, step+1, lis);
        real_calTreeWPL(root->right,step+1, lis);
        return;
    }
}

/**
 * calTreeWPL: 计算二叉树的WPL
 * param root: 二叉树的根结点
 * return: 输入二叉树的WPL
 * note: 二叉树的每个叶子结点到根结点的路径长度（树中每条边的长度设为1）与该叶子结点的值的乘积之和，即称为WPL
 */
int calTreeWPL(TreeNode *root)
{
    vector<int> lis;

    real_calTreeWPL(root, 0, lis);

    int res=0;
    for(int i=0;i<lis.size();i++)
    {
        res+=lis[i];
    }

    return res;
}


int main(void)
{
    vector<int> preorder={12,5,2,9,18,15,17,16,19};
	vector<int> inorder={2,5,9,12,15,16,17,18,19};

	Tree tree2(inorder,preorder);   // ��ȷWPL=2*2+9*2+16*4+19*2=124 
	
    cout<<calTreeWPL(tree2.getRoot())<<endl;
}
