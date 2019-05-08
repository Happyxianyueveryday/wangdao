#include <iostream>
#include <string>

using namespace std;

/*
 * reverse: 将给定的数组进行逆置操作/反转操作 
 * param lis: 原数组
 * param size: 原数组大小/元素个数 
*/
void reverse(int lis[], int size)
{
	for(int i=0;i<size/2;i++)
	{
		int temp=lis[i];
		lis[i]=lis[size-1-i];
		lis[size-1-i]=temp;
	}
	
	return;
}


int main(void)
{
	int lis[9]={9,6,3,2,5,8,7,4,1};
	int lis2[10]={0,2,5,8,9,6,3,1,4,7};
	reverse(lis, 9);
	reverse(lis2, 10);
	
	cout<<"反转操作后的数组为: lis = "<<endl;
	for(int i=0;i<9;i++)
	{
		cout<<lis[i]<<" ";
	}
	cout<<endl;
	
	cout<<"反转操作后的数组为: lis2 = "<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<lis2[i]<<" ";
	}
	cout<<endl;
}
