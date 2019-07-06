#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 本题中使用的算法较为简单，因为满二叉树不存在空结点，因此本题中所使用的算法可以简述为以下的步骤：
// (1) 若输入的前序遍历序列只有一个元素或者为空，则为单结点树或者空树，这时后序遍历等于前序遍历，故直接返回输入的前序遍历序列 
// (2) 否则，从前序遍历序列中删除首元素，删除的首元素就是当前的根结点的值 
// (3) 将剩下的前序遍历序列分割为元素数量相等的两段，前半部分就是左子树的前序遍历序列，后半部分就是右子树的前序遍历序列 
// (4) 从左子树的前序遍历序列递归地生成左子树的后序遍历，从右子树的前序遍历序列递归地生成右子树的后序遍历 
// (5) 重新依次将上述得到的左子树的后序遍历，右子树的后序遍历，根结点的值拼接起来，就得到最终当前树的后序遍历序列 
        
vector<int> getPostFromPre(vector<int> pre) 
{
    // 0. 若前序遍历中仅有一个元素或者空，则为单结点树或者空树，直接返回输入的前序遍历序列即可
    if(pre.size()==1||pre.size()==0)
    return pre;
    else
    {
        vector<int> leftpre, rightpre;  // 左子树和右子树的前序遍历序列

        int rootval=pre[0];             // 根结点就是前序遍历中的第一个结点
        pre.erase(pre.begin());         // 删除根结点
        
        // 1. 生成左子树和右子树的前序遍历序列
        for(int i=0;i<pre.size();i++)
        {
            if(i<pre.size()/2)          // 删除前序遍历中的根结点后，前半部分就是左子树的前序遍历
            leftpre.push_back(pre[i]);
            else                        // 删除前序遍历中的根结点后，后半部分就是右子树的前序遍历
            rightpre.push_back(pre[i]);
        }

        // 2. 递归生成左右子树的后序遍历序列
        vector<int> leftpost=getPostFromPre(leftpre);
        vector<int> rightpost=getPostFromPre(rightpre);

        // 3. 依次将左子树的后序遍历序列，右子树的后序遍历，根结点的值组合起来，就得到当前的树的后序遍历序列
        vector<int> res;

        for(int i=0;i<leftpost.size();i++)
        {
            res.push_back(leftpost[i]);
        }

        for(int i=0;i<rightpost.size();i++)
        {
            res.push_back(rightpost[i]);
    	}
        res.push_back(rootval);

        return res;
    }
}

int main(void)
{
    vector<int> pre={1,2,4,5,3,6,7};
    vector<int> post=getPostFromPre(pre);

    for(int i=0;i<post.size();i++)
    {
        cout<<post[i]<<" ";
    }
    cout<<endl;
}

