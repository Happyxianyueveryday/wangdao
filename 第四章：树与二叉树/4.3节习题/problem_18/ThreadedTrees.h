#include <iostream> 
#include <string>
#include <stack>
#include "tree.h"

using namespace std; 


struct ThreadNode
{
    ThreadNode(int ival=0):val(ival),left(NULL),right(NULL),lflag(0),rflag(0)
    {
    }

    int val;
    ThreadNode *left;
    ThreadNode *right;
    int lflag;
    int rflag;
};


/*
 * ThreadTree: 中序遍历的二叉搜索线索树
 * note 1: 在普通二叉树中，可能存在许多的结点只有左子结点或者右子结点，或者是叶子结点，这时该结点中left和right成员就处于空置状态
 * note 2: 为了在左子结点/右子结点为空的情况下利用left和right成员，规定: 当左子结点为空时，使用left字段记录当前结点在中序遍历时的前驱结点；当右子结点为空时，使用right字段记录当前结点在中序遍历时的后继结点，并额外新增lflag和rflag表明left字段和right字段指向的是前后驱结点还是左右子结点，这就构成了二叉线索树 
*/
class ThreadTree
{
	public:  
	// 1. 构造函数 
	ThreadTree();                                                      // 默认构造函数 
	ThreadTree(const Tree &other);                                     // 从普通二叉搜索树生成对应的线索树
	
	// 2. 拷贝控制 
	ThreadTree(const ThreadTree &other);                               // 拷贝构造函数  
	ThreadTree & operator = (const ThreadTree &other) = delete;        // 禁止拷贝赋值运算符的使用 
	
	// 3. 测试函数：二叉线索树的后序遍历 
	vector<int> postorder();                                              // 获取当前线索树的后序遍历序列
	
	// 4. 析构函数
	~ThreadTree();
	
	private:
	ThreadNode *treeroot;     // 线索树的根结点 
	
	ThreadNode *getPrevNode(ThreadNode *pos);            // 线索树基本操作4：获取在中序遍历中当前结点的上一个结点 
	ThreadNode *getLastNode(ThreadNode *root);           // 线索树基本操作3: 获取给定的线索树中序遍历序列中的最后一个结点
	ThreadNode *__copyTree(TreeNode *root);                              // 从二叉搜索树拷贝一个线索树的底层递归实现
	
	// 5. 本题要实现的算法——查找给定结点在后序遍历中的前驱结点
	ThreadNode *getPostLastNode(ThreadNode *root);       // 获取当前线索树的后序遍历的首结点 
	ThreadNode *getPostPrevNode(ThreadNode *pos);        // 获取当前线索树的后序遍历中给定结点的前驱结点
};


/*
 * ThreadTree: 默认构造函数 
*/
ThreadTree::ThreadTree()
{
	treeroot=NULL;
}


/*
 * ThreadTree: 根据普通二叉搜索树生成对应的线索树
 * note: 从普通二叉搜索树生成线索树的算法步骤可以划分为简单两步：
 *       (1) 第一步，从原始二叉搜索树进行深拷贝；
 *       (2) 第二步，在拷贝结果上通过进行依次中序遍历进行线索化：若当前结点的left为NULL，则令left指向当前结点在中序遍历中的前驱结点；若当前结点的right为NULL，则令right指向当前结点在中序遍历中的后继结点；并修改对应的状态标记变量 
*/ 
ThreadTree::ThreadTree(const Tree &other)
{
	// 1. 首先从输入的源二叉搜索树进行深拷贝，得到一个二叉搜索树 
	treeroot=__copyTree(other.getroot());    
	
	// 2. 然后进行该二叉搜索树的线索化，通过一次中序遍历进行实现，这里使用非递归方法进行实现（关于普通二叉树的中序遍历请参见二叉搜索树的部分，本处不再重复介绍） 
	// note: 使用中序遍历每次访问一个结点，将正在访问的结点进行线索化 
	stack<ThreadNode *> sta;
	
	ThreadNode *temp=treeroot;     // 用于遍历的临时指针 
	ThreadNode *nowprev=NULL;      // 当前结点now的前驱结点指针 
	
	while(temp)
	{
		sta.push(temp);
		temp=temp->left;
	}
	
	while(sta.size())
	{
		// 2.1 进行中序遍历所需要的常规步骤 
		ThreadNode *now=sta.top();    // 当前正在访问的和准备进行线索化的结点 
		sta.pop();
		
		temp=now->right;
		
		while(temp)
		{
			sta.push(temp); 
			temp=temp->left;
		}
		
		// 2.2 对当前结点now进行线索化，线索化规则按照线索树的定义: 若now->left==NULL，则将now->left指向当前结点now的前驱结点nowprev；若now->right==NULL，则将now->right指向当前结点的后继结点（当前结点now后下一个访问的结点就是当前的栈顶结点）；并设置对应的标志变量 
		if(!now->left)
		{
			now->left=nowprev;
			now->lflag=1;
		}
		if(!now->right)
		{
			// 注意首先判断栈是否为空，若访问当前结点后栈为空，说明当前结点是中序遍历中的最后一个结点，没有后继结点 
			if(sta.size())
			now->right=sta.top();
			else
			now->right=NULL;
			
			now->rflag=1;
		}
		
		// 2.3 更新当前结点now的前驱结点nowprev
		nowprev=now; 
	}
}

ThreadNode *ThreadTree::__copyTree(TreeNode *root)
{
	if(!root)
	return NULL;
	else
	{
		ThreadNode *now=new ThreadNode(root->val);
		now->left=__copyTree(root->left);
		now->right=__copyTree(root->right);
		
		return now;
	}
}

/*
 * postorder: 获取当前中序线索树的后序遍历序列 
 * return: 当前线索树中序线索树的反向后序遍历序列 
*/
vector<int> ThreadTree::postorder()
{
	// 1. 获取后序遍历的尾结点 
	vector<int> res;
	ThreadNode *now=getPostLastNode(treeroot);   
	
	// 2. 获取后序遍历中当前结点的前驱结点 
	while(now)
	{
		res.push_back(now->val);
		now=getPostPrevNode(now);
	}
	
	return res;
}

/*
 * getLastNode: 线索树基本操作3: 获取给定的线索树中序遍历序列中的最后一个结点
 * param root: 输入的给定线索树的根结点 
 * return: 给定的线索树的中序遍历的最后一个结点
 * note: 给定一个线索树，其中序遍历的最后一个结点必然是整个线索树中最右侧的结点，因此一直沿着右子结点的方向直到整个树最右侧的结点，返回该结点即可 
*/
ThreadNode *ThreadTree::getLastNode(ThreadNode *root)
{
	ThreadNode *now=root;	
	
	while(now&&!now->rflag)
	{
		now=now->right;
	}
	
	return now;
}   

/*
 * getPrevNode: 线索树基本操作4：获取在中序遍历中当前结点的上一个结点
 * param pos: 输入的线索树结点 
 * return: 给定的结点在中序遍历中的上一个结点 
 * note: 给定一个线索树中的某个结点，要获得该结点在中序遍历中的上一个结点，站在中序遍历的角度上思考，其思路非常简单：
 *       (1) 若输入结点pos的lflag==1，根据二叉线索树结点的定义，这时沿着left必定能够达到后继结点，故直接返回pos->left；
 *       (2) 若输入结点pos的lflag==0，这时当前结点存在左子树，因为当前结点pos已经输出，因此中序遍历中的前驱结点是当前结点的左子树pos->left中的中序遍历的最后一个结点，故直接返回getLastNode(pos->left)
*/          
ThreadNode *ThreadTree::getPrevNode(ThreadNode *pos)
{
	if(pos->lflag)	
	return pos->left;
	else
	return getLastNode(pos->left);
}

/*
 * getPostLastNode: 获取当前中序线索树的后序遍历序列的最后一个结点 
 * param root: 当前的中序线索树的根结点 
 * return: 后序遍历中的最后一个结点 
*/
ThreadNode *ThreadTree::getPostLastNode(ThreadNode *root)
{
	// 1. 当前中序线索树的后序遍历序列中的最后一个结点就是线索树的根结点，故直接返回根结点即可 
	return root;
}

/*
 * getPostLastNode: 获取当前结点在中序线索树的后序遍历序列中的前驱结点 
 * param pos: 当前的中序线索树结点 
 * return: 当前结点在后序遍历序列中的前驱结点 
*/
ThreadNode *ThreadTree::getPostPrevNode(ThreadNode *pos)
{
	// 1. 若在中序线索树中，当前结点存在右子树，则当前结点在后序遍历中的前驱结点一定是右子树在后序遍历中的最后一个结点 
	if(pos->rflag==0)
	return getPostLastNode(pos->right);
	
	// 2. 若在中序线索树中，当前结点不存在右子树，但是存在左子树，则当前结点在后序遍历中的前驱结点一定是左子树在后序遍历中的最后一个结点 
	else if(pos->lflag==0)
	return getPostLastNode(pos->left);
	
	// 3. 若在中序线索树中，当前结点既不存在右子树，也不存在左子树，这时根据线索树的定义，当前结点的左子结点指向中序遍历的前驱结点，右子结点指向中序遍历的后继结点，但是问题是需要求解的是后序遍历的前驱结点 
	// 因此，需要沿着中序序列中的前驱结点一路前进，直到遇到一个结点，该结点具有左子结点 
	else
	{
		// 3.1 不断查找当前结点的前驱结点，直到遇到一个具有左子树的结点（因为只有不存在左子树的结点，其左子结点指向当前结点在中序遍历中的前驱结点） 
		while(pos->lflag==1&&pos->left!=NULL)   
		{
			pos=pos->left;
		}
		
		// 3.2 若当前结点的左子树为空，即pos->lflag==1，且不存在前驱结点，即pos->left==NULL，则说明当前结点就是首结点，返回NULL 
		if(pos->lflag==1&&pos->left==NULL)
		return NULL;
		else
		return pos->left;
	}
}

/*
 * ~ThreadTree: 析构函数 
 * note: 同样可以按照中序遍历的顺序来进行析构，使用getFirstNode和getNextNode两个方法进行遍历的同时进行删除即可 
*/
ThreadTree::~ThreadTree()
{
	ThreadNode *now=getLastNode(treeroot);
	
	while(now)
	{
		ThreadNode *temp=now;
		now=getPrevNode(now);
		delete temp; 
	}
}
