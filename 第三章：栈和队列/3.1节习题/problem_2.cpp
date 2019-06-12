#include <iostream>
#include <stack>

using namespace std;

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
	string input, output;
	cin>>input>>output;
	cout<<validStackSeq(input, output)<<endl;
}

