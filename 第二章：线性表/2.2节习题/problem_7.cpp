#include <iostream>
#include <string>

using namespace std;

/*
 * merge: 将两个有序数组组合成为一个有序数组
 * param lis1, lis2: 输入的有序数组1，有序数组2 
 * param size1, size2: 输入的有序数组1的元素个数，有序数组2的元素个数 
 * note: 本题实质上和归并排序中的归并过程是一致的 
*/
int *merge(int lis1[], int lis2[], int size1, int size2)
{
	int *res=new int[size1+size2];
	
	int pos1=0;
	int pos2=0;
	int tarpos=0;
	
	while(pos1<size1&&pos2<size2)
	{
		if(lis1[pos1]<=lis2[pos2])
		{
			res[tarpos]=lis1[pos1];
			pos1+=1;
			tarpos+=1;
		}
		else
		{
			res[tarpos]=lis2[pos2];
			pos2+=1;
			tarpos+=1;
		}
	}
	
	while(pos1<size1)
	{
		res[tarpos]=lis1[pos1];
		pos1+=1;
		tarpos+=1;
	}
	
	while(pos2<size2)
	{
		res[tarpos]=lis2[pos2];
		pos2+=1;
		tarpos+=1;
	}
	
	return res;
}

int main(void)
{
	int lis1[]={1,3,5,7,9};
	int lis2[]={2,4,6,8,10};
	
	int *res=merge(lis1, lis2, 5, 5);
	
	for(int i=0;i<10;i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
	
	delete [] res; 
}
