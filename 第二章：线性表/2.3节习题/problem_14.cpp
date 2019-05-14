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
    
    List(const List &a, const List &b);  // 本问题的实现函数: 从两个递增有序的单链表中的共同元素生成新链表 
    
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
 * List: 从两个递增有序的单链表中的共同元素生成新链表 
 * note: 由于两个链表都是递增的，因此只需要使用双指针法即可解决本题：
 *       创建两个游标指针now1和now2分别指向链表a和b的首结点，循环进行以下步骤直到now1或者now2指向NULL为止: 、
 *       (1) 比较结点now1和now2的值
 *       (2) 若结点now1和结点now2的值相等，则将结点now1的拷贝加入到结果链表中，然后两个结点同时向前移动一步 
 *       (3) 若结点now1的值小于结点now2的值，则将结点now1向前移动一步
 *       (4) 若结点now1的值大于结点now2的值，则将结点now2向前移动一步 
*/
List::List(const List &a, const List &b)
{
	ListNode *now1=a.head->next;    // 有序输入链表a的游标指针 
	ListNode *now2=b.head->next;    // 有序输入链表b的游标指针 
	
	head=new ListNode(0);           // 创建结果链表头部哑结点 
	ListNode *resnow=head;          // 结果链表的游标指针 
	
	while(now1&&now2)
	{
		if(now1->val<now2->val)
		now1=now1->next;
		else if(now1->val>now2->val)
		now2=now2->next;
		else
		{
			resnow->next=new ListNode(now1->val);
			
			now1=now1->next;
			now2=now2->next;
			resnow=resnow->next;
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
	vector<int> data1={1,2,3,4,5,6,7,8,9}; 
	vector<int> data2={1,3,5,7,9,12,14};	
	vector<int> data3={1,2,5,9,10,14};
	vector<int> data4={};
	vector<int> data5={1,4,5,6,8,9};
	
	List lis1(data1);
	List lis2(data2);
	List lis3(data3);
	List lis4(data4);
	List lis5(data5);
	
	List res1(data1, data1);
	res1.print();
	List res2(data1, data2);
	res2.print();
	List res3(data1, data3);
	res3.print();
	List res4(data1, data4);
	res4.print();
	List res5(data1, data5);
	res5.print();
	List res6(data2, data3);
	res6.print();    
} 

