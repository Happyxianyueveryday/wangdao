#include <iostream>
#include <string>

using namespace std;

/*
 * delmin: �Ӹ�����������ɾ��������Сֵ��Ԫ�أ�������СֵΨһ���������ر�ɾ����Ԫ�ص�ֵ����ɾ����Ԫ�ص�λ������������һ��Ԫ�ؽ��������˳���Ϊ�������������Ϣ���˳����� 
 * param lis: ����ĸ������� 
 * param size: �����Ԫ�ظ���/����Ĵ�С 
*/
int delmin(int lis[], int size)
{
	if(!size)
	{
		cout<<"����Ϊ�գ�ɾ����С��Ԫ��ʧ��!"<<endl;
		return 0;
	}
	
	// 1. �Ӹ������������ҵ���Сֵ��λ�ú��±�
	int min=lis[0];
	int pos=0;
	
	for(int i=0;i<size;i++)
	{
		if(lis[i]<=min)
		{
			min=lis[i];
			pos=i;
		}
	}
	
	// 2. ���������һ��Ԫ���������Сֵλ�ã��Ӷ�ɾ�������е���Сֵ
	lis[pos]=lis[size-1];
	
	// 3. ����ɾ������СֵԪ��
	return min; 
}

int main(void)
{	
	int lis[9]={7,4,1,2,5,8,9,6,3};
	
	cout<<"ɾ����������СֵΪ: "<<delmin(lis, 9)<<endl;
	cout<<"ɾ���������lisΪ lis = "<<endl;
	
	for(int i=0;i<8;i++)
	{
		cout<<lis[i]<<" ";
	}
	cout<<endl;
}
