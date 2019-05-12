#include <iostream> 
#include <string>
#include <map>

using namespace std;

/*
 * main_element: 查找数组的主元素，若一个大小为size的数组中，某个元素出现次数大于size/2，则称该元素为数组的主元素 
 * lis: 原始输入数组 
 * size: 输入数组的大小 
 * note: 很基础的问题，使用哈希表(map)记录每个元素的出现次数即可 
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
