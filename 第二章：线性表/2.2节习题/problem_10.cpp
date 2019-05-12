#include <iostream> 
#include <string>

using namespace std;

/*
 * binary_search: 二分查找算法实现 
*/
int binary_search(int lis[], int size, int target)
{
	int begin=0;
	int end=size-1;
	
	while(begin<=end)
	{
		int mid=begin+(end-begin)/2;
		
		if(target>lis[mid])
		begin=mid+1;
		else if(target<lis[mid])
		end=mid-1;
		else
		return mid;
	}
	
	return -1;
} 


/*
 * search_and_insert: 查找和插入
 * param lis: 原始数组 
 * param size: 当前数组的大小 
 * param target: 要查找和插入的目标值 
 * note: 本题的要求实质上非常简单，首先在给定的数组中进行二分查找，若能查找到该值，则将其与后继元素交换（若无后继元素则不交换），若查找不到，则用该值替换原数组中的最大值 
*/
void search_and_insert(int lis[], int size, int target) 
{
	int index=binary_search(lis, size, target);
	
	if(index==-1)
	{
		lis[size-1]=target;
	}
	else if(index!=size-1)
	{
		int temp=lis[index];
		lis[index]=lis[index+1];
		lis[index+1]=temp;
	}
	
	return;
}


int main(void)
{
	int lis[]={1,2,3,4,5,6,7,8,9};
	
	search_and_insert(lis, 9, 5);
	
	for(int i=0;i<9;i++)
	{
		cout<<lis[i]<<endl;
	}
} 
