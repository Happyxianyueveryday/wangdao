#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isVaildExp(string exp)
{
    stack<char> sta;

    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]=='{'||exp[i]=='['||exp[i]=='(')
            sta.push(exp[i]);
        else if(exp[i]=='}'||exp[i]==']'||exp[i]==')')
        {
            char temp=sta.top();
            sta.pop();

            if(exp[i]=='}'&&temp!='{'||exp[i]==']'&&temp!='['||exp[i]==')'&&temp!='(')
                return false;
        }
    }

    return true;
}


int main(void)
{
    string exp="{}[][]({[]}({}))";
    string exp2="{}[][]({[])({}))";

    cout<<isVaildExp(exp)<<endl;
    cout<<isVaildExp(exp2)<<endl;
}
