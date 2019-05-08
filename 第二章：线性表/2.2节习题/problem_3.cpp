#include <iostream>
#include <string>

using namespace std;

/*
 * delval: 从数组中删除指定值的所有元素，返回删除元素的数量 
 * param lis: 原始输入数组
 * param size: 原始输入数组的大小/元素数量
 * param val: 待删除的元素值 
 * note: 从数组中删除多个数值的方法较为直观和简单：使用一个变量count来记录当前已经遇到的需要删除的元素的个数，然后使用循环遍历整个数组: 当当前元素和待删除的值不相等而无需删除时，直接将其左移count位；当当前元素等于待删除的值因此要删除时，直接将计数器count加1 
*/ 
int delval(int lis[], int size, int val)
{
	int count=0;
	
	for(int i=0;i<size;i++)
	{
		if(lis[i]==val)
		count+=1;
		else
		lis[i-count]=lis[i];
	}
	
	return count;
}

int main(void)
{
	int lis[]={3,9,6,3,2,3,8,3,4,3};
	
	int count=delval(lis, 9, 3);
	
	for(int i=0;i<9-count;i++)
	{
		cout<<lis[i]<<" ";
	}
	
	cout<<endl;
} 
