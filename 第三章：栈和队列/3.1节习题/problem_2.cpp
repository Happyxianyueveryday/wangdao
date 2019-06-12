#include <iostream>
#include <stack>

using namespace std;

bool validStackSeq(string input, string output)
{
	int pos=0;
	stack<char> sta;

	for(int i=0;i<output.size();i++)    // Ŀ��ʼ��Ϊ��ջ�г�ջ��������е���һ��Ŀ��Ԫ��
	{
		while(!(sta.size()&&sta.top()==output[i]))   // ������ջֱ��ջ��Ϊ����ջ��Ԫ�ص�����һ��Ŀ���ջ��Ԫ��Ϊֹ
		{
			if(pos==input.size())   // ��ջ�������궼û��ʹ��ջ��Ԫ�غ�Ŀ�����Ԫ����ȣ���ƥ��ʧ�ܷ�������false
				return false;
			else
			{
				sta.push(input[pos]);
				pos+=1;
			}
		}
		sta.pop();    // ��ջջ����Ŀ�����Ԫ�أ�ת������һ��Ԫ��
	}

	return true;      // ������������в��裬��ƥ��ɹ�������true
}

int main(void)
{
	string input, output;
	cin>>input>>output;
	cout<<validStackSeq(input, output)<<endl;
}

