/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// ������һ��leetcodeԭ�⣬ԭ���ַ��: https://leetcode-cn.com/problems/intersection-of-two-linked-lists/ 
 
// �����ཻ����ĵ�һ���ཻ�����㷨��: ��ʼ�������α�ָ��now1��now2��now1ָ���һ��������׽��headA��now2ָ��ڶ���������׽��headB��Ȼ��ÿ��ͬʱ�ƶ�����ָ��һ�����ƶ�ʱ����һ������now1->nextΪ�գ����ƶ�now1��headB����now1=headA��now2ͬ����ѭ��������������ֱ��now1����now2Ϊ�ջ���now1==now2ʱΪֹ������Ϊnow1==NULL����now2==NULLֹͣ�򲻴��ڽ��㣬����Ϊnow1==now2ֹͣ����ڽ��㣬�������now1����now2 
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) { 
    	
    	ListNode *now1=headA;   // �α�ָ��now1 
    	ListNode *now2=headB;   // �α�ָ��now2 
    	
        int flag1=0;    // ���ָ��now1�Ƿ�Ϊ��һ������NULL��� 
        int flag2=0;    // ���ָ��now2�Ƿ�Ϊ��һ������NULL���
		
		while(1) 
		{
			if(now1==now2)
			break;
			else if(now1==NULL||now2==NULL)
			break;
			else
			{
				now1=now1->next;
				now2=now2->next;
				
				if(now1==NULL&&flag1==0)
				{
					now1=headB;
					flag1=1;
				}
				if(now2==NULL&&flag2==0)
				{
					now2=headA;
					flag2=1;
				}
			}
		}
		
		if(now1==now2) 
		return now1;
		else
		return NULL;
    }
}; 
