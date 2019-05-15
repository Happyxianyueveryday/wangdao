/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// ����������ר���µľ���ϰ�⣬leetcode���Ӽ�: https://leetcode-cn.com/problems/palindrome-linked-list/

// A. �����ȸ���һ��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)�����д����ʹ��ջ����ʵ�֣����ٶ��������
// �㷨��������: ����һ��ջ��ʹ�������ڲ��������м����˫ָ�뷨: 
//               (1) ������ָ��fast����ָ��slow
//               (2) ѭ���������²���ֱ����ָ��fastָ��NULL: ����ָ��slowָ��Ľ��ֵ��ջ��Ȼ���ָ��fast��ǰ�ƶ���������ָ��slow��ǰ��һ��������ѭ����ͬʱͳ�� ��������Ľ�����
//               (3) ��������Ϊ���������ʼ���µ�ָ��test=slow->next����������Ϊż�������ʼ����ָ��test=slow 
//               (4) ѭ���������²���ֱ��ָ��testΪ��: ��ָ��test��ֵ��ջ��Ԫ�رȽϣ���������������ѭ����������ȣ���ֱ�ӷ���false��ʾ�����ǻ�������
//               (5) �������в���ִ����Ϻ���ջΪ���򷵻�true����ջ�ǿ��򷵻�false 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	// 0. ���������͵�Ԫ��������������
		if(!head||!head->next) 
		return true;
    	
        // 1. ���ȣ������м��㣬���м���֮ǰ�Ľ��ֵ�������м���������ջ����ͬʱ���������еĽ���������������ż�� 
        ListNode *fast=head;
        ListNode *slow=head;
        
        stack<int> sta;
        
        while(fast&&fast->next)
        {
        	sta.push(slow->val);   // ע�⣬������д�������slow������м��㲢δ��ջ 
        	
        	slow=slow->next;
        	fast=fast->next->next;
		}
		
		bool isodd;
		
		if(!fast)    // ������fast==NULL���˳�ѭ�����������Ϊż�� 
		isodd=false;
		else         // ������fast->next==NULL���˳�ѭ�����������Ϊ���� 
		isodd=true; 
		
		// 2. ��ʼ���µ��α�ָ��test
		ListNode *test=(isodd)?slow->next:slow;
		
		
		while(test&&sta.size())
		{
			if(sta.top()!=test->val)
			return false;
			else
			{
				sta.pop();
				test=test->next;
			}
		}
		
		if(sta.size())
		return false;
		else   
		return true;
    }
};
