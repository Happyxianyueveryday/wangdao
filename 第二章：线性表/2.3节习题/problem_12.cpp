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
    
    void delete_dumplicate();          // 本问题的实现函数: 删除有序链表中重复值的结点 
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
 * delete_dumplicate: 删除递增有序的链表中的重复值结点
 * note 1: 由于递增有序的链表中重复值一定连续出现，因此删除时可以进行连续删除
 * note 2: 本题的核心算法思想是：使用一个游标指针now来遍历整个链表，每当now到达一个新结点，则使用另外一个新游标指针pos，从now开始向后查找第一个不等于now的结点，然后删除结点pos和now之间的所有结点即可 
*/
void List::delete_dumplicate()
{
	ListNode *now=head;
	
	while(now)
	{
		ListNode *pos=now;
		
		// 查找结点now后第一个和now不相等的结点位置 
		while(pos&&pos->val==now->val)   
		{
			pos=pos->next;
		}
		
		// 删除结点now和结点pos之间的所有结点，这些结点都是重复结点 
		ListNode *temp=now->next;
		now->next=pos;
		
		// 更新游标指针now 
		now=pos;   
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
	vector<int> data1={1,1,2,3,4,4,5,5,6,6,7,7,7,7,7,8,8,9,10,10}; 
	
	List lis1(data1);
	lis1.delete_dumplicate(); 
	lis1.print();
	
	cout<<"--------------------------------"<<endl;
	
	vector<int> data2={2,2,2,2,2,2,2,2};
	
	List lis2(data2);
	lis2.delete_dumplicate(); 
	lis2.print();
	
	cout<<"--------------------------------"<<endl; 
	
	vector<int> data3={1,1,1,1,2,2,2,2,3,3,3,3,3};   
	
	List lis3(data3);
	lis3.delete_dumplicate();  
	lis3.print();
	
	cout<<"--------------------------------"<<endl;
} 

