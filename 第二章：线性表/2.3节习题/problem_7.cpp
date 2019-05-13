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
    
    void delete_range(int low, int high);    // �������ʵ�ֺ���: ɾ��ֵ��һ����Χ�ڵĽ�� 
    void print() const;                      // �������: ���������������ʹ�ã���Ա������Ӧ��������cin��cout��ֱ��ʹ��

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
 * delete_range: ɾ��ֵ��һ����Χ�ڵĽ�� 
 * param low: ��Χ�Ľ�С�߽�ֵ 
 * param high: ��Χ�Ľϴ�߽�ֵ 
 * note: �����ɾ�������е���ĳ��ֵ�Ľ����㷨û�б��������㷨˼�벻���ظ�˵�� 
*/
void List::delete_range(int low, int high)
{
	// 0. ��Ϊ��������ֱ�ӷ��� 
	if(!head->next)
	return;
	
	// 1. ���α��������е�ÿһ��Ԫ�أ�����ָ���ķ�Χ�������ɾ��
	ListNode *now=head->next; 
	ListNode *nowtemp=head;
	
	while(now)
	{
		if(now->val<=high&&now->val>=low)
		{
			nowtemp->next=now->next;
			delete now;
			
			now=nowtemp->next;
			nowtemp=nowtemp;
		}
		else
		{
			nowtemp=now;
			now=now->next;
		}
	}
	
	return;
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
	vector<int> data1={9,6,3,2,5,1,8,7,4}; 
	
	List lis1(data1);
	lis1.delete_range(5,8);
	lis1.print();
	
	cout<<"--------------------------------"<<endl;
	
	vector<int> data2={1,9,8,7,4,5,6,3,2};
	
	List lis2(data2);
	lis2.delete_range(5,8); 
	lis2.print();
	
	cout<<"--------------------------------"<<endl; 
	
	vector<int> data3={1,2,5,8,9,6,3,4,0,7};
	
	List lis3(data3);
	lis3.delete_range(5,8);  
	lis3.print();
	
	cout<<"--------------------------------"<<endl;
} 

