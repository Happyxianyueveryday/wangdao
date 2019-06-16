#include <iostream> 
#include <vector>

using namespace std;

class CycleQueue
{
	public: 
	// 1. ���캯�� 
	CycleQueue(int max_size);
	CycleQueue(int max_size, const vector<int> &lis);
	
	// 2. ��������
	CycleQueue(const CycleQueue &other);
	CycleQueue & operator = (const CycleQueue &other);
	
	// 3. ���ܺ��� 
	bool push(int val);         // ��Ԫ����� 
	bool pop(int &val);         // ����Ԫ�س��� 
	bool frontval(int &val) const; // ��ȡ����Ԫ�� 
	void clear();               // ��ն��� 
	int length() const;         // ��ȡ�����е�Ԫ�ظ��� 
	
	// 4. ��������
	~CycleQueue();              // �����������  
	
	private: 
	int *data;                  // ��������ʵ�ʴ洢������
	int front;                  // ѭ���������α�frontָ�����Ԫ�ص��±� 
	int back;                   // ѭ���������α�backָ���βԪ�ص��±꣬����Ŀ��ѭ��������е�ʵ��ʹ�õ���־�������ֶ��пպͶ���������˿�������ѭ�������е����е�Ԫ������������൥Ԫ����һ���ճ�һ����Ԫ���������� 
	int MAX_SIZE;               // ���������С������������������Ԫ�ظ��� 
	int flag;                   // ��Ƕ����Ƿ��Ѿ����ı�־��flag==0��ʾ����Ϊ�գ�flag==1��ʾ�����Ѿ������ñ�־�������ֵ�front==endʱ�Ƕӿջ��Ƕ��� 
};

/*
 * CycleQueue: Ĭ�Ϲ��캯�� 
*/
CycleQueue::CycleQueue(int max_size)
{
	data=new int [max_size];
	front=back=0;
	MAX_SIZE=max_size;
	flag=0;
}

/*
 * CycleQueue: �����鹹����� 
*/
CycleQueue::CycleQueue(int max_size, const vector<int> &lis)
{
	if(lis.size()>max_size)   // �����벻�Ϸ�����Ĭ�Ϲ���һ���յĶ��У����е�����СΪ100 
	{
		data=new int [100];
		front=back=0;
		MAX_SIZE=100;
		return; 
	}
	
	data=new int [max_size];
	front=0;
	back=lis.size();
	MAX_SIZE=max_size;
	flag=(lis.size()==MAX_SIZE)?1:0;
	
	for(int i=0;i<lis.size();i++)
	{
		data[i]=lis[i];
	}
	
	return;
}

/*
 * CycleQueue: �������캯�� 
*/
CycleQueue::CycleQueue(const CycleQueue &other)
{
	data=new int[other.MAX_SIZE];
	MAX_SIZE=other.MAX_SIZE;
	front=other.front;
	back=other.back;
	flag=other.flag;
	
	for(int i=front;i<back;i++)
	{
		data[i]=other.data[i];
	}
}

/*
 * CycleQueue: ������ֵ����� 
*/
CycleQueue & CycleQueue::operator = (const CycleQueue &other)
{
	if(&other==this) 
	return (*this);
	
	delete [] data;
	
	data=new int[other.MAX_SIZE];
	MAX_SIZE=other.MAX_SIZE;
	front=other.front;
	back=other.back;
	flag=other.flag;
	
	for(int i=front;i<back;i++)
	{
		data[i]=other.data[i];
	}
} 

/*
 * push: ��Ԫ������� 
 * note: ѭ�������У��ڽ�Ԫ�����֮ǰ��������Ҫ�ж϶����Ƿ��Ѿ������ڵ���־���У���front==end��flag==1���ʾ�����Ѿ������������δ������Ԫ�����֮��Ҫ���¼������Ƿ���������Ӻ�front==end�������Ϊ�������±�־����flag=0 
*/
bool CycleQueue::push(int val)
{
	if(front==back&&flag==1)
	return false;
	else
	{
		data[back]=val;
		back=(back+1)%MAX_SIZE;
		
		if(front==back)   // ������Ӻ�����front==back��������������ñ�־����flag=1 
			flag=1;
			
		return true;
	}
}

/*
 * pop: ������Ԫ�س��� 
 * note: ѭ�������У��ڽ�Ԫ�س���֮ǰ��������Ҫ�ж϶����Ƿ�Ϊ�գ��ڵ���־���У���front==end��flag==0���ʾ�����Ѿ��գ��������δ�գ���Ԫ�س���֮����Ҫ���¼������Ƿ�գ������Ӻ�front==end�������Ϊ�գ����±�־����flag=0 
*/
bool CycleQueue::pop(int &val)
{
	if(front==back&&flag==0)
	return false;
	else
	{
		val=data[front];
		front=(front+1)%MAX_SIZE;
		
		if(front==back)  // ������Ӻ�����front==back��������ѿգ��ñ�Ǳ���flag=0 
			flag=0;
			
		return true;
	}
}

/*
 * frontval: ���ض���Ԫ�� 
 * note: ���ض���Ԫ�ص��㷨�ͳ��ӹ��̴�����ͬ�����������ظ����� 
*/
bool CycleQueue::frontval(int &val) const
{
	if(front==back&&flag==0)
	return false;
	else
	{
		val=data[front];
		return true;
	}
}

/*
 * clear: ���ջ��Ԫ�� 
*/
void CycleQueue::clear()
{
	front=back=0;
	flag=0;
}
	
/*
 * length: ����ջ�е�Ԫ������ 
*/
int CycleQueue::length() const
{
	if(front==back&&flag==1)
		return MAX_SIZE;
	else
		return (back-front+MAX_SIZE)%MAX_SIZE;    // �ù�ʽ��Ҫʹ�ü����򵥵������������Ƶ������򵥵ķ�����ֱ�Ӽ������ù�ʽ 
}

/*
 * ~CycleQueue: ��������  
*/ 
CycleQueue::~CycleQueue()
{
	delete [] data;
}


