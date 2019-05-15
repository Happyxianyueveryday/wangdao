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
    
    bool sublist(const List &lis);     // �������ʵ�ֺ���: �жϵ�ǰ�����Ƿ�Ϊ����������������������� 
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
 * sublist: �жϵ�ǰ�����Ƿ�����������������������
 * note: ��������Ҫʹ�õ��㷨����Ϊ: ���δ����������ÿһ����㿪ʼ����ƥ�伴�ɣ�һ������ʧ�����������������һ����㿪ʼ����ƥ��
*/
bool List::sublist(const List &lis)
{
	ListNode *pos2=lis.head->next;    // ��Ŀ����������ʼƥ��Ľ��
	
	while(pos2)
	{
		ListNode *pos1=head->next;        // �ڵ�ǰ��������ʼƥ��Ľ�� 
		
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
		
		if(pos1==NULL)   // ������ѭ������ʱ��pos1ָ��գ�����ʱ���ƥ��
		return true;
		else             // ����ƥ��δ��ɾͱ��жϣ���ʱƥ��ʧ�ܣ�����һ����㿪ʼƥ�� 
		{
			pos2=pos2->next;
			continue;
		}
	}
	
	return false;        // ���н��ƥ����Ͼ����ɹ����򷵻�ƥ��ʧ�� 
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
	cout<<"����lis2������lis1������������"<<endl;
	else
	cout<<"����lis2��������lis1������������"<<endl;
	
	if(lis3.sublist(lis1))
	cout<<"����lis3������lis1������������"<<endl;
	else
	cout<<"����lis3��������lis1������������"<<endl;
	
	if(lis4.sublist(lis1))
	cout<<"����lis4������lis1������������"<<endl;
	else
	cout<<"����lis4��������lis1������������"<<endl;
	
	if(lis5.sublist(lis1))
	cout<<"����lis5������lis1������������"<<endl;
	else
	cout<<"����lis5��������lis1������������"<<endl;
	
} 

