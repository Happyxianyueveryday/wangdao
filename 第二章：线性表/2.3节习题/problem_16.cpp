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
    
    bool sublist(const List &lis);     // 本问题的实现函数: 判断当前链表是否为给定参数链表的连续子序列 
    void print() const;                      // 输出链表: 本函数仅方便测试使用，成员函数中应尽量减少cin和cout的直接使用

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
 * sublist: 判断当前链表是否是输入的链表的连续子序列
 * note: 本题所需要使用的算法步骤为: 依次从输入链表的每一个结点开始进行匹配即可，一旦出现失配情况，则立即从下一个结点开始进行匹配
*/
bool List::sublist(const List &lis)
{
	ListNode *pos2=lis.head->next;    // 在目标链表中起始匹配的结点
	
	while(pos2)
	{
		ListNode *pos1=head->next;        // 在当前链表中起始匹配的结点 
		
		while(pos1&&pos2)
		{
			if(pos1->val==pos2->val)
			{
				pos1=pos1->next;
				pos2=pos2->next;
			}
			else
			break;
		}
		
		if(pos1==NULL)   // 若上述循环结束时，pos1指向空，则这时完成匹配
		return true;
		else             // 否则匹配未完成就被中断，这时匹配失败，从下一个结点开始匹配 
		{
			pos2=pos2->next;
			continue;
		}
	}
	
	return false;        // 所有结点匹配完毕均不成功，则返回匹配失败 
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
	vector<int> data1={1,2,3,4,5,6,7,8,9,10};
	vector<int> data2={5,6,7,8,9};
	vector<int> data3={5,6,7,9};
	vector<int> data4={};
	vector<int> data5={1,2,3,4,5,6,7,8,9,10};
	
	List lis1(data1);
	List lis2(data2);
	List lis3(data3);  
	List lis4(data4);
	List lis5(data5);
	
	if(lis2.sublist(lis1))
	cout<<"链表lis2是链表lis1的连续子序列"<<endl;
	else
	cout<<"链表lis2不是链表lis1的连续子序列"<<endl;
	
	if(lis3.sublist(lis1))
	cout<<"链表lis3是链表lis1的连续子序列"<<endl;
	else
	cout<<"链表lis3不是链表lis1的连续子序列"<<endl;
	
	if(lis4.sublist(lis1))
	cout<<"链表lis4是链表lis1的连续子序列"<<endl;
	else
	cout<<"链表lis4不是链表lis1的连续子序列"<<endl;
	
	if(lis5.sublist(lis1))
	cout<<"链表lis5是链表lis1的连续子序列"<<endl;
	else
	cout<<"链表lis5不是链表lis1的连续子序列"<<endl;
	
} 

