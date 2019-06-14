#include <iostream>
#include <string> 
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> permutations(string input);
bool validStackSeq(string input, string output);

/**
 * generateStackSeq: ������ջ�����������еĳ�ջ����
 * param input: �������ջ���� 
 * return: ���п��ܵĳ�ջ���� 
 * note: ����ջ�������ɳ�ջ���е��㷨����ܻ�����������ʾ��
 		 (1) �������������ջ���е�ȫ����
		 (2) �����ж�ȫ�����еĸ��������Ƿ������������ջ˳�򣨲μ�����ͬһ�ڵڶ��⣩ 
	     (3) ������2�е�������ջ���е����м������У���󷵻ؽ�� 
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
 * permutations�����ɸ������е�ȫ����
 * param input: �����ԭʼ���� 
 * return: ����ԭʼ�������п��ܵĳ�ջ���� 
 * note 1: ����ȫ����ͨ��ʹ�ú����С��������������Ϊ��
 	     (1) ͨ�������ҵ��������е���С���У�������������Ϊ'bac'������С����Ϊ'abc' 
		 (2) ����С���п�ʼ��ѭ���ز��Ҵ��ڵ�ǰֵ����һ����Сֵ���������С������ֱ�������������ʱֹͣ��������о�����С���е����򣩣�
		     (a) һ���ң�������ҵ����һ������lis[k]<lis[k+1]������Ԫ��lis[k]������'1243'�е�lis[k]=2 
			 (b) �����ң�������ҵ�λ����lis[k]֮�����lis[k]����Сֵtar������'1243'�е�tar=3 
			 (c) ����������lis[k]��tar��ֵ����������'1243'�н�����õ�'1342' 
			 (d) �ĵ��򣺷�תlis[k]���Ԫ�أ�����'1342'��ת��õ�'1324' 
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
		// (a) һ���� 
		int k=-1;
		for(int i=0;i<input.size()-1;i++)
		{
			if(input[i]<input[i+1])
			{
				k=i;
			}
		}
	
		// (b) ������ 
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
		
		// (c) ������
		char temp=input[tarpos]; 
		input[tarpos]=input[k];
		input[k]=temp;
		
		// (d) �ķ�ת
		reverse(input.begin()+k+1, input.end());
		
		res.push_back(input);
	}
	
	return res;
}

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
	vector<string> res=generateStackSeq("ABCDE");
	
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
}
