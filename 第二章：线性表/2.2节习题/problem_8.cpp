#include <iostream>
#include <string>

using namespace std;

/*
 * swaplist: 交换一个数组中两个子数组的位置，例如将{1,2,3,4,5,8,9,10}, m=5, n=3，转换成的结果为{8,9,10,1,2,3,4,5} 
 * param lis: 原始输入数组，该数组由两部分子数组组成，前m个数组元素构成一个子数组，后n个数组元素构成一个子数组
 * param m: 第一个子数组的长度  
 * param n: 第二个子数组的长度 
 * note: 将前m个元素移动到后n个元素之后的算法非常简单: 首先将前m个元素逆置，然后将后n个元素逆置，最后将整个数组逆置 
*/ 
void swaplist(int lis[], int m, int n)
{
	// 1. 逆置前m个元素 
	for(int i=0;i<m/2;i++)
	{
		int temp=lis[i];
		lis[i]=lis[m-1-i];
		lis[m-1-i]=temp;
	}
	
	// 2. 逆置后n个元素，后n个元素同样可以视作从下标0开始，只不过加了一个偏移量m 
	for(int i=0;i<n/2;i++)
	{
		int temp=lis[m+i];
		lis[m+i]=lis[m+(n-1-i)];
		lis[m+(n-1-i)]=temp;
	}
	
	// 3. 最后逆置整个数组 
	for(int i=0;i<(m+n)/2;i++)
	{
		int temp=lis[i];
		lis[i]=lis[m+n-1-i];
		lis[m+n-1-i]=temp;
	}
}

int main(void)
{
	int lis[]={1,2,3,4,5,8,9,10};
	
	swaplist(lis, 5, 3);
	
	for(int i=0;i<8;i++)
	{
		cout<<lis[i]<<" ";
	}
	cout<<endl;
}
