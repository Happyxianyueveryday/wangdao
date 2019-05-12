#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*
 * get_median: 获取两个等长数组的中位数 
 * param lis1: 等长数组1 
 * param lis2: 等长数组2 
 * param size: 两个等长数组的长度
 * note 1: 本题同样是使用分治的方法，通过一次比较排除一半的元素来将时间复杂度限制在O(logn)，本题为非常经典的习题，需要熟练掌握 
 * note 2: 本题的算法的基本步骤为: 循环进行以下步骤直到删除到数组lis1和数组lis2中均只剩下一个元素为止，这时两个元素中的较小值就是中位数： 每次先分别得到数组lis1的中位数lis1[mid]和数组lis2的中位数lis2[mid]，然后比较这两个中位数: 
 *         (1) 若lis1[mid]<lis2[mid]，则这时大小关系为: lis1左半部分<lis1[mid]<...<lis2[mid]<lis2右半部分，说明中位数不可能存在于数组lis1的左半部分和数组lis2的右半部分，故排除掉lis1的左半部分和lis2的右半部分 
 *         (2) 若lis1[mid]>lis2[mid]，则这时大小关系为: lis2左半部分<lis2[mid]<...<lis1[mid]<lis1右半部分，说明中位数不可能存在于数组lis1的右半部分和数组lis2的左半部分，故排除掉lis1的右半部分和lis2的左半部分 
 *         (3) 若lis1[mid]=lis2[mid]，则这时中位数就是lis1[mid]，直接返回即可 
 *         附注: 在每次排除掉两个数组的一半元素后，需要仍然保证两个数组的大小一致，根据定义，中位数的下标为mid=ceil(size/2)-1，因此若数组lis1和lis2的长度均为奇数，则无需做特殊处理，若数组lis1和数组lis2的长度均为偶数，则需要做特殊处理，删除左半部分时一同删除掉中位数本身（即下标范围0~mid），删除右半部分时不删除中位数（即下标范围mid+1~size-1） 
*/
int get_median(int lis1[], int lis2[], int size)
{
	// 0. 初始化进行查找和比较的范围 
	int begin1=0, end1=size-1;
	int begin2=0, end2=size-1;
	
	// 1. 循环进行如下的步骤，直到两个数组lis1和lis2中均只剩下一个元素时停止 
	while(begin1!=end1||begin2!=end2)
	{
		// 1.1 计算两个数组lis1和lis2分别的中位数的下标 
		int mid1=(begin1+end1)/2;
		int mid2=(begin2+end2)/2;
		
		// 1.2 若lis1[mid]<lis2[mid]，则删除lis1的左半部分和lis2的右半部分，注意保证删除后两个数组的长度相等 
		if(lis1[mid1]<lis2[mid2]) 
		{
			int length=end1-begin1+1;   // 计算数组lis1和lis2的当前长度
			
			if(length%2)   // 若数组lis1和lis2的长度均为奇数，则删除的左半部分区间为lis[0:mid-1]，右半部分区间为lis[mid+1:0] 
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
		
		// 1.3 若lis1[mid]<lis2[mid]，则删除lis2的左半部分和lis1的右半部分，注意保证删除后两个数组的长度相等 
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
		
		// 1.4 若lis1[mid]=lis2[mid]，则中位数就是lis1[mid]，直接返回即可 
		else
		return lis1[mid1];	
	}
	
	// 2. 若删除到数组lis1和lis2均只剩下一个元素时，则这时两个元素中的较小值就是 
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
