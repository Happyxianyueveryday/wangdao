#include <iostream>
#include <string>

using namespace std;

/*
 * delrange: ��������ɾ��ָ����Χ������Ԫ�أ�����ɾ��Ԫ�ص����� 
 * param lis: ԭʼ��������
 * param size: ԭʼ��������Ĵ�С/Ԫ������
 * param min: ��ɾ����Ԫ�صķ�Χ�½� 
 * param max: ��ɾ����Ԫ�صķ�Χ�Ͻ� 
 * note: ������㷨��problem_3���ƣ��˴�����׸�� 
*/ 
int delval(int lis[], int size, int min, int max)
{
	int count=0;
	
	if(min>max)    // ��min>max����ʱ��Χ[min,max]Ϊ�գ��޷�ɾ��Ԫ�أ���ֱ�ӷ��� 
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
