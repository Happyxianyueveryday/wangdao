#include <iostream>
#include <string>
#include <stack>

using namespace std;

double calByStack(double x, int n)
{
    stack<double> sta;
    sta.push(1.0);
    sta.push(2*x);

    for(int k=2;k<=n;k++)
    {
        int kseq1=sta.top();
        sta.pop();
        int kseq2=sta.top();
        sta.pop();

        int kseq0=2*x*kseq1-2*(k-1)*kseq2;

        sta.push(kseq1);
        sta.push(kseq0);
    }

    return sta.top();
}

int main(void)
{
    cout<<calByStack(1.5, 2)<<endl;
    cout<<calByStack(1.5, 3)<<endl;
}
