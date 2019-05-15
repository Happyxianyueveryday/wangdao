/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// ������leetcodeԭ�⣬ԭ��������: https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/ 

// ���������е�����k�������Ҫ��Ҫʹ�õķ�����˫ָ�뷨�������㷨��������: 
// (1) ��������˫ָ��fast��slow����ʼ��fast��slowָ��������׽��head
// (2) ����ָ��fast��ǰ�ƶ�k�� 
// (3) ѭ��ִ����������ֱ����ָ��fastָ��NULLΪֹ: ��fast��slow��ͬʱǰ��һ�� 
// (4) ���������������ָ��slow��ָ������ĵ�����k����� 
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	
        // 1. ��ʼ������ָ��fast��slow���Լ���ָ��slow��ǰ�����slowprev 
		ListNode *fast=head, *slow=head, *slowprev=NULL;
		
		
		// 2. ����ָ����ǰ�ƶ�k��
		for(int i=0;i<n;i++) 
		{
			fast=fast->next;
		}
		
		// 3. ͬʱ�ƶ�����ָ�룬ֱ����ָ�뵽��ս��Ϊֹ
		while(fast) 
		{
			slowprev=slow;
			slow=slow->next;
			fast=fast->next;
		}
		
		// 4. ��ʱslow��ָ������ĵ�����k����㣬ɾ���ý�㼴�ɣ�ע�����⴦��Ҫɾ���Ľ���ǵ�һ���������
		if(!slowprev)    // Ҫɾ���Ľ���ǵ�һ�����
		{
			head=head->next;
			delete slow;
		} 
		else 
		{
			slowprev->next=slow->next; 
			delete slow; 
		}
		
		return head;
    }
};  
