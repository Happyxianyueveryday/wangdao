#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

// 'C'代表客车，'V'代表货车

class BayDispatcher
{
    public:
    BayDispatcher();
    void book(char car);       // 登记一个新的需要渡江的车
    string getarr();           // 获取此次过江渡船所需要搭载的十辆车

    private:
    queue<char> vque;          // 正在等待的货车序列
    queue<char> cque;          // 正在等待的客车序列
};

BayDispatcher::BayDispatcher()
{
}

void BayDispatcher::book(char car)
{
    if(car=='C')
        cque.push(car);
    else
        vque.push(car);
}

string BayDispatcher::getarr()
{
    string res;

    for(int i=0;i<2;i++)    // 4辆客车一辆货车，两次循环就是一组10辆
    {
        for(int k=0;k<4;k++)
        {
            if(cque.size())
            {
                res.push_back(cque.front());
                cque.pop();
            }
            else if(vque.size())
            {
                res.push_back(vque.front());
                vque.pop();
            }
        }

        if(vque.size())
        {
            res.push_back(vque.front());
            vque.pop();
        }
        else if(cque.size())
        {
            res.push_back(cque.front());
            cque.pop();
        }
    }

    return res;
}

int main(void)
{
    BayDispatcher bay;
    
    bay.book('V');
    bay.book('V');
    bay.book('C');
    bay.book('C');
    bay.book('C');
    bay.book('C');
    bay.book('V');
    bay.book('C');
    bay.book('C');
    bay.book('V');
    bay.book('V');
    bay.book('C');
    bay.book('C');
    bay.book('C');
    bay.book('V');
    bay.book('V');
    bay.book('C');
    bay.book('V');
    bay.book('C');
    bay.book('V');
    bay.book('V');
    bay.book('C');
    bay.book('C');
    bay.book('C');
    bay.book('C');
    bay.book('C');
    bay.book('C');
    bay.book('C');
    bay.book('C');
    bay.book('V');
	bay.book('C');
	bay.book('C');
	bay.book('C');
	bay.book('C');
	bay.book('C');
	bay.book('C');
	bay.book('C'); 
	bay.book('V');
	bay.book('V');
	bay.book('V');

    cout<<bay.getarr()<<endl;
    cout<<bay.getarr()<<endl;
    cout<<bay.getarr()<<endl;
    cout<<bay.getarr()<<endl;
    cout<<bay.getarr()<<endl;
    cout<<bay.getarr()<<endl;
    cout<<bay.getarr()<<endl;
}
