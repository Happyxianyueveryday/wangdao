#include <iostream> 
#include <string>
#include <vector>
#include <cstdlib>
#include <stack>
#include <set>

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
    
    void remove_dumplicate();          // 本问题的实现函数: 删除链表中绝对值相同的重复结点
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
 * remove_dumplicate: 删除链表中绝对值相同的重复结点
 * note: 本题同样是使用一个哈希表(set)来记录哪些结点值已经出现过，对于在哈希表中已经存在相同值的结点进行删除即可 
*/
void List::remove_dumplicate() 
{
	set<int> dic;
	
	ListNode *now=head->next, *nowprev=head;
	
	while(now)
	{
		if(dic.count(now->val))
		{
			nowprev->next=now->next;
			delete now;
			
			nowprev=nowprev;
			now=nowprev->next;
		}
		else
		{
			dic.insert(now->val);
			nowprev=now;
			now=now->next;
		}
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
        delete temp;   
    }
}


int main(void)
{
	vector<int> data1={9,8,7,5,8,9,5,6,4,5,6,3,8,7,4,1,2,6,6,9,8,7,4,1,5,6,3};  
	
	List lis1(data1);
	lis1.remove_dumplicate();
	lis1.print();
	
	cout<<"--------------------------------"<<endl;
	
	vector<int> data2={1,2,3,3,4,4,5,5,6,6,6,7,7,7,8,8,9,9};
	
	List lis2(data2);
	lis2.remove_dumplicate(); 
	lis2.print();
	
	cout<<"--------------------------------"<<endl; 
	
	vector<int> data3={1,1,1,1,1,1,1,1,1,};
	
	List lis3(data3);
	lis3.remove_dumplicate();
	lis3.print();
	
	cout<<"--------------------------------"<<endl;
} 

