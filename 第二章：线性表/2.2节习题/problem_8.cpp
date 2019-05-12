#include <iostream>
#include <string>

using namespace std;

/*
 * swaplist: ����һ�������������������λ�ã����罫{1,2,3,4,5,8,9,10}, m=5, n=3��ת���ɵĽ��Ϊ{8,9,10,1,2,3,4,5} 
 * param lis: ԭʼ�������飬����������������������ɣ�ǰm������Ԫ�ع���һ�������飬��n������Ԫ�ع���һ��������
 * param m: ��һ��������ĳ���  
 * param n: �ڶ���������ĳ��� 
 * note: ��ǰm��Ԫ���ƶ�����n��Ԫ��֮����㷨�ǳ���: ���Ƚ�ǰm��Ԫ�����ã�Ȼ�󽫺�n��Ԫ�����ã���������������� 
*/ 
void swaplist(int lis[], int m, int n)
{
	// 1. ����ǰm��Ԫ�� 
	for(int i=0;i<m/2;i++)
	{
		int temp=lis[i];
		lis[i]=lis[m-1-i];
		lis[m-1-i]=temp;
	}
	
	// 2. ���ú�n��Ԫ�أ���n��Ԫ��ͬ�������������±�0��ʼ��ֻ��������һ��ƫ����m 
	for(int i=0;i<n/2;i++)
	{
		int temp=lis[m+i];
		lis[m+i]=lis[m+(n-1-i)];
		lis[m+(n-1-i)]=temp;
	}
	
	// 3. ��������������� 
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
