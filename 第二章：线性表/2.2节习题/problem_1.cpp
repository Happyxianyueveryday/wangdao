#include <iostream>
#include <string>

using namespace std;

/*
 * delmin: 从给定的数组中删除具有最小值的元素（假设最小值唯一），并返回被删除的元素的值，被删除的元素的位置由数组的最后一个元素进行填补，若顺序表为空则输出错误信息并退出运行 
 * param lis: 输入的给定数组 
 * param size: 数组的元素个数/数组的大小 
*/
int delmin(int lis[], int size)
{
	if(!size)
	{
		cout<<"数组为空，删除最小的元素失败!"<<endl;
		return 0;
	}
	
	// 1. 从给定的数组中找到最小值的位置和下标
	int min=lis[0];
	int pos=0;
	
	for(int i=0;i<size;i++)
	{
		if(lis[i]<=min)
		{
			min=lis[i];
			pos=i;
		}
	}
	
	// 2. 将数组最后一个元素填到数组最小值位置，从而删除数组中的最小值
	lis[pos]=lis[size-1];
	
	// 3. 返回删除的最小值元素
	return min; 
}

int main(void)
{	
	int lis[9]={7,4,1,2,5,8,9,6,3};
	
	cout<<"删除的数组最小值为: "<<delmin(lis, 9)<<endl;
	cout<<"删除后的数组lis为 lis = "<<endl;
	
	for(int i=0;i<8;i++)
	{
		cout<<lis[i]<<" ";
	}
	cout<<endl;
}
