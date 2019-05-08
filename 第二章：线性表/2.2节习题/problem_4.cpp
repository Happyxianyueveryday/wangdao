#include <iostream>
#include <string>

using namespace std;

/*
 * delrange: 从数组中删除指定范围的所有元素，返回删除元素的数量 
 * param lis: 原始输入数组
 * param size: 原始输入数组的大小/元素数量
 * param min: 待删除的元素的范围下界 
 * param max: 待删除的元素的范围上界 
 * note: 本题的算法和problem_3类似，此处不再赘述 
*/ 
int delval(int lis[], int size, int min, int max)
{
	int count=0;
	
	if(min>max)    // 若min>max，这时范围[min,max]为空，无法删除元素，故直接返回 
	return 0;
	
	for(int i=0;i<size;i++)
	{
		if(lis[i]>=min&&lis[i]<=max)
		count+=1;
		else
		lis[i-count]=lis[i];
	}
	
	return count;
}

int main(void)
{
	int lis[]={3,9,6,3,2,3,8,3,4,3};
	
	int count=delval(lis, 9, 2, 6);
	
	for(int i=0;i<9-count;i++)
	{
		cout<<lis[i]<<" ";
	}
	
	cout<<endl;
} 
