#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue> 

using namespace std;

struct TreeNode
{
    TreeNode(int ival=0):val(ival),left(NULL),right(NULL)
    {
    }

    int val;
    TreeNode *left;
    TreeNode *right;
};

class Tree
{
    public:
    // 1. ���캯��
    Tree();     // Ĭ�Ϲ��캯��
    Tree(vector<int> inorder, vector<int> preorder);              // �����������ǰ������������������
    Tree(vector<int> inorder, vector<int> postorder, int flag);   // ����������ͺ���������������������flag��Ϊ��������Ĺ�����Ʋ��� 

    // 2. ��������
    Tree(const Tree &other);                  // �������캯��
    Tree & operator = (const Tree &other);    // ������ֵ�����

    // 3. ���ܺ���
    vector<int> preorder() const;             // �ǵݹ��ǰ�����
    vector<int> inorder() const;              // �ǵݹ���������
    vector<int> postorder() const;            // �ǵݹ�ĺ������
    vector<int> levelorder() const;           // ���Ĳ�α���

    void insert(int val);                     // ����������    
    void remove(int val);                     // ����ɾ�����
    TreeNode *search(int val);                // �����и���ֵ���ҽ��ĵ�ַ
    TreeNode *getroot() const;                // ��ȡ�����������ĸ�����ַ��ע������Ϊconst��Ա����  

    TreeNode *lca(TreeNode *p, TreeNode *q);  // �ڶ����������в����������(�Ե�ַ��ʽ����)������������ڵ�
    TreeNode *lca(int p, int q);              // �ڶ����������в����������(��ֵ��ʽ����)������������ڵ�
    
    int depth();                              // ��������������/�߶�
    int size();                               // �������Ľ�����
    int maxpath();                            // �������е����·����(���ｫ��ǰ����Ϊ��ͨ������)
    int maxrlpath();                          // �������дӸ��ڵ㵽Ҷ�ӽ������·����

    // 4. ��������
    ~Tree();                                  // ������������

    private:
    TreeNode *treeroot;                       // ���ĸ����

    TreeNode *__buildTree1(vector<int> &inorder, vector<int> &preorder);    
    TreeNode *__buildTree2(vector<int> &inorder, vector<int> &postorder);
    TreeNode *__copyTree(TreeNode *root);
    void __deleteTree(TreeNode *root);
    int __findIndex(const vector<int> &lis, int tar);
    TreeNode *__insertTree(TreeNode *root, int val);
    TreeNode *__searchTree(TreeNode *root, int val);
    TreeNode *__deleteTree(TreeNode *root, int val);
    TreeNode *__lcaTree1(TreeNode *root, TreeNode *p, TreeNode *q);
    TreeNode *__lcaTree2(TreeNode *root, int p, int q);
    int __depthTree(TreeNode *root);
    int __sizeTree(TreeNode *root);
    int __maxrlpathTree(TreeNode *root);
    int __maxpathTree(TreeNode *root);
};


/* 
 * Tree: Ĭ�Ϲ��캯��
*/ 
Tree::Tree()
{
    treeroot=NULL;    // Ĭ�Ϲ��캯������һ�ſյĶ���������
} 


/*
 * Tree: �����������ǰ������������������
*/
Tree::Tree(vector<int> inorder, vector<int> preorder)
{
    treeroot=__buildTree1(inorder,preorder);
}


/*
 * Tree: ����������ͺ�������������������
*/
Tree::Tree(vector<int> inorder, vector<int> postorder, int flag)
{
    treeroot=__buildTree2(inorder, postorder);
}


/* 
 * __buildTree1: �����������ǰ�������������������ĵײ�ݹ�ʵ��
 * param inorder: �����������
 * param preorder: ǰ���������
*/
TreeNode *Tree::__buildTree1(vector<int> &inorder, vector<int> &preorder)
{
    // 0. �����������
    if(!preorder.size()||!inorder.size())
    return NULL;

    // 1. ��ǰ���������Ԫ��ȡ�ø��ڵ�
    int rootval=preorder[0];
    TreeNode *root=new TreeNode(rootval);
    
    // 2. ��������������в��Ҹ�����ֵ��������������з�Ϊ������������
    vector<int> left, right;
    int index=__findIndex(inorder, rootval);
    
    for(int i=0;i<inorder.size();i++)
    {
    	if(i<index)
    	left.push_back(inorder[i]);
    	if(i>index)
    	right.push_back(inorder[i]);
	}

    // 3. ��ǰ����������е�������㣬��ǰ��������е�ǰ�벿�ֺ�����������й�����ڵ����������ͬ�����ʹ��ǰ��������еĺ�벿�ֺ�����������й�����ڵ��������
    preorder.erase(preorder.begin());
    root->left=__buildTree1(left, preorder);
    root->right=__buildTree1(right, preorder);

    return root;
}


/*
 * __buildTree2: ����������ͺ��������������������ĵײ�ݹ�ʵ��
 * param inorder: �����������
 * param postorder: �����������
*/
TreeNode *Tree::__buildTree2(vector<int> &inorder, vector<int> &postorder)
{
    // 0. �����������
    if(!inorder.size()||!postorder.size())
    return NULL;

    // 1. �ɺ�����������һ��Ԫ�ع������ĸ��ڵ�
    int rootval=postorder[postorder.size()-1];
    TreeNode *root=new TreeNode(rootval);

    // 2. ��������������в��Ҹ��ڵ��ֵ��������������з�Ϊ������������
    vector<int> left, right;
    int index=__findIndex(inorder, rootval);
    
    for(int i=0;i<inorder.size();i++)
    {
    	if(i<index)
    	left.push_back(inorder[i]);
    	if(i>index)
    	right.push_back(inorder[i]);
	}

    // 3. �ں�����������е�������㣬�ɺ���������е�ǰ�벿�ֺ�����������й�����ڵ����������ͬ�����ʹ�ú���������еĺ�벿�ֺ�����������й�����ڵ��������
    postorder.pop_back();
    
    root->right=__buildTree2(right, postorder);   // �״�㣺��������й���˳������෴�����ȹ����������ٹ�����������ֻҪ��˼��һ�º�������Ķ��弴����� 
    root->left=__buildTree2(left, postorder);

    return root;
}


/* 
 * Tree: �������캯��
*/
Tree::Tree(const Tree &other)
{
    treeroot=__copyTree(other.treeroot);
}


/*
 * __copyTree: ���Ŀ����ĵײ�ݹ�ʵ��
*/
TreeNode *Tree::__copyTree(TreeNode *other)
{
    // 0. �����������
    if(!other)
    return NULL;

    // 1. ���������
    TreeNode *root=new TreeNode(other->val);

    // 2. �ݹ�ؿ�����������������
    root->left=__copyTree(other->left);
    root->right=__copyTree(other->right);

    return root;
}

  
/*
 * operator =: ������ֵ�����
*/
Tree & Tree::operator = (const Tree &other)
{
    // 0. �������Ҹ�ֵ����
    if(this==&other)
    return (*this);

    // 1. �ݹ��ͷŵ�ǰ�������
    __deleteTree(treeroot);

    // 2. ����Դ�����������ǰ������
    treeroot=__copyTree(other.treeroot);

    return (*this);
}


/*
 * __deleteTree: ɾ����ָ�벢�ͷ��ڴ� 
*/
void Tree::__deleteTree(TreeNode *root)
{
	if(!root)
	return;
	
	else
	{
		// 1. �����ͷŸ������������������� 
		__deleteTree(root->left);
		__deleteTree(root->right);
		
		// 2. ����ͷŸ����
		delete root; 
	}
}


/* 
 * preorder: �������ķǵݹ�ǰ�����
*/ 
vector<int> Tree::preorder() const
{
	vector<int> res;
	
	// 0. ����������� 
	if(!treeroot)
	return res;

    // 1. ����һ������ʹ�õ�ջ�������������ջ
    stack<TreeNode *> sta;
    sta.push(treeroot);
	
    // 2. ѭ���������²���ֱ��ջΪ��Ϊֹ�����ȴ�ջ��ȡһ����㣬����ý�㣬Ȼ��ֱ����ν��ý��ķǿ����ӽ������ӽ����ջ
    while(sta.size())
    {
        TreeNode *temp=sta.top();
        sta.pop();

        res.push_back(temp->val);

        if(temp->right)
        sta.push(temp->right);
        if(temp->left)
        sta.push(temp->left);
    }

    return res;
}


/*
 *  inorder: �������ķǵݹ��������
*/
vector<int> Tree::inorder() const
{
    vector<int> res;
    
    // 0. ����������� 
	if(!treeroot)
	return res;

    // 1. ����һ������ʹ�õ�ջ�����Ӹ�����������ӽ���·���ϵ����н��ȫ��������ջ
    stack<TreeNode *> sta;
    TreeNode *now=treeroot;

    while(now)
    {
        sta.push(now);
        now=now->left;
    }

    // 2. ѭ���������²���ֱ��ջΪ��Ϊֹ����ջ�г�ջջ����㣬���ջ����㣬Ȼ��Ӹý������ӽ�㿪ʼ�������ӽڵ�·���ϵ����н��������ջ
    while(sta.size())
    {
        TreeNode *temp=sta.top();
        sta.pop();
        
        res.push_back(temp->val);

        temp=temp->right;
        while(temp)
        {
            sta.push(temp);
            temp=temp->left;
        }
    }

    return res;
}


/*
 *  postorder: �������ķǵݹ�������
*/
vector<int> Tree::postorder() const
{
    // 0. �����������
    vector<int> res;
    if(!treeroot)
    return res;

    // 1. ����һ������ʹ�õ�ջ���Ӹ���㿪ʼ�������ӽ��ķ�����ʣ���;���Ľ��(�����ս��)����ջ��
    stack<TreeNode *> sta;
    TreeNode *now=treeroot;

    while(now)
    {
        sta.push(now);
        now=now->left;
    }
    sta.push(now);

    // 2. ѭ���������²���ֱ��ջΪ��Ϊֹ�����ȴ�ջ����ջһ��Ԫ�ز����(�����ջ�Ľ��ǿ�)��Ȼ��ӵ�ǰջ��������������ʼ���������ӽڵ�·���ϵĽ��������ջ
    while(sta.size())
    {
        TreeNode *temp=sta.top();
        sta.pop();
        
        if(temp)
        res.push_back(temp->val);

		// ��Ҫ�ر�ע��ǵݹ�������ʵ�ֵ������ر��ж������������ڴˣ�
		// 1. ���ոճ�ջ�Ľ����ǳ�ջ��ջ���������ӽ�㣬��˵��ջ���������ӽ���Ѿ������������ʱ������������ظ���ջ
		// 2. ����ջһ��Ԫ�غ�ջΪ�գ���ֱ�ӷ��ص�ѭ������������ 
        if(!sta.size()||temp==sta.top()->right)     
        continue;

        TreeNode *now=sta.top()->right;
        
        while(now)
        {
            sta.push(now);
            now=now->left;
        }
        sta.push(now);
    }

    return res;
}


/*
 *  levelorder: �������ķǵݹ�������
*/
vector<int> Tree::levelorder() const
{
    // 0. �����������
    vector<int> res;
    if(!treeroot)
    return res;

    // 1. ����һ�����ڱ����Ķ��У�����������
    queue<TreeNode *> que;
    que.push(treeroot);

    // 2. �ظ��������²���ֱ������Ϊ�գ��������г��Ӷ��׽�㣬Ȼ�����ν����ӽ��ǿյ����ӽ������ӽ��������
    while(que.size())
    {
        TreeNode *temp=que.front();
        que.pop();
        
        res.push_back(temp->val);
        
        if(temp->left)
        que.push(temp->left);
        if(temp->right)
        que.push(temp->right);
    }

    return res;
}


/*
 * __findIndex: ����ֵ�����������е��±� 
*/
int Tree::__findIndex(const vector<int> &lis, int tar)
{
	for(int i=0;i<lis.size();i++)
	{
		if(lis[i]==tar)
		return i;
	}
	
	return -1;
}


/*
 * insert: �����в�����
*/ 
void Tree::insert(int val)
{
	__insertTree(treeroot,val);
}

/* 
 * __insertTree: ���в�����ĵײ�ݹ�ʵ��
*/ 
TreeNode *Tree::__insertTree(TreeNode *root, int val)
{
	if(!root)
	{
		TreeNode *newnode=new TreeNode(val);
		return newnode;
	}
	else if(val>root->val)
	root->right=__insertTree(root->right,val);
	else if(val<=root->val)
	root->left=__insertTree(root->left,val);
	
	return root;
}


/*
 * remove: �������Ƴ����ڸ���ֵ�Ľ�� 
*/
void Tree::remove(int val)              
{
	treeroot=__deleteTree(treeroot,val);
}

TreeNode *Tree::__deleteTree(TreeNode *root, int val)
{
	if(!root)
	return NULL;
	else if(val>root->val)
	root->right=__deleteTree(root->right,val);
	else if(val<root->val)
	root->left=__deleteTree(root->left,val);
	else
	{
		// �Ѿ����ҵ���Ŀ���㣬�������ɾ������ 
		// 1. ����ɾ���Ľ���û�����ӽ��Ҳû�����ӽ�㣬��ֱ��ɾ���ý�㣬����NULL 
		if(!root->left&&!root->right) 
		{
			delete root;
			return NULL;
		}
		// 2. ����ɾ���Ľ��������ӽ��Ҳ�����ӽ�㣬�����Ȳ����������е����ֵ�����������е���Сֵ���tar��Ȼ�󽫽��tar��ֵ�ʹ�ɾ������ֵ���������ɾ�����tar 
		// ��ע: ����Ϊʲôѡ���������е����ֵ�����������е���Сֵ��ȡ����ɾ������ֵ��ԭ����Ϊ�˱���ȡ��ԭֵ�󣬱��ֶ����������Ļ������ʡ�����������ֵ��С�ڸ���㣬��������ֵ�����ڸ���� 
		else if(root->left&&root->right)
		{
			// 2.1 �����Ȳ��ҵ��������е����ֵ
			TreeNode *tar=root->left;  // �������е����ֵ���tar 
			TreeNode *parent=root;     // ��¼���tar�ĸ���� 
			while(tar->right)
			{
				parent=tar;
				tar=tar->right;
			}
			
			// 2.2 �������tar�͵�ǰ���root��ֵ
			int temp=tar->val; 
			tar->val=root->val;
			root->val=temp;
			
			// 2.3 ɾ�����tar����Ϊ���tar��ԭ���������е����ֵ���������������Ҳ�Ľ�㣬��������ֻ�����ӽ�㣬�Ӷ�������ݹ��ת��Ϊ��ɾ�����ֻ��һ���ӽ������ 
			// ��ע: ��һ�����׳��ִ��󣬼�ֱ�ӽ�parent->right=NULL; ��Ҫ�ر�ע�⣬�ҵ�������������е����ֵ���ͬ�����������һ���ӽ�� 
			parent->right=tar->left;
			delete tar;
			
			// 2.4 ֱ�ӷ��ص�ǰ��㣬��Ϊ��ǰ���Ĵ洢δ������ɾ�� 
			return root;    
		}
		// 3. ����ɾ���Ľ��������ӽ������ӽ��֮�е�һ������ɾ��Ŀ���㣬ɾ����������������������ռ��ԭ��ɾ���Ľ���λ�ã������������ֽڻ������ӽ�� 
		else
		{
			TreeNode *temp=(root->left)?root->left:root->right;
			delete root;
			return temp;
		}
	}
	
	return root;
}


/*
 * search: �����в��Ҷ�Ӧֵ�Ľ���ַ 
*/ 
TreeNode *Tree::search(int val)
{
	return __searchTree(treeroot,val);
}

/*
 * __searchTree: ���������ĵײ�ݹ�ʵ�� 
*/
TreeNode *Tree::__searchTree(TreeNode *root, int val)
{
	if(!root)
	return NULL;
	else if(val>root->val)
	return __searchTree(root->right, val);
	else if(val<root->val)
	return __searchTree(root->left, val);
	else
	return root;
}


/*
* lca: ����������������ַ�������������/������������(lca) 
*/
TreeNode *Tree::lca(TreeNode *p, TreeNode *q)
{
	return __lcaTree1(treeroot, p, q);
}

TreeNode *Tree::__lcaTree1(TreeNode *root, TreeNode *p, TreeNode *q)
{
	// ���ﻻ������ͨ������(��һ������ȫ������)�в�������������ȵ��㷨 
	
	// 0. �������Ϊ�գ���ֱ�ӷ���NULL����������ʧ��	
	if(!root)
	return NULL;
	else if(root==p||root==q)  // ���* 
	return root;
	else
	{
		// 1. �����ڵ�ǰ�������������зֱ����p��q������������ȣ�ע����p����q����Ҳ������������������ 
		TreeNode *left=__lcaTree1(root->left, p, q);     // ���������в���p��q�������������    
		TreeNode *right=__lcaTree1(root->right, p, q);   // ���������в���p��q�������������   
	
		// 2. �����������в��ҵ���p��q������������ȣ�����p�ͽ��q���ڵ�ǰ���root���������У�ֱ�ӷ���left���� 
		if(left&&!right)
		return left;
	
		// 3. �����������в��ҵ���p��q������������ȣ�����p��q���ڵ�ǰ���root���������У�ֱ�ӷ���right���� 
		else if(!left&&right)
		return right;
		
		// 4. �������������������ж����ҵ���p��q������������ȣ���ʱ˵�����p�ͽ��q�ֱ������������У�������*��ǵĴ���Σ���˷��ص�ǰ���root��Ϊ����������� 
		else if(left&&right)
		return root;
	
		// 5. ���������в��ҵĽ������NULL�����������ڣ����ֱ�ӷ���NULL 
		else
		return NULL;
	}
}


/*
* lca: ������������ֵ�������������/������������(lca) 
*/
TreeNode *Tree::lca(int p, int q)
{
	return __lcaTree2(treeroot, p, q);
}

TreeNode *Tree::__lcaTree2(TreeNode *root, int p, int q)
{
	// �ڶ����������в�������������ȵ��㷨 
	
	// 0. ͳһ����pΪ�������еĽ�Сֵ��qΪ�������еĽϴ�ֵ
	if(p>q) 
	{
		int temp=p;
		p=q;
		q=temp;
	}
	
	// 1. ����ǰ���rootΪ�գ������ʧ�ܣ�ֱ�ӷ���NULL 
	if(!root)
	return NULL;
	
	// 2. ����ǰ���root��ֵ���ڽϴ�ֵq������p��q��������������ڵ�ǰ����������root->left�� 
	else if(root->val>q) 
	return __lcaTree2(root->left, p, q);
	
	// 3. ����ǰ���root��ֵС�ڽ�Сֵp������p��q��������������ڵ�ǰ����������root->right��
	else if(root->val<p) 
	return __lcaTree2(root->right, p, q);
	
	// 4. ����ǰ���root��ֵ����q��p֮�䣬��ǰ���root�������������p��q������������� 
	else
	return root;
}


/*
 * depth: �����������
*/ 
int Tree::depth()
{
	return __depthTree(treeroot);
}

int Tree::__depthTree(TreeNode *root)
{
	if(!root)
	return 0;
	else if(!root->left&&!root->right)
	return 1;
	else
	{
		int left=__depthTree(root->left);
		int right=__depthTree(root->right);
		
		return ((left>right)?left:right)+1;
	}
}


/*
* size: ����������Ľ����� 
*/
int Tree::size()
{
	return __sizeTree(treeroot);
}

int Tree::__sizeTree(TreeNode *root)
{
	if(!root)
	return 0;
	else if(!root->left&&!root->right) 
	return 1;
	else
	return 1+__sizeTree(root->left)+__sizeTree(root->right);
}


/*
* maxrlpath: ����������Ӹ���㵽Ҷ�ӽ��Ľ��ֵ֮������·�� 
*/
int Tree::maxrlpath()
{
	return __maxrlpathTree(treeroot);
}

int Tree::__maxrlpathTree(TreeNode *root)
{
	if(!root)
	return 0;
	else if(!root->left&&!root->right)
	return root->val;
	else 
	{
		int left=__maxrlpathTree(root->left);
		int right=__maxrlpathTree(root->right);
		
		return ((left>right)?left:right) + root->val;   // ע����Ԫ���������ʹ�������������������൱��: (left>right)?left:(right+root->val)��������߼����� 
	}
}


/*
* maxpath: �������е��·���� 
*/
int Tree::maxpath()
{
	return __maxpathTree(treeroot);
}

int Tree::__maxpathTree(TreeNode *root)
{
	// ����������н��ֵ֮������·�����㷨��Ϊ�򵥣����·��Ҫôֻ�ڸ������������У�Ҫôֻ�ڸ������������У�Ҫôͨ������㣬��������������� 
	if(!root)
	return 0;
	else if(!root->left&&!root->right)
	return root->val;
	else
	{
		int left=__maxpathTree(root->left);         // ��һ�����: ���·��ֻ�����ڸ������������� 
		int right=__maxpathTree(root->right);       // �ڶ������: ���·��ֻ�����ڸ������������� 
		// ���������: ���·�����������������������������ʱ�൱���������дӸ��ڵ㵽Ҷ�ӽ������·��ֵ���ϸ��ڵ��ֵ�����������дӸ��ڵ㵽Ҷ�ӽ������·��ֵ
		int lr=__maxrlpathTree(root->left) + root->val + __maxrlpathTree(root->right);   
		
		return ((left>right)?((left>lr)?left:lr):((right>lr)?right:lr));   // ��������е����ֵ������������·�� 
	}
}
 
TreeNode *Tree::getroot() const 
{
	return treeroot;
}

/*
 * ~Tree: ��������
*/ 
Tree::~Tree()
{
	__deleteTree(treeroot);
}

