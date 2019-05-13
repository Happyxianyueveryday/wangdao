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
    
    void reverse();                 // 本问题的实现函数: 对给定的链表进行反转 
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
 * reverse: 对链表进行反转 
 * note: 对链表进行反转的算法较为简单：依次将链表的第二个结点，第三个结点，...，最后一个结点从原位置删除，并插入到链表的头部哑结点之后（也即原来的第一个结点之前即可） 
*/
void List::reverse()
{
	// 0. 处理空链表和单个元素链表的特殊情况
	if(!head->next||!head->next->next)	
	return;
	
	// 1. 从第二个结点开始，依次遍历每一个结点，将每一个结点从原位置删除，并插入到头部哑结点之后
	ListNode *now=head->next->next;
	ListNode *tempnow=head->next;
	
	while(now)
	{
		// 1.1 从原位置删除结点now
		tempnow->next=now->next;
		
		// 1.2 将结点now插入到链表头结点之后
		now->next=head->next;
		head->next=now; 
		
		// 1.3 更新游标指针
		tempnow=tempnow;
		now=tempnow->next;
	}
	
	return;
}


/*
 * print: 输出链表，输出链表中的元素
 * note: 本函数的目标只是方便单元测试，成员函数中应尽量减少cin和cout的直接使用
*/
void List::print() const
{
    ListNode *now=head->next;

    while(now)
    {
        if(now==head->next)
        cout<<now->val;
        else
        cout<<"->"<<now->val;

        now=now->next;
    }
    
    cout<<endl;
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
	lis1.reverse();
	lis1.print();
	
	cout<<"--------------------------------"<<endl;
	
	vector<int> data2={1,9,8,7,4,5,6,3,2};
	
	List lis2(data2);
	lis2.reverse(); 
	lis2.print();
	
	cout<<"--------------------------------"<<endl; 
	
	vector<int> data3={1,2,5,8,9,6,3,4,0,7};
	
	List lis3(data3);
	lis3.reverse();
	lis3.print();
	
	cout<<"--------------------------------"<<endl;
} 

