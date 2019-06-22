#include <iostream>
#include <string>
#include <stack>

using namespace std;

string trainDispatcher(string input)
{
    string res;
    stack<char> sta;
    
    for(int i=0;i<input.size();i++)
    {
        if(input[i]=='H')
            sta.push(input[i]);
        else
            res.push_back(input[i]);
    }

    while(sta.size())
    {
        res.push_back(sta.top());
        sta.pop();
    }

    return res;
}

int main(void)
{
    string exp="HSHSSSHHHSHSHSSSHSSHS";
    cout<<trainDispatcher(exp)<<endl;
}