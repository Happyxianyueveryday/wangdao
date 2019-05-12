#include <iostream> 
#include <string>

using namespace std;

/*
 * recycle_right_shift: �����ѭ�������㷨ʵ�� 
 * param lis: ԭʼ��������
 * param size: ԭʼ���������Ԫ�ظ���
 * param k: ��Ҫѭ�����Ƶ�λ�� 
 * note: ����ѭ�����Ƶ��㷨�͵�8�����ƣ�ֻ������8��ʵ�ֵ���ѭ������ 
 * note: ѭ������kλ���㷨��: ���Ƚ������ǰkλ���ã�Ȼ������ĺ�(size-k)λ���ã����������������
 *       ��ѭ������kλ���㷨��: ���Ƚ������������ã�Ȼ�������ǰkλ���ã��������ĺ�(size-k)λ����
 *       ���ѿ�����ѭ�����ƺ�ѭ�������㷨������������������������һ�µģ�ֻ��˳��ͬ��ѭ������ʱ���ȶ���������������ã�ѭ������ʱ������������������� 
*/
void recycle_right_shift(int lis[], int size, int k)
{
	// 1. ���ȼ���ʵ������Ҫ��λ��λ��
	k=k%size;
	
	// 2. ���Ƚ����������������
	for(int i=0;i<size/2;i++) 
	{
		int temp=lis[i];
		lis[i]=lis[size-1-i];
		lis[size-1-i]=temp;
	}
	
	// 3. Ȼ�������ǰkλ��������
	for(int i=0;i<k/2;i++)
	{
		int temp=lis[i];
		lis[i]=lis[k-1-i];
		lis[k-1-i]=temp;
	}
	
	// 4. �������ĺ�m=(size-k)λ�������ã���mλ���Կ���ǰmλ���±��0��ʼ�����������ͳһ����һ��ƫ����k 
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
