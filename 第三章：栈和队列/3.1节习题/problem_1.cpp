#include <iostream>
#include <string> 
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> permutations(string input);
bool validStackSeq(string input, string output);

/**
 * generateStackSeq: 根据入栈序列生成所有的出栈序列
 * param input: 输入的入栈序列 
 * return: 所有可能的出栈序列 
 * note: 从入栈序列生成出栈序列的算法步骤很基础，如下所示：
 		 (1) 生成所输入的入栈序列的全排列
		 (2) 依次判断全排列中的各个序列是否满足给定的入栈顺序（参见王道同一节第二题） 
	     (3) 将步骤2中的满足入栈序列的序列加入结果中，最后返回结果 
*/
vector<string> generateStackSeq(string input)
{
	vector<string> lis=permutations(input);
	vector<string> res;
	
	for(int i=0;i<lis.size();i++)
	{
		if(validStackSeq(input,lis[i]))
			res.push_back(lis[i]);
	}
	
	return res;
}

/**
 * permutations：生成给定序列的全排列
 * param input: 输入的原始序列 
 * return: 输入原始序列所有可能的出栈序列 
 * note 1: 生成全排列通常使用后继最小数法，基本步骤为：
 	     (1) 通过排序找到输入序列的最小排列，例如输入序列为'bac'，则最小排列为'abc' 
		 (2) 从最小排列开始，循环地查找大于当前值的下一个最小值（即后继最小数），直到遇到最大排列时停止（最大排列就是最小排列的逆序）：
		     (a) 一查找：正序查找到最后一对满足lis[k]<lis[k+1]的序列元素lis[k]，例如'1243'中的lis[k]=2 
			 (b) 二查找：倒序查找到位置在lis[k]之后大于lis[k]的最小值tar，例如'1243'中的tar=3 
			 (c) 三交换：将lis[k]和tar的值交换，例如'1243'中交换后得到'1342' 
			 (d) 四倒序：反转lis[k]后的元素，例如'1342'反转后得到'1324' 
*/
vector<string> permutations(string input)
{
	vector<string> res;
	sort(input.begin(), input.end());
	res.push_back(input);
	
	string end=input;
	reverse(end.begin(),end.end());
	
	while(input!=end)
	{
		// (a) 一查找 
		int k=-1;
		for(int i=0;i<input.size()-1;i++)
		{
			if(input[i]<input[i+1])
			{
				k=i;
			}
		}
	
		// (b) 二查找 
		int tarpos=-1;
		int tar=INT_MAX;
		for(int i=input.size()-1;i>k;i--)
		{
			if(input[i]>input[k]&&input[i]<=tar)
			{
				tar=input[i];
				tarpos=i;
			}
		}
		
		// (c) 三交换
		char temp=input[tarpos]; 
		input[tarpos]=input[k];
		input[k]=temp;
		
		// (d) 四反转
		reverse(input.begin()+k+1, input.end());
		
		res.push_back(input);
	}
	
	return res;
}

bool validStackSeq(string input, string output)
{
	int pos=0;
	stack<char> sta;

	for(int i=0;i<output.size();i++)    // 目标始终为从栈中出栈输出序列中的下一个目标元素
	{
		while(!(sta.size()&&sta.top()==output[i]))   // 进行入栈直到栈不为空且栈顶元素等于下一个目标出栈的元素为止
		{
			if(pos==input.size())   // 入栈序列用完都没有使得栈顶元素和目标输出元素相等，则匹配失败法，返回false
				return false;
			else
			{
				sta.push(input[pos]);
				pos+=1;
			}
		}
		sta.pop();    // 出栈栈顶的目标输出元素，转向处理下一个元素
	}

	return true;      // 若完成上述所有步骤，则匹配成功，返回true
}

int main(void)
{
	vector<string> res=generateStackSeq("ABCDE");
	
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
}
