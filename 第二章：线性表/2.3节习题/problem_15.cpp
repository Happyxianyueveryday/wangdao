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
    
    List(const List &a, const List &b);  // 本问题的实现函数: 从两个递增有序的单链表中的交集生成新链表 
    
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
 * note 1: 从两个递增有序的单链表中的共同元素生成最小序列的方法和上一题类似，不过公共元素可能出现重复值，而交集中不存在重复值，例如{1,2,5,5,5}和{3,4,5,5}的共同元素是{5,5}（两个链表中最多共同有2个5，因此结果中存在2个5），但是交集为{5} 
 * note 2: 本题的实际算法也与上一题类似：使用两个游标指针now1和now2分别遍历两个链表a和b，循环进行以下步骤直到now1和now2其中一个为空为止: 
 *         (1) 若now1的值小于now2的值，则将指针now1前移一步
 *         (2) 若now1的值大于now2的值。则将指针now2前移一步
 *         (3) 若指针now1的值等于指针now2的值，则将指针now1的值加入结果链表中，并移动now1到下一个不等于当前now1的值的结点上，移动now2到下一个不等于当前now2的值的结点上（这一点的处理与上一题的共同元素不同，两个链表中的共同元素值可以出现重复，但是两个链表中的交集元素一定不出现重复，之所以移动now1和now2到不等于当前值的结点上，原因就是为了保证结果链表中不出现重复） 
*/
List::List(const List &a, const List &b)
{
	head=new ListNode(0);           // 创建结果链表的头部哑结点
	
	ListNode *now1=a.head->next;    // 链表a的游标指针now1 
	ListNode *now2=b.head->next;    // 链表b的游标指针now2 
	ListNode *resnow=head;
	
	while(now1&&now2)
	{
		// 1. 若now1的值小于now2，则将now1前移一步 
		if(now1->val<now2->val)
		now1=now1->next;
		
		// 2. 若now2的值小于now1，则将now2前移一步 
		else if(now1->val>now2->val)
		now2=now2->next;
		
		// 3. 若now1和now2的值相等，则将该结点的值加入结果链表中，将now1和now2分别移动到下一个不等于当前值的结点 
		else
		{
			resnow->next=new ListNode(now1->val);
			
			int val1=now1->val;
			int val2=now2->val;
			
			while(now1&&now1->val==val1)
			{
				now1=now1->next;
			}
			
			while(now2&&now2->val==val2)
			{
				now2=now2->next;
			}
			
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
	vector<int> data1={1,1,2,2,3,3,4,4,5,5,5,6,6,7,7,7,7,8,8,8,8,8,8,9,10,10}; 
	vector<int> data2={1,3,3,3,3,5,5,7,9,9,9,12,12,14};	
	vector<int> data3={1,2,2,5,9,9,9,9,9,9,10,14}; 
	vector<int> data4={};
	vector<int> data5={1,1,4,5,5,5,6,6,8,8,8,8,8,9};
	
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

