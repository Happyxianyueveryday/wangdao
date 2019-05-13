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
    
    void partition();                  // �������ʵ�ֺ���: ������{a1,b1,a2,b2,...,an,bn}�ֽ�Ϊ{a1,a2,a3,...,an}��{bn,...,b2,b1} 
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
 * partition: ������{a1,b1,a2,b2,...,an,bn}�ֽ�Ϊ{a1,a2,a3,...,an}��{bn,...,b2,b1} 
 * note: ������㷨�ǳ��򵥣����Ȱ��ս�����ŵ���ż�Խ�������Ϊ��ż�����֣�Ȼ��ż����ת���� 
*/
void List::partition()
{
	// 1. ������ָ�Ϊ��ż������ 
	ListNode *odd=new ListNode(0);
	ListNode *even=new ListNode(0);
	
	ListNode *oddnow=odd;
	ListNode *evennow=even;
	ListNode *now=head->next;
	
	int count=1;
	
	while(now)
	{
		if(count%2)
		{
			oddnow->next=new ListNode(now->val);
			oddnow=oddnow->next;
		}
		else
		{
			evennow->next=new ListNode(now->val);
			evennow=evennow->next;
		}
		now=now->next;
		count+=1;
	}
	
	// 2. ��ż������з�ת
	if(even->next&&even->next->next)
	{
		ListNode *now=even->next->next; 
		ListNode *nowtemp=even->next;
	
		while(now)
		{
			nowtemp->next=now->next;
			now->next=even->next;
			even->next=now;
			
			nowtemp=nowtemp;
			now=nowtemp->next;
		}
	}
	
	// 3. ����ָ�������
	now=odd->next;
	
	while(now) 
	{
		cout<<now->val<<" ";
		now=now->next;
	}
	cout<<endl;
	
	now=even->next;
	
	while(now) 
	{
		cout<<now->val<<" ";
		now=now->next;
	}
	cout<<endl;
	
	return;
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
	lis1.partition();
	
	cout<<"--------------------------------"<<endl;
	
	vector<int> data2={1,9,8,7,4,5,6,3,2}; 
	
	List lis2(data2);
	lis2.partition(); 
	
	cout<<"--------------------------------"<<endl; 
	
	vector<int> data3={1,2,5,8,9,6,3,4,0,7};
	
	List lis3(data3);
	lis3.partition();  
		
	cout<<"--------------------------------"<<endl;
} 

