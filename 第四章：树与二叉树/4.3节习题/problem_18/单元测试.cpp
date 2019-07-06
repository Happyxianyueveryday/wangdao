#include <iostream>
#include <vector>
#include "ThreadedTrees.h"

using namespace std;  

void print(string info, const vector<int> &lis)
{
	cout<<info;
	for(int i=0;i<lis.size();i++)
	{
		cout<<lis[i]<<" "; 
	}
	cout<<endl;
}

int main(void)
{
	// 0. ��ʼ���������õ��� 
	vector<int> preorder={12,5,2,9,18,15,17,16,19};
	vector<int> inorder={2,5,9,12,15,16,17,18,19};
	Tree tree2(inorder,preorder);    // �����������ǰ������Ĺ��캯�� 
	cout<<"tree2 = "<<endl;
	print("tree2 ǰ����� = ", tree2.preorder());
	print("tree2 ������� = ", tree2.inorder());  
	print("tree2 ������� = ", tree2.postorder());
	print("tree2 ��α��� = ", tree2.levelorder()); 
	 
	cout<<"--------------------------------------------"<<endl;
	
	ThreadTree threadtree2(tree2);
	
	print("������tree2 ���������� = ", threadtree2.postorder());
} 
