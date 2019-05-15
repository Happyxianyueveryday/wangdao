#include <iostream> 
#include <string>
#include <vector>
#include <cstdlib>
#include <stack>
#include <set>

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
    
    void remove_dumplicate();          // �������ʵ�ֺ���: ɾ�������о���ֵ��ͬ���ظ����
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
 * remove_dumplicate: ɾ�������о���ֵ��ͬ���ظ����
 * note: ����ͬ����ʹ��һ����ϣ��(set)����¼��Щ���ֵ�Ѿ����ֹ��������ڹ�ϣ�����Ѿ�������ֵͬ�Ľ�����ɾ������ 
*/
void List::remove_dumplicate() 
{
	set<int> dic;
	
	ListNode *now=head->next, *nowprev=head;
	
	while(now)
	{
		if(dic.count(now->val))
		{
			nowprev->next=now->next;
			delete now;
			
			nowprev=nowprev;
			now=nowprev->next;
		}
		else
		{
			dic.insert(now->val);
			nowprev=now;
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
        delete temp;   
    }
}


int main(void)
{
	vector<int> data1={9,8,7,5,8,9,5,6,4,5,6,3,8,7,4,1,2,6,6,9,8,7,4,1,5,6,3};  
	
	List lis1(data1);
	lis1.remove_dumplicate();
	lis1.print();
	
	cout<<"--------------------------------"<<endl;
	
	vector<int> data2={1,2,3,3,4,4,5,5,6,6,6,7,7,7,8,8,9,9};
	
	List lis2(data2);
	lis2.remove_dumplicate(); 
	lis2.print();
	
	cout<<"--------------------------------"<<endl; 
	
	vector<int> data3={1,1,1,1,1,1,1,1,1,};
	
	List lis3(data3);
	lis3.remove_dumplicate();
	lis3.print();
	
	cout<<"--------------------------------"<<endl;
} 

