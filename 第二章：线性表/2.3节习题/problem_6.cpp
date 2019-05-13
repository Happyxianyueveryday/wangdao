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
    
    void insert_sort();                 // �������ʵ�ֺ���: �Ը���������������в������� 
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
 * insert_sort: ��������в������� 
 * note: ��������в���������㷨Ҳ��Ϊ�򵥣����α���ÿһ����㣬ÿ�ν�һ�������뵽�ý��֮ǰ�������еĺ��ʲ��ּ��ɣ�ע��ʹ��˫ָ�뷨�Ļ���˼�롪��һ���α�ָ��now��now��ǰ�����ָ��nowtemp�ĺ��ļ��� 
*/
void List::insert_sort() 
{
	// 0. ����Ԫ������Ϳ������������� 
	if(!head->next||!head->next->next)
	return;
	
	// 1. �ӵڶ��������㿪ʼ�����α���ÿһ�������㣬������뵽�ý��֮ǰ����ȷ��λ����
	ListNode *now=head->next->next;
	ListNode *nowtemp=head->next;
	
	while(now)
	{
		// 1.1 �ڵ�ǰ���now֮ǰ�����򲿷ֲ�����ȷ�Ĳ���λ�� 
		ListNode *pos=head->next;    // ����λ�ã�����λ��ָ�����ڵ�ǰ���now֮ǰ�ģ���һ�����ڵ�ǰ���now��ֵ�Ľ�� 
		ListNode *postemp=head;      // ����λ�õ�ǰ����� 
		
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
		
		// 1.2 �����now��ԭλ�ý���ɾ�������뵽���pos֮ǰ��Ȼ������α�ָ��now��nowtemp 
		if(pos!=now)    // pos!=now����Ҫ���룬����˵��now���֮ǰ�Ľ���ֵ��С��now������ı�now��λ��
		{
			nowtemp->next=now->next; 
			now->next=postemp->next; 
			postemp->next=now;
			
			now=nowtemp->next;      // �����α�ָ��now��nowtemp 
  		    nowtemp=nowtemp;     
		} 
		else            //����ı�now��λ��ʱ��ֱ��ת������һ����� 
		{
			nowtemp=now;            // �����α�ָ��now��nowtemp 
			now=now->next;
		}
	}
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

