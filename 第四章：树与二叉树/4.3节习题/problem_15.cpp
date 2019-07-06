#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ������ʹ�õ��㷨��Ϊ�򵥣���Ϊ�������������ڿս�㣬��˱�������ʹ�õ��㷨���Լ���Ϊ���µĲ��裺
// (1) �������ǰ���������ֻ��һ��Ԫ�ػ���Ϊ�գ���Ϊ����������߿�������ʱ�����������ǰ���������ֱ�ӷ��������ǰ��������� 
// (2) ���򣬴�ǰ�����������ɾ����Ԫ�أ�ɾ������Ԫ�ؾ��ǵ�ǰ�ĸ�����ֵ 
// (3) ��ʣ�µ�ǰ��������зָ�ΪԪ��������ȵ����Σ�ǰ�벿�־�����������ǰ��������У���벿�־�����������ǰ��������� 
// (4) ����������ǰ��������еݹ�������������ĺ������������������ǰ��������еݹ�������������ĺ������ 
// (5) �������ν������õ����������ĺ���������������ĺ��������������ֵƴ���������͵õ����յ�ǰ���ĺ���������� 
        
vector<int> getPostFromPre(vector<int> pre) 
{
    // 0. ��ǰ������н���һ��Ԫ�ػ��߿գ���Ϊ����������߿�����ֱ�ӷ��������ǰ��������м���
    if(pre.size()==1||pre.size()==0)
    return pre;
    else
    {
        vector<int> leftpre, rightpre;  // ����������������ǰ���������

        int rootval=pre[0];             // ��������ǰ������еĵ�һ�����
        pre.erase(pre.begin());         // ɾ�������
        
        // 1. ��������������������ǰ���������
        for(int i=0;i<pre.size();i++)
        {
            if(i<pre.size()/2)          // ɾ��ǰ������еĸ�����ǰ�벿�־�����������ǰ�����
            leftpre.push_back(pre[i]);
            else                        // ɾ��ǰ������еĸ����󣬺�벿�־�����������ǰ�����
            rightpre.push_back(pre[i]);
        }

        // 2. �ݹ��������������ĺ����������
        vector<int> leftpost=getPostFromPre(leftpre);
        vector<int> rightpost=getPostFromPre(rightpre);

        // 3. ���ν��������ĺ���������У��������ĺ��������������ֵ����������͵õ���ǰ�����ĺ����������
        vector<int> res;

        for(int i=0;i<leftpost.size();i++)
        {
            res.push_back(leftpost[i]);
        }

        for(int i=0;i<rightpost.size();i++)
        {
            res.push_back(rightpost[i]);
    	}
        res.push_back(rootval);

        return res;
    }
}

int main(void)
{
    vector<int> pre={1,2,4,5,3,6,7};
    vector<int> post=getPostFromPre(pre);

    for(int i=0;i<post.size();i++)
    {
        cout<<post[i]<<" ";
    }
    cout<<endl;
}

