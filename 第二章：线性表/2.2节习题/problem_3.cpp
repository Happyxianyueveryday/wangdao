#include <iostream>
#include <string>

using namespace std;

/*
 * delval: ��������ɾ��ָ��ֵ������Ԫ�أ�����ɾ��Ԫ�ص����� 
 * param lis: ԭʼ��������
 * param size: ԭʼ��������Ĵ�С/Ԫ������
 * param val: ��ɾ����Ԫ��ֵ 
 * note: ��������ɾ�������ֵ�ķ�����Ϊֱ�ۺͼ򵥣�ʹ��һ������count����¼��ǰ�Ѿ���������Ҫɾ����Ԫ�صĸ�����Ȼ��ʹ��ѭ��������������: ����ǰԪ�غʹ�ɾ����ֵ����ȶ�����ɾ��ʱ��ֱ�ӽ�������countλ������ǰԪ�ص��ڴ�ɾ����ֵ���Ҫɾ��ʱ��ֱ�ӽ�������count��1 
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
