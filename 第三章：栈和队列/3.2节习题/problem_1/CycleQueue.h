#include <iostream> 
#include <vector>

using namespace std;

class CycleQueue
{
	public: 
	// 1. 构造函数 
	CycleQueue(int max_size);
	CycleQueue(int max_size, const vector<int> &lis);
	
	// 2. 拷贝控制
	CycleQueue(const CycleQueue &other);
	CycleQueue & operator = (const CycleQueue &other);
	
	// 3. 功能函数 
	bool push(int val);         // 新元素入队 
	bool pop(int &val);         // 队首元素出队 
	bool frontval(int &val) const; // 获取队首元素 
	void clear();               // 清空队列 
	int length() const;         // 获取队列中的元素个数 
	
	// 4. 析构函数
	~CycleQueue();              // 类的析构函数  
	
	private: 
	int *data;                  // 队列数据实际存储的数组
	int front;                  // 循环队列中游标front指向队首元素的下标 
	int back;                   // 循环队列中游标back指向队尾元素的下标，本项目中循环数组队列的实现使用单标志法来区分队列空和队列满，因此可以利用循环数组中的所有单元，而无需像空余单元法中一样空出一个单元来进行区分 
	int MAX_SIZE;               // 数组的最大大小，即队列中最多允许的元素个数 
	int flag;                   // 标记队列是否已经满的标志，flag==0表示队列为空，flag==1表示队列已经满，该标志用于区分当front==end时是队空还是队满 
};

/*
 * CycleQueue: 默认构造函数 
*/
CycleQueue::CycleQueue(int max_size)
{
	data=new int [max_size];
	front=back=0;
	MAX_SIZE=max_size;
	flag=0;
}

/*
 * CycleQueue: 从数组构造队列 
*/
CycleQueue::CycleQueue(int max_size, const vector<int> &lis)
{
	if(lis.size()>max_size)   // 若输入不合法，则默认构造一个空的队列，队列的最大大小为100 
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
 * CycleQueue: 拷贝构造函数 
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
 * CycleQueue: 拷贝赋值运算符 
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
 * push: 将元素入队列 
 * note: 循环队列中，在将元素入队之前，首先需要判断队列是否已经满，在单标志法中，若front==end且flag==1则表示队列已经满，否则队列未满；在元素入队之后，要重新检查队列是否满，若入队后front==end，则队列为满，更新标志变量flag=0 
*/
bool CycleQueue::push(int val)
{
	if(front==back&&flag==1)
	return false;
	else
	{
		data[back]=val;
		back=(back+1)%MAX_SIZE;
		
		if(front==back)   // 若在入队后满足front==back，则队列已满，置标志变量flag=1 
			flag=1;
			
		return true;
	}
}

/*
 * pop: 将队首元素出队 
 * note: 循环队列中，在将元素出队之前，首先需要判断队列是否为空，在单标志法中，若front==end且flag==0则表示队列已经空，否则队列未空；在元素出队之后，需要重新检查队列是否空，若出队后front==end，则队列为空，更新标志变量flag=0 
*/
bool CycleQueue::pop(int &val)
{
	if(front==back&&flag==0)
	return false;
	else
	{
		val=data[front];
		front=(front+1)%MAX_SIZE;
		
		if(front==back)  // 若在入队后满足front==back，则队列已空，置标记变量flag=0 
			flag=0;
			
		return true;
	}
}

/*
 * frontval: 返回队首元素 
 * note: 返回队首元素的算法和出队过程大致相同，本处不再重复介绍 
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
 * clear: 清空栈中元素 
*/
void CycleQueue::clear()
{
	front=back=0;
	flag=0;
}
	
/*
 * length: 返回栈中的元素数量 
*/
int CycleQueue::length() const
{
	if(front==back&&flag==1)
		return MAX_SIZE;
	else
		return (back-front+MAX_SIZE)%MAX_SIZE;    // 该公式需要使用几个简单的例子来进行推导，更简单的方法是直接记下来该公式 
}

/*
 * ~CycleQueue: 析构函数  
*/ 
CycleQueue::~CycleQueue()
{
	delete [] data;
}


