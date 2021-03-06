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
    
    void reverse_print();       // 本问题的实现函数: 反向输出整个链表中的每一个值 
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
 * reverse_print: 反向输出链表元素
 * note: 反向输出链表元素的算法非常简单，使用一个临时栈，将各个结点的值顺序放入栈中，最后再不断出栈元素输出即可 
*/
void List::reverse_print()
{
	stack<int> sta;
	
	ListNode *now=head->next;
	
	while(now)
	{
		sta.push(now->val);
		now=now->next;
	}
	
	while(sta.size())
	{
		cout<<sta.top()<<" "; 
		sta.pop();
	}
	cout<<endl;
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
	vector<int> data1={5,5,5,5,5,5,5,5,5,5};
	
	List lis1(data1);
	lis1.print();
	lis1.reverse_print();
	
	cout<<"--------------------------------"<<endl;
	
	vector<int> data2={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0};
	
	List lis2(data2);
	lis2.print();
	lis2.reverse_print();
	
	cout<<"--------------------------------"<<endl; 
	
	vector<int> data3={9,6,3,2,8,5,2,1,4,7,8,4,5,6,8,7,5,5};
	
	List lis3(data3);
	lis3.print();
	lis3.reverse_print();
	
	cout<<"--------------------------------"<<endl;
} 

