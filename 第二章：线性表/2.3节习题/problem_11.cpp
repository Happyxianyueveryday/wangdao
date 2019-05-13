#include <iostream> 
#include <string>
#include <vector>
#include <cstdlib>
#include <stack>

using namespace std;

struct ListNode
{
    ListNode(int ival=0):val(ival),next(NULL)
    {
    }

    int val;
    ListNode *next;
};

class List
{
    public:
    // 1. 构造函数
    List();                            // 默认构造函数
    List(const vector<int> &lis);      // 其他构造函数: 从数组构造链表
    
    void partition();                  // 本问题的实现函数: 将链表{a1,b1,a2,b2,...,an,bn}分解为{a1,a2,a3,...,an}和{bn,...,b2,b1} 
    void print() const;                // 输出链表: 本函数仅方便测试使用，成员函数中应尽量减少cin和cout的直接使用

    // 4. 析构函数
    ~List();                           // 析构函数

    private:
    ListNode *head;                    // 链表头结点，本实现中使用头部哑结点来简化插入和删除过程 
};



/*
 * List: 默认构造函数
*/
List::List()
{
    head=new ListNode(0);    // 初始化链表头部哑结点
}


/* 
 * List: 其他构造函数，从数组构造链表
 * param lis: 原始数组
*/
List::List(const vector<int> &lis)  // 为什么lis参数使用const引用而不是值传递？因为大型数组的拷贝非常耗时和占用空间，因此使用引用，const防止本函数修改该数组
{
    head=new ListNode(0);    // 初始化链表头部哑结点
    ListNode *now=head;      // 用于遍历链表的游标指针

    for(int i=0;i<lis.size();i++)    
    {
        now->next=new ListNode(lis[i]);
        now=now->next;
    }
}


/*
 * partition: 将链表{a1,b1,a2,b2,...,an,bn}分解为{a1,a2,a3,...,an}和{bn,...,b2,b1} 
 * note: 本题的算法非常简单，首先按照结点的序号的奇偶性将链表划分为奇偶两部分，然后将偶链表反转即可 
*/
void List::partition()
{
	// 1. 将链表分割为奇偶两部分 
	ListNode *odd=new ListNode(0);
	ListNode *even=new ListNode(0);
	
	ListNode *oddnow=odd;
	ListNode *evennow=even;
	ListNode *now=head->next;
	
	int count=1;
	
	while(now)
	{
		if(count%2)
		{
			oddnow->next=new ListNode(now->val);
			oddnow=oddnow->next;
		}
		else
		{
			evennow->next=new ListNode(now->val);
			evennow=evennow->next;
		}
		now=now->next;
		count+=1;
	}
	
	// 2. 将偶链表进行反转
	if(even->next&&even->next->next)
	{
		ListNode *now=even->next->next; 
		ListNode *nowtemp=even->next;
	
		while(now)
		{
			nowtemp->next=now->next;
			now->next=even->next;
			even->next=now;
			
			nowtemp=nowtemp;
			now=nowtemp->next;
		}
	}
	
	// 3. 输出分割后的链表
	now=odd->next;
	
	while(now) 
	{
		cout<<now->val<<" ";
		now=now->next;
	}
	cout<<endl;
	
	now=even->next;
	
	while(now) 
	{
		cout<<now->val<<" ";
		now=now->next;
	}
	cout<<endl;
	
	return;
}


/*
 * ~List: 析构函数
*/
List::~List()
{
    // 1. List析构函数依次释放整个链表中的每个结点所占的内存，防止内存泄漏

    ListNode *now=head;
    while(now)
    {
        ListNode *temp=now;
        now=now->next;
        delete temp;    // 这个地方的错误找了10分钟！小心和谨慎！不能删除now，只能删除临时变量temp 
    }
}


int main(void)
{
	vector<int> data1={9,6,3,2,5,1,8,7,4}; 
	
	List lis1(data1);
	lis1.partition();
	
	cout<<"--------------------------------"<<endl;
	
	vector<int> data2={1,9,8,7,4,5,6,3,2}; 
	
	List lis2(data2);
	lis2.partition(); 
	
	cout<<"--------------------------------"<<endl; 
	
	vector<int> data3={1,2,5,8,9,6,3,4,0,7};
	
	List lis3(data3);
	lis3.partition();  
		
	cout<<"--------------------------------"<<endl;
} 

