#include <iostream> 
#include <string>
#include <vector>
#include <cstdlib>

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
    
    void delete_val(int val);         // �������ʵ�ֺ���: ��������ɾ��ֵΪָ��ֵ�Ľ�� 
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
 * delete_val: ��������ɾ������Ϊָ��ֵ�Ľ��
 * param val: �����ָ��ֵ
 * note: ɾ���ķ����ǳ��򵥣�ʹ��һ��ָ��now��������������ÿһ������ͬʱ��ʹ��һ��ǰ�����ָ��tempnow�����ټ�¼ָ��now��ǰ����㼴�ɣ������now��ֵ��Ŀ��ֵ��ͬ��ɾ��ʱ��ֱ��ͨ��ǰ�����tempnowɾ��now���� 
*/
void List::delete_val(int val)
{
	ListNode *now=head->next;    // �α�ָ��now 
	ListNode *tempnow=head;      // �α�ָ��now��ǰ�����tempnow 
	
	while(now)
	{
		if(now->val==val)        // �����now��ֵ��Ŀ��ֵ��ȣ���ͨ��ǰ�����tempnowɾ�����now 
		{
			tempnow->next=now->next;
			delete now;
			
			now=tempnow->next;       // �����α�ָ��now 
			tempnow=tempnow;         // ǰ�����ָ��tempnow���� 
		}
		else
		{
			tempnow=now;             // �ƶ�ǰ�����ָ��tempnow 
			now=now->next;           // �ƶ��α�ָ��now
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
	vector<int> data1={5,5,5,5,5,5,5,5,5,5};
	
	List lis1(data1);
	lis1.print();
	lis1.delete_val(5);
	lis1.print();
	
	cout<<"--------------------------------"<<endl;
	
	vector<int> data2={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0};
	List lis2(data2);
	lis2.print();
	lis2.delete_val(8);
	lis2.print();
	
	cout<<"--------------------------------"<<endl;
	
	vector<int> data3={9,6,3,2,8,5,2,1,4,7,8,4,5,6,8,7,5,5};
	List lis3(data3);
	lis3.print();
	lis3.delete_val(8);  
	lis3.print();
	
	cout<<"--------------------------------"<<endl;
} 

