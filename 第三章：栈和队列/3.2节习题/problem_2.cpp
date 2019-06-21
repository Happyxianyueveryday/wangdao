#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

/**
 * reverse_queue: ʹ��ջ��ת����
 * note: ʹ��ջ�����ж��з� 
 */
void reverse_queue(queue<int> &que)
{
	stack<int> sta;
	
	while(que.size())
	{
		sta.push(que.front());
		que.pop();
	}
	
	while(sta.size())
	{
		que.push(sta.top());
		sta.pop();
	}
}

int main(void)
{
	queue<int> que;
	int data[]={1,2,3,4,5,6,7};
	
	for(int i=0;i<7;i++)
	{
		que.push(data[i]);
	} 
	
	reverse_queue(que);
	
	while(que.size())
	{
		cout<<que.front()<<" ";
		que.pop();
	}
}
