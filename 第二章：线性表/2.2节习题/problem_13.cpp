#include <iostream> 
#include <string>
#include <cstring>

using namespace std;

/*
 * get_min_disappear: 
 * param lis: ԭʼ�������� 
 * param size: ��������Ĵ�С 
 * note: ��������Žⷨ���Ǵ���һ����СΪsize�ı������dic���ֱ����ڼ�¼������1~size�Ƿ���ֹ�����Ϊ��СΪsize���������Сδ���������ض���1��n֮�䣨��һ������ʮ����Ҫ�������ȱ����������飬����ǰԪ�ص�ֵ�ڷ�Χ1~n�����ڱ������dic�Ķ�Ӧλ�ý��б�ǣ����������󣬴�dic���ҳ�δ����ǵ���СԪ�ؼ��� 
 * note: ����Ҳ����ʹ���ȿ��������ڽ��в��ҵķ�������ʱ�临�Ӷ�ΪO(nlogn) 
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
