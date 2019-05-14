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
    
    List(const List &a, const List &b);  // �������ʵ�ֺ���: ��������������ĵ������еĽ������������� 
    
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
 * List: ��������������ĵ������еĹ�ͬԪ������������ 
 * note 1: ��������������ĵ������еĹ�ͬԪ��������С���еķ�������һ�����ƣ���������Ԫ�ؿ��ܳ����ظ�ֵ���������в������ظ�ֵ������{1,2,5,5,5}��{3,4,5,5}�Ĺ�ͬԪ����{5,5}��������������๲ͬ��2��5����˽���д���2��5�������ǽ���Ϊ{5} 
 * note 2: �����ʵ���㷨Ҳ����һ�����ƣ�ʹ�������α�ָ��now1��now2�ֱ������������a��b��ѭ���������²���ֱ��now1��now2����һ��Ϊ��Ϊֹ: 
 *         (1) ��now1��ֵС��now2��ֵ����ָ��now1ǰ��һ��
 *         (2) ��now1��ֵ����now2��ֵ����ָ��now2ǰ��һ��
 *         (3) ��ָ��now1��ֵ����ָ��now2��ֵ����ָ��now1��ֵ�����������У����ƶ�now1����һ�������ڵ�ǰnow1��ֵ�Ľ���ϣ��ƶ�now2����һ�������ڵ�ǰnow2��ֵ�Ľ���ϣ���һ��Ĵ�������һ��Ĺ�ͬԪ�ز�ͬ�����������еĹ�ͬԪ��ֵ���Գ����ظ����������������еĽ���Ԫ��һ���������ظ���֮�����ƶ�now1��now2�������ڵ�ǰֵ�Ľ���ϣ�ԭ�����Ϊ�˱�֤��������в������ظ��� 
*/
List::List(const List &a, const List &b)
{
	head=new ListNode(0);           // ������������ͷ���ƽ��
	
	ListNode *now1=a.head->next;    // ����a���α�ָ��now1 
	ListNode *now2=b.head->next;    // ����b���α�ָ��now2 
	ListNode *resnow=head;
	
	while(now1&&now2)
	{
		// 1. ��now1��ֵС��now2����now1ǰ��һ�� 
		if(now1->val<now2->val)
		now1=now1->next;
		
		// 2. ��now2��ֵС��now1����now2ǰ��һ�� 
		else if(now1->val>now2->val)
		now2=now2->next;
		
		// 3. ��now1��now2��ֵ��ȣ��򽫸ý���ֵ�����������У���now1��now2�ֱ��ƶ�����һ�������ڵ�ǰֵ�Ľ�� 
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

