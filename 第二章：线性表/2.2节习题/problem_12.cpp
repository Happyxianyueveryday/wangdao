#include <iostream> 
#include <string>
#include <map>

using namespace std;

/*
 * main_element: �����������Ԫ�أ���һ����СΪsize�������У�ĳ��Ԫ�س��ִ�������size/2����Ƹ�Ԫ��Ϊ�������Ԫ�� 
 * lis: ԭʼ�������� 
 * size: ��������Ĵ�С 
 * note: �ܻ��������⣬ʹ�ù�ϣ��(map)��¼ÿ��Ԫ�صĳ��ִ������� 
*/
int main_element(int lis[], int size) 
{
	map<int,int> dic;
	
	for(int i=0;i<size;i++)
	{
		if(dic.count(lis[i]))
		dic[lis[i]]+=1;
		else
		dic[lis[i]]=1;
	}
	
	for(auto a=dic.begin();a!=dic.end();a++)
	{
		if(a->second>size/2)
		return a->first;
	}
	
	return -1;
}

int main(void) 
{
	int lis[]={0,5,5,3,5,7,5,5};
	int lis1[]={0,5,5,3,5,1,5,7};
	
	cout<<main_element(lis, 8)<<endl;
	cout<<main_element(lis1, 8)<<endl;
}
