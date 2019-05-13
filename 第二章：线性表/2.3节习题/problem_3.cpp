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
    // 1. ���캯��
    List();                            // Ĭ�Ϲ��캯��
    List(const vector<int> &lis);      // �������캯��: �����鹹������
    
    void reverse_print();       // �������ʵ�ֺ���: ����������������е�ÿһ��ֵ 
    void print() const;                // �������: ���������������ʹ�ã���Ա������Ӧ��������cin��cout��ֱ��ʹ��

    // 4. ��������
    ~List();                           // ��������

    private:
    ListNode *head;                    // ����ͷ��㣬��ʵ����ʹ��ͷ���ƽ�����򻯲����ɾ������
};



/*
 * List: Ĭ�Ϲ��캯��
*/
List::List()
{
    head=new ListNode(0);    // ��ʼ������ͷ���ƽ��
}


/* 
 * List: �������캯���������鹹������
 * param lis: ԭʼ����
*/
List::List(const vector<int> &lis)  // Ϊʲôlis����ʹ��const���ö�����ֵ���ݣ���Ϊ��������Ŀ����ǳ���ʱ��ռ�ÿռ䣬���ʹ�����ã�const��ֹ�������޸ĸ�����
{
    head=new ListNode(0);    // ��ʼ������ͷ���ƽ��
    ListNode *now=head;      // ���ڱ���������α�ָ��

    for(int i=0;i<lis.size();i++)    
    {
        now->next=new ListNode(lis[i]);
        now=now->next;
    }
}


/*
 * reverse_print: �����������Ԫ��
 * note: �����������Ԫ�ص��㷨�ǳ��򵥣�ʹ��һ����ʱջ������������ֵ˳�����ջ�У�����ٲ��ϳ�ջԪ��������� 
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
 * print: ���������������е�Ԫ��
 * note: ��������Ŀ��ֻ�Ƿ��㵥Ԫ���ԣ���Ա������Ӧ��������cin��cout��ֱ��ʹ��
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
 * ~List: ��������
*/
List::~List()
{
    // 1. List�������������ͷ����������е�ÿ�������ռ���ڴ棬��ֹ�ڴ�й©

    ListNode *now=head;
    while(now)
    {
        ListNode *temp=now;
        now=now->next;
        delete temp;    // ����ط��Ĵ�������10���ӣ�С�ĺͽ���������ɾ��now��ֻ��ɾ����ʱ����temp 
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

