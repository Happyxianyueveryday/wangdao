#include <iostream> 
#include <string>

using namespace std;

/*
 * recycle_right_shift: 数组的循环右移算法实现 
 * param lis: 原始输入数组
 * param size: 原始输入数组的元素个数
 * param k: 需要循环右移的位数 
 * note: 本题循环右移的算法和第8题类似，只不过第8题实现的是循环左移 
 * note: 循环左移k位的算法是: 首先将数组的前k位逆置，然后将数组的后(size-k)位逆置，最后将整个数组逆置
 *       而循环右移k位的算法是: 首先将整个数组逆置，然后将数组的前k位逆置，最后将数组的后(size-k)位逆置
 *       不难看出，循环左移和循环右移算法所包含的三个基本操作都是一致的，只是顺序不同，循环左移时首先对整个数组进行逆置，循环右移时最后对整个数组进行逆置 
*/
void recycle_right_shift(int lis[], int size, int k)
{
	// 1. 首先计算实际上需要移位的位数
	k=k%size;
	
	// 2. 首先将整个数组进行逆置
	for(int i=0;i<size/2;i++) 
	{
		int temp=lis[i];
		lis[i]=lis[size-1-i];
		lis[size-1-i]=temp;
	}
	
	// 3. 然后将数组的前k位进行逆置
	for(int i=0;i<k/2;i++)
	{
		int temp=lis[i];
		lis[i]=lis[k-1-i];
		lis[k-1-i]=temp;
	}
	
	// 4. 最后将数组的后m=(size-k)位进行逆置，后m位可以看作前m位（下标从0开始）的情况，再统一加上一个偏移量k 
	int m=size-k;
	for(int i=0;i<m/2;i++)
	{
		int temp=lis[k+i];
		lis[k+i]=lis[k+m-1-i];
		lis[k+m-1-i]=temp;
	}
	
	return;
}


int main(void)
{
	int lis[]={1,2,3,4,5,8,9,10};
	
	recycle_right_shift(lis, 8, 3);
	
	for(int i=0;i<8;i++)
	{
		cout<<lis[i]<<" ";
	}
	cout<<endl;
}
