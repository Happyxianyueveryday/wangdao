/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// ����ʵ���Ϻ�leetcode�ĺϲ�����һ�����ƣ�ԭ���ַ��: https://leetcode-cn.com/problems/merge-two-sorted-lists/

// ��������������ϲ�Ϊһ����������ķ����͹鲢�����еĹ鲢������ʵ������һ���ģ����������ȥ���㷨������ 
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { 
    	
    	ListNode *res=new ListNode(0);
    	
        ListNode *now1=l1;
        ListNode *now2=l2;
        ListNode *resnow=res;
        
        while(now1&&now2)
        {
        	if(now1->val<=now2->val)
        	{
				resnow->next=now1;
				now1=now1->next;
			}
			else
			{
				resnow->next=now2;
				now2=now2->next;
			}
			
			resnow=resnow->next;
		}
		
		while(now1)
		{
			resnow->next=now1;
			now1=now1->next;
			resnow=resnow->next;
		}
		
		while(now2)
		{
			resnow->next=now2;
			now2=now2->next;
			resnow=resnow->next;
		}
		
		ListNode *temp=res;
		res=res->next;
		delete temp;
		
		return res;
    }
};
