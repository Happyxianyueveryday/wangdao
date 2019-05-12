#include <iostream> 
#include <string>

using namespace std;

/*
 * binary_search: ���ֲ����㷨ʵ�� 
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
 * search_and_insert: ���ҺͲ���
 * param lis: ԭʼ���� 
 * param size: ��ǰ����Ĵ�С 
 * param target: Ҫ���ҺͲ����Ŀ��ֵ 
 * note: �����Ҫ��ʵ���Ϸǳ��򵥣������ڸ����������н��ж��ֲ��ң����ܲ��ҵ���ֵ����������Ԫ�ؽ��������޺��Ԫ���򲻽������������Ҳ��������ø�ֵ�滻ԭ�����е����ֵ 
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
