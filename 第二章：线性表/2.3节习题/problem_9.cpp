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
    
    void sort_and_print();                   // 本问题的实现函数: 从小到大输出链表的所有结点，输出结束后释放整个链表 
    void print() const;                      // 输出链表: 本函数仅方便测试使用，成员函数中应尽量减少cin和cout的直接使用

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
 * sort_and_print: 小到大输出链表的所有结点，输出结束后释放整个链表
 * note: 本题中所需要使用的算法非常简单，首先对原链表进行插入排序，然后按照顺序进行输出，输出的同时释放链表结点即可 
*/
void List::sort_and_print()
{
	// 1. 首先对原链表进行插入排序，如果原链表不是空链表或者单结点链表 
	if(head->next&&head->next->next)
	{
		ListNode *now=head->next->next;
		ListNode *nowtemp=head->next;
		
		while(now)
		{
			ListNode *pos=head->next;
			ListNode *postemp=head;
			
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
			
			if(pos!=now)
			{
				nowtemp->next=now->next;
				now->next=postemp->next;
				postemp->next=now;
				
				nowtemp=nowtemp;
				now=nowtemp->next;
			}
			else
			{
				nowtemp=now;
				now=now->next;
			}
		}
	}
	
	// 2. 然后遍历整个排序后的链表，输出结点并释放结点
	ListNode *now=head->next;
	
	while(now) 
	{
		if(now==head->next)
		cout<<now->val;
		else
		cout<<"->"<<now->val;   
		
		ListNode *temp=now;
		now=now->next;
		delete temp;
	}
	cout<<endl;
	
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


int main(void)
{
	vector<int> data1={9,6,3,2,5,1,8,7,4}; 
	
	List lis1(data1);
	lis1.sort_and_print();
	
	cout<<"--------------------------------"<<endl;
	
	vector<int> data2={1,9,8,7,4,5,6,3,2};
	
	List lis2(data2);
	lis2.sort_and_print(); 
	
	cout<<"--------------------------------"<<endl; 
	
	vector<int> data3={1,2,5,8,9,6,3,4,0,7};
	
	List lis3(data3);
	lis3.sort_and_print();  
	
	cout<<"--------------------------------"<<endl;
} 

