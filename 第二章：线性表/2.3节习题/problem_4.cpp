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
    
    void delete_min();                 // 本问题的实现函数: 删除整个链表中的最小值 
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
 * delete_min: 删除链表中最小元素（假设最小值唯一） 
 * note: 删除链表中最小元素的算法也较为简单: 使用指针now遍历整个链表，同时每当访问一个结点，就将该结点和当前所查找到的最小值比较，若小于最小值，则更新记录最小值结点前驱结点mintemp的指针，遍历结束后，通过最小值结点前驱结点的记录指针mintemp来删除结点
*/
void List::delete_min()
{
	if(!head->next)
	return; 
	
	ListNode *now=head->next;     // 用于遍历链表的游标指针 
	ListNode *nowtemp=head;       // 游标指针now的前驱结点 
	
	ListNode *mintemp=head;       // 记录链表最小值结点的前驱结点的指针 
	int min=head->next->val;      // 记录链表结点中的最小值
	
	while(now) 
	{
		if(now->val<=min)
		{
			min=now->val;
			mintemp=nowtemp;
		}
		nowtemp=now;
		now=now->next;
	}
	
	ListNode *temp=nowtemp->next;
	mintemp->next=mintemp->next->next;
	delete temp;
	
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
	lis1.delete_min();
	lis1.print();
	
	cout<<"--------------------------------"<<endl;
	
	vector<int> data2={1,9,8,7,4,5,6,3,2};
	
	List lis2(data2);
	lis2.delete_min();
	lis2.print();
	
	cout<<"--------------------------------"<<endl; 
	
	vector<int> data3={1,2,5,8,9,6,3,4,0,7};
	
	List lis3(data3);
	lis3.delete_min();
	lis3.print();
	
	cout<<"--------------------------------"<<endl;
} 

