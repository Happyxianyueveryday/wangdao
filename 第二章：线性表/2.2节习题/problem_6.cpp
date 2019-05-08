#include <iostream> 
#include <string>
#include <set>

using namespace std;

/*
 * deldump: ɾ��һ���������������е��ظ�Ԫ�أ�������ɾ��Ԫ�ص����� 
 * param lis: ԭʼ��������
 * param size: ����Ԫ�صĸ���/���鳤�� 
 * note 1: ���㷨�ı��ʻ���Ҫ��������ɾ��Ԫ�أ�����䱾���㷨��problem_3, problem_4, problem_5���ƣ�����ʹ��һ����������count����¼��ǰ�Ѿ����ֵ�Ҫɾ����Ԫ�أ�������һ������ɾ����Ԫ��ʱ������Ԫ��ǰ��countλ
 * note 2: ���㷨��ǰ�������Ҫ�������ڣ���ΪҪɾ����Ԫ���ǳ����ظ���Ԫ�أ������Ҫʹ��һ������set����������һ��Ԫ��֮ǰ���������жϼ������Ƿ���ڸ�Ԫ�أ������ڣ�����Ҫɾ�������Ӽ�������count���������ڣ�������ɾ��������Ԫ��ǰ��countλ���ɣ���󣬽���ǰԪ�ؼ��뼯�� 
*/
int deldump(int lis[], int size)
{
	if(!size)      // ������Ϊ�գ���ֱ�ӽ��з���
	return 0;
	
	set<int> dic;  
	int count=0;   // ��ǰ��ɾ����Ԫ������ 
	
	for(int i=0;i<size;i++)
	{
		if(dic.count(lis[i]))  // ����Ԫ��֮ǰ���ֹ���������ɾ��Ԫ�صļ�����count 
		count+=1;
		else                   // ��֮ǰû���ֹ�����ǰ��countλ 
		lis[i-count]=lis[i];
		
		// ��󽫵�ǰԪ�ؼ��뼯����
		dic.insert(lis[i]);
	}
	
	return count;
}

int main(void)
{
	int lis[]={1,1,2,2,2,3,3,4,4,5,5,6,7,8,9,9,11,12,12,15};
	int size=20;
	
	int count=deldump(lis, size);
	
	for(int i=0;i<size-count;i++)
	{
		cout<<lis[i]<<" ";
	}
}
