#include <iostream> 
#include <string>
#include <set>

using namespace std;

/*
 * deldump: 删除一个有序数组中所有的重复元素，返回已删除元素的数量 
 * param lis: 原始输入数组
 * param size: 数组元素的个数/数组长度 
 * note 1: 该算法的本质还是要从数组中删除元素，因此其本质算法和problem_3, problem_4, problem_5类似，都是使用一个计数变量count来记录当前已经发现的要删除的元素，当遇到一个无需删除的元素时，将该元素前移count位
 * note 2: 该算法和前几题的主要区别在于，因为要删除的元素是出现重复的元素，因此需要使用一个集合set，遍历访问一个元素之前，首先先判断集合中是否存在该元素，若存在，则需要删除，增加计数变量count，若不存在，则无需删除，将该元素前移count位即可，最后，将当前元素加入集合 
*/
int deldump(int lis[], int size)
{
	if(!size)      // 若数组为空，则直接进行返回
	return 0;
	
	set<int> dic;  
	int count=0;   // 当前待删除的元素数量 
	
	for(int i=0;i<size;i++)
	{
		if(dic.count(lis[i]))  // 若该元素之前出现过，则增加删除元素的计数器count 
		count+=1;
		else                   // 若之前没出现过，则前移count位 
		lis[i-count]=lis[i];
		
		// 最后将当前元素加入集合中
		dic.insert(lis[i]);
	}
	
	return count;
}

int main(void)
{
	int lis[]={1,1,2,2,2,3,3,4,4,5,5,6,7,8,9,9,11,12,12,15};
	int size=20;
	
	int count=deldump(lis, size);
	
	for(int i=0;i<size-count;i++)
	{
		cout<<lis[i]<<" ";
	}
}
