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
 * ThreadTree: ��������Ķ�������������
 * note 1: ����ͨ�������У����ܴ������Ľ��ֻ�����ӽ��������ӽ�㣬������Ҷ�ӽ�㣬��ʱ�ý����left��right��Ա�ʹ��ڿ���״̬
 * note 2: Ϊ�������ӽ��/���ӽ��Ϊ�յ����������left��right��Ա���涨: �����ӽ��Ϊ��ʱ��ʹ��left�ֶμ�¼��ǰ������������ʱ��ǰ����㣻�����ӽ��Ϊ��ʱ��ʹ��right�ֶμ�¼��ǰ������������ʱ�ĺ�̽�㣬����������lflag��rflag����left�ֶκ�right�ֶ�ָ�����ǰ������㻹�������ӽ�㣬��͹����˶��������� 
*/
class ThreadTree
{
	public:  
	// 1. ���캯�� 
	ThreadTree();                                                      // Ĭ�Ϲ��캯�� 
	ThreadTree(const Tree &other);                                     // ����ͨ�������������ɶ�Ӧ��������
	
	// 2. �������� 
	ThreadTree(const ThreadTree &other);                               // �������캯��  
	ThreadTree & operator = (const ThreadTree &other) = delete;        // ��ֹ������ֵ�������ʹ�� 
	
	// 3. ���Ժ����������������ĺ������ 
	vector<int> postorder();                                              // ��ȡ��ǰ�������ĺ����������
	
	// 4. ��������
	~ThreadTree();
	
	private:
	ThreadNode *treeroot;     // �������ĸ���� 
	
	ThreadNode *getPrevNode(ThreadNode *pos);            // ��������������4����ȡ����������е�ǰ������һ����� 
	ThreadNode *getLastNode(ThreadNode *root);           // ��������������3: ��ȡ������������������������е����һ�����
	ThreadNode *__copyTree(TreeNode *root);                              // �Ӷ�������������һ���������ĵײ�ݹ�ʵ��
	
	// 5. ����Ҫʵ�ֵ��㷨�������Ҹ�������ں�������е�ǰ�����
	ThreadNode *getPostLastNode(ThreadNode *root);       // ��ȡ��ǰ�������ĺ���������׽�� 
	ThreadNode *getPostPrevNode(ThreadNode *pos);        // ��ȡ��ǰ�������ĺ�������и�������ǰ�����
};


/*
 * ThreadTree: Ĭ�Ϲ��캯�� 
*/
ThreadTree::ThreadTree()
{
	treeroot=NULL;
}


/*
 * ThreadTree: ������ͨ�������������ɶ�Ӧ��������
 * note: ����ͨ�����������������������㷨������Ի���Ϊ��������
 *       (1) ��һ������ԭʼ�������������������
 *       (2) �ڶ������ڿ��������ͨ���������������������������������ǰ����leftΪNULL������leftָ��ǰ�������������е�ǰ����㣻����ǰ����rightΪNULL������rightָ��ǰ�������������еĺ�̽�㣻���޸Ķ�Ӧ��״̬��Ǳ��� 
*/ 
ThreadTree::ThreadTree(const Tree &other)
{
	// 1. ���ȴ������Դ��������������������õ�һ������������ 
	treeroot=__copyTree(other.getroot());    
	
	// 2. Ȼ����иö�������������������ͨ��һ�������������ʵ�֣�����ʹ�÷ǵݹ鷽������ʵ�֣�������ͨ�����������������μ������������Ĳ��֣����������ظ����ܣ� 
	// note: ʹ���������ÿ�η���һ����㣬�����ڷ��ʵĽ����������� 
	stack<ThreadNode *> sta;
	
	ThreadNode *temp=treeroot;     // ���ڱ�������ʱָ�� 
	ThreadNode *nowprev=NULL;      // ��ǰ���now��ǰ�����ָ�� 
	
	while(temp)
	{
		sta.push(temp);
		temp=temp->left;
	}
	
	while(sta.size())
	{
		// 2.1 ���������������Ҫ�ĳ��沽�� 
		ThreadNode *now=sta.top();    // ��ǰ���ڷ��ʵĺ�׼�������������Ľ�� 
		sta.pop();
		
		temp=now->right;
		
		while(temp)
		{
			sta.push(temp); 
			temp=temp->left;
		}
		
		// 2.2 �Ե�ǰ���now�������������������������������Ķ���: ��now->left==NULL����now->leftָ��ǰ���now��ǰ�����nowprev����now->right==NULL����now->rightָ��ǰ���ĺ�̽�㣨��ǰ���now����һ�����ʵĽ����ǵ�ǰ��ջ����㣩�������ö�Ӧ�ı�־���� 
		if(!now->left)
		{
			now->left=nowprev;
			now->lflag=1;
		}
		if(!now->right)
		{
			// ע�������ж�ջ�Ƿ�Ϊ�գ������ʵ�ǰ����ջΪ�գ�˵����ǰ�������������е����һ����㣬û�к�̽�� 
			if(sta.size())
			now->right=sta.top();
			else
			now->right=NULL;
			
			now->rflag=1;
		}
		
		// 2.3 ���µ�ǰ���now��ǰ�����nowprev
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
 * postorder: ��ȡ��ǰ�����������ĺ���������� 
 * return: ��ǰ�����������������ķ������������� 
*/
vector<int> ThreadTree::postorder()
{
	// 1. ��ȡ���������β��� 
	vector<int> res;
	ThreadNode *now=getPostLastNode(treeroot);   
	
	// 2. ��ȡ��������е�ǰ����ǰ����� 
	while(now)
	{
		res.push_back(now->val);
		now=getPostPrevNode(now);
	}
	
	return res;
}

/*
 * getLastNode: ��������������3: ��ȡ������������������������е����һ�����
 * param root: ����ĸ����������ĸ���� 
 * return: ��������������������������һ�����
 * note: ����һ������������������������һ������Ȼ�����������������Ҳ�Ľ�㣬���һֱ�������ӽ��ķ���ֱ�����������Ҳ�Ľ�㣬���ظý�㼴�� 
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
 * getPrevNode: ��������������4����ȡ����������е�ǰ������һ�����
 * param pos: �������������� 
 * return: �����Ľ������������е���һ����� 
 * note: ����һ���������е�ĳ����㣬Ҫ��øý������������е���һ����㣬վ����������ĽǶ���˼������˼·�ǳ��򵥣�
 *       (1) ��������pos��lflag==1�����ݶ������������Ķ��壬��ʱ����left�ض��ܹ��ﵽ��̽�㣬��ֱ�ӷ���pos->left��
 *       (2) ��������pos��lflag==0����ʱ��ǰ����������������Ϊ��ǰ���pos�Ѿ�����������������е�ǰ������ǵ�ǰ����������pos->left�е�������������һ����㣬��ֱ�ӷ���getLastNode(pos->left)
*/          
ThreadNode *ThreadTree::getPrevNode(ThreadNode *pos)
{
	if(pos->lflag)	
	return pos->left;
	else
	return getLastNode(pos->left);
}

/*
 * getPostLastNode: ��ȡ��ǰ�����������ĺ���������е����һ����� 
 * param root: ��ǰ�������������ĸ���� 
 * return: ��������е����һ����� 
*/
ThreadNode *ThreadTree::getPostLastNode(ThreadNode *root)
{
	// 1. ��ǰ�����������ĺ�����������е����һ���������������ĸ���㣬��ֱ�ӷ��ظ���㼴�� 
	return root;
}

/*
 * getPostLastNode: ��ȡ��ǰ����������������ĺ�����������е�ǰ����� 
 * param pos: ��ǰ��������������� 
 * return: ��ǰ����ں�����������е�ǰ����� 
*/
ThreadNode *ThreadTree::getPostPrevNode(ThreadNode *pos)
{
	// 1. ���������������У���ǰ����������������ǰ����ں�������е�ǰ�����һ�����������ں�������е����һ����� 
	if(pos->rflag==0)
	return getPostLastNode(pos->right);
	
	// 2. ���������������У���ǰ��㲻���������������Ǵ�������������ǰ����ں�������е�ǰ�����һ�����������ں�������е����һ����� 
	else if(pos->lflag==0)
	return getPostLastNode(pos->left);
	
	// 3. ���������������У���ǰ���Ȳ�������������Ҳ����������������ʱ�����������Ķ��壬��ǰ�������ӽ��ָ�����������ǰ����㣬���ӽ��ָ����������ĺ�̽�㣬������������Ҫ�����Ǻ��������ǰ����� 
	// ��ˣ���Ҫ�������������е�ǰ�����һ·ǰ����ֱ������һ����㣬�ý��������ӽ�� 
	else
	{
		// 3.1 ���ϲ��ҵ�ǰ����ǰ����㣬ֱ������һ�������������Ľ�㣨��Ϊֻ�в������������Ľ�㣬�����ӽ��ָ��ǰ�������������е�ǰ����㣩 
		while(pos->lflag==1&&pos->left!=NULL)   
		{
			pos=pos->left;
		}
		
		// 3.2 ����ǰ����������Ϊ�գ���pos->lflag==1���Ҳ�����ǰ����㣬��pos->left==NULL����˵����ǰ�������׽�㣬����NULL 
		if(pos->lflag==1&&pos->left==NULL)
		return NULL;
		else
		return pos->left;
	}
}

/*
 * ~ThreadTree: �������� 
 * note: ͬ�����԰������������˳��������������ʹ��getFirstNode��getNextNode�����������б�����ͬʱ����ɾ������ 
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
