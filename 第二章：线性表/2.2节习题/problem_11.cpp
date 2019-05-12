#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*
 * get_median: ��ȡ�����ȳ��������λ�� 
 * param lis1: �ȳ�����1 
 * param lis2: �ȳ�����2 
 * param size: �����ȳ�����ĳ���
 * note 1: ����ͬ����ʹ�÷��εķ�����ͨ��һ�αȽ��ų�һ���Ԫ������ʱ�临�Ӷ�������O(logn)������Ϊ�ǳ������ϰ�⣬��Ҫ�������� 
 * note 2: ������㷨�Ļ�������Ϊ: ѭ���������²���ֱ��ɾ��������lis1������lis2�о�ֻʣ��һ��Ԫ��Ϊֹ����ʱ����Ԫ���еĽ�Сֵ������λ���� ÿ���ȷֱ�õ�����lis1����λ��lis1[mid]������lis2����λ��lis2[mid]��Ȼ��Ƚ���������λ��: 
 *         (1) ��lis1[mid]<lis2[mid]������ʱ��С��ϵΪ: lis1��벿��<lis1[mid]<...<lis2[mid]<lis2�Ұ벿�֣�˵����λ�������ܴ���������lis1����벿�ֺ�����lis2���Ұ벿�֣����ų���lis1����벿�ֺ�lis2���Ұ벿�� 
 *         (2) ��lis1[mid]>lis2[mid]������ʱ��С��ϵΪ: lis2��벿��<lis2[mid]<...<lis1[mid]<lis1�Ұ벿�֣�˵����λ�������ܴ���������lis1���Ұ벿�ֺ�����lis2����벿�֣����ų���lis1���Ұ벿�ֺ�lis2����벿�� 
 *         (3) ��lis1[mid]=lis2[mid]������ʱ��λ������lis1[mid]��ֱ�ӷ��ؼ��� 
 *         ��ע: ��ÿ���ų������������һ��Ԫ�غ���Ҫ��Ȼ��֤��������Ĵ�Сһ�£����ݶ��壬��λ�����±�Ϊmid=ceil(size/2)-1�����������lis1��lis2�ĳ��Ⱦ�Ϊ�����������������⴦��������lis1������lis2�ĳ��Ⱦ�Ϊż��������Ҫ�����⴦��ɾ����벿��ʱһͬɾ������λ���������±귶Χ0~mid����ɾ���Ұ벿��ʱ��ɾ����λ�������±귶Χmid+1~size-1�� 
*/
int get_median(int lis1[], int lis2[], int size)
{
	// 0. ��ʼ�����в��ҺͱȽϵķ�Χ 
	int begin1=0, end1=size-1;
	int begin2=0, end2=size-1;
	
	// 1. ѭ���������µĲ��裬ֱ����������lis1��lis2�о�ֻʣ��һ��Ԫ��ʱֹͣ 
	while(begin1!=end1||begin2!=end2)
	{
		// 1.1 ������������lis1��lis2�ֱ����λ�����±� 
		int mid1=(begin1+end1)/2;
		int mid2=(begin2+end2)/2;
		
		// 1.2 ��lis1[mid]<lis2[mid]����ɾ��lis1����벿�ֺ�lis2���Ұ벿�֣�ע�Ᵽ֤ɾ������������ĳ������ 
		if(lis1[mid1]<lis2[mid2]) 
		{
			int length=end1-begin1+1;   // ��������lis1��lis2�ĵ�ǰ����
			
			if(length%2)   // ������lis1��lis2�ĳ��Ⱦ�Ϊ��������ɾ������벿������Ϊlis[0:mid-1]���Ұ벿������Ϊlis[mid+1:0] 
			{
				begin1=mid1;
				end2=mid2;
			}
			else
			{
				begin1=mid1+1;
				end2=mid2;
			}
		}
		
		// 1.3 ��lis1[mid]<lis2[mid]����ɾ��lis2����벿�ֺ�lis1���Ұ벿�֣�ע�Ᵽ֤ɾ������������ĳ������ 
		else if(lis1[mid1]>lis2[mid2])
		{
			int length=end1-begin1+1;
			
			if(length%2)
			{
				end1=mid1;
				begin2=mid2;
			}
			else
			{
				end1=mid1;
				begin2=mid2+1;
			}
		}
		
		// 1.4 ��lis1[mid]=lis2[mid]������λ������lis1[mid]��ֱ�ӷ��ؼ��� 
		else
		return lis1[mid1];	
	}
	
	// 2. ��ɾ��������lis1��lis2��ֻʣ��һ��Ԫ��ʱ������ʱ����Ԫ���еĽ�Сֵ���� 
	return ((lis1[begin1]<lis2[begin2])?lis1[begin1]:lis2[begin2]);
}


int main(void)
{
	int lis1[5]={1,3,5,7,9};
	int lis2[5]={2,4,6,8,10};
	cout<<get_median(lis1, lis2, 5)<<endl;  
	
	int lis3[]={1,2,5,6,9,10};
	int lis4[]={1,3,7,9,11,18};
	cout<<get_median(lis3, lis4, 6)<<endl;
	
	int lis5[]={1,2,3};
	int lis6[]={4,5,6};
	cout<<get_median(lis5, lis6, 3)<<endl;
	
}
