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
    
    void sort_and_print();                   // �������ʵ�ֺ���: ��С���������������н�㣬����������ͷ��������� 
    void print() const;                      // �������: ���������������ʹ�ã���Ա������Ӧ��������cin��cout��ֱ��ʹ��

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
 * sort_and_print: С���������������н�㣬����������ͷ���������
 * note: ����������Ҫʹ�õ��㷨�ǳ��򵥣����ȶ�ԭ������в�������Ȼ����˳���������������ͬʱ�ͷ������㼴�� 
*/
void List::sort_and_print()
{
	// 1. ���ȶ�ԭ������в����������ԭ�����ǿ�������ߵ�������� 
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
	
	// 2. Ȼ������������������������㲢�ͷŽ��
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

