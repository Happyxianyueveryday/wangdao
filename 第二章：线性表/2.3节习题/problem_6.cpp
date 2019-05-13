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
    
    void insert_sort();                 // 本问题的实现函数: 对给定的无序链表进行插入排序 
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
 * insert_sort: 对链表进行插入排序 
 * note: 对链表进行插入排序的算法也较为简单，依次遍历每一个结点，每次将一个结点插入到该结点之前的链表中的合适部分即可，注意使用双指针法的基本思想——一个游标指针now和now的前驱结点指针nowtemp的核心技巧 
*/
void List::insert_sort() 
{
	// 0. 处理单元素链表和空链表的特殊情况 
	if(!head->next||!head->next->next)
	return;
	
	// 1. 从第二个链表结点开始，依次遍历每一个链表结点，将其插入到该结点之前的正确的位置上
	ListNode *now=head->next->next;
	ListNode *nowtemp=head->next;
	
	while(now)
	{
		// 1.1 在当前结点now之前的有序部分查找正确的插入位置 
		ListNode *pos=head->next;    // 插入位置，插入位置指的是在当前结点now之前的，第一个大于当前结点now的值的结点 
		ListNode *postemp=head;      // 插入位置的前驱结点 
		
		while(pos!=now)
		{
			if(pos->val>now->val)
			break;
			else
			{
				postemp=pos;
				pos=pos->next;
			}
		}
		
		// 1.2 将结点now从原位置进行删除并插入到结点pos之前，然后更新游标指针now和nowtemp 
		if(pos!=now)    // pos!=now才需要插入，否则说明now结点之前的结点的值均小于now，无需改变now的位置
		{
			nowtemp->next=now->next; 
			now->next=postemp->next; 
			postemp->next=now;
			
			now=nowtemp->next;      // 更新游标指针now和nowtemp 
  		    nowtemp=nowtemp;     
		} 
		else            //无需改变now的位置时，直接转向处理下一个结点 
		{
			nowtemp=now;            // 更新游标指针now和nowtemp 
			now=now->next;
		}
	}
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
	lis1.insert_sort();
	lis1.print();
	
	cout<<"--------------------------------"<<endl;
	
	vector<int> data2={1,9,8,7,4,5,6,3,2};
	
	List lis2(data2);
	lis2.insert_sort(); 
	lis2.print();
	
	cout<<"--------------------------------"<<endl; 
	
	vector<int> data3={1,2,5,8,9,6,3,4,0,7};
	
	List lis3(data3);
	lis3.insert_sort();
	lis3.print();
	
	cout<<"--------------------------------"<<endl;
} 

