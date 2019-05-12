#include <iostream> 
#include <string>
#include <cstring>

using namespace std;

/*
 * get_min_disappear: 
 * param lis: 原始输入数组 
 * param size: 输入数组的大小 
 * note: 本题的最优解法就是创建一个大小为size的标记数组dic，分别用于记录正整数1~size是否出现过，因为大小为size的数组的最小未出现整数必定在1到n之间（这一个推论十分重要），首先遍历整个数组，若当前元素的值在范围1~n，则在标记数组dic的对应位置进行标记，遍历结束后，从dic中找出未被标记的最小元素即可 
 * note: 本题也可以使用先快速排序在进行查找的方法做，时间复杂度为O(nlogn) 
*/
int get_min_disappear(int lis[], int size)
{
	int dic[size];
	memset(dic, 0, size*sizeof(int));
	
	for(int i=0;i<size;i++)	
	{
		if(lis[i]>=1&&lis[i]<=size)
		dic[lis[i]-1]=1;
	}
	
	for(int i=0;i<size;i++)
	{
		if(!dic[i])
		return i+1;
	}
	
	return -1; 
}


int main(void)
{
	int lis[]={-5,3,2,3};
	int size=4;
	
	int lis1[]={9,6,3,2,4,8,7,4,1};
	int size1=9;
	
	cout<<get_min_disappear(lis, size)<<endl;
	cout<<get_min_disappear(lis1, size1)<<endl;
} 
