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
    
    void delete_dumplicate();          // �������ʵ�ֺ���: ɾ�������������ظ�ֵ�Ľ�� 
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
 * delete_dumplicate: ɾ����������������е��ظ�ֵ���
 * note 1: ���ڵ���������������ظ�ֵһ���������֣����ɾ��ʱ���Խ�������ɾ��
 * note 2: ����ĺ����㷨˼���ǣ�ʹ��һ���α�ָ��now��������������ÿ��now����һ���½�㣬��ʹ������һ�����α�ָ��pos����now��ʼ�����ҵ�һ��������now�Ľ�㣬Ȼ��ɾ�����pos��now֮������н�㼴�� 
*/
void List::delete_dumplicate()
{
	ListNode *now=head;
	
	while(now)
	{
		ListNode *pos=now;
		
		// ���ҽ��now���һ����now����ȵĽ��λ�� 
		while(pos&&pos->val==now->val)   
		{
			pos=pos->next;
		}
		
		// ɾ�����now�ͽ��pos֮������н�㣬��Щ��㶼���ظ���� 
		ListNode *temp=now->next;
		now->next=pos;
		
		// �����α�ָ��now 
		now=pos;   
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

