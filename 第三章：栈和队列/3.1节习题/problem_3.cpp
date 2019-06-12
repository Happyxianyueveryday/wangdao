#include <iostream>
#include <string> 
#include <stack>

using namespace std;

bool isValidOperaSeq(string seq)
{
	stack<char> sta;
	
	for(int i=0;i<seq.size();i++)
	{
		if(seq[i]=='I')
			sta.push(seq[i]);
		else
		{
			if(sta.size())
				sta.pop();
			else
				return false;
		}
	}
	
	if(sta.size())
		return false;
	else
		return true;
}

int main(void)
{
	string seq;
	cin>>seq;
	cout<<isValidOperaSeq(seq)<<endl;
}
