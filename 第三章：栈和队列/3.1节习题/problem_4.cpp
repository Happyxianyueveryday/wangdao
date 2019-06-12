/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// ������㷨�ǳ����䣬��Ҫ�ر�ע�� 
// ��������Ľⷨ����ʹ��ջ��������⣬һ����ʹ�õ��㷨���£�
// (1) ʹ�ÿ���˫ָ�뷨����������м��㣬�ڲ��ҹ��������ν���ָ�뾭���Ľ����ջ�����Կ�ָ�뾭���Ľ����м��� 
// (2) ��(1)�еļ������Ϊż���������ָ�뿪ʼ���κ�ջ��Ԫ�رȽϣ�ÿ�Ƚ�һ�Σ��ƶ�ָ�벢��ջջ��Ԫ�أ����������Ϊ��������ӿ�ָ�뿪ʼ���κ�ջ��Ԫ�رȽ� 
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	stack<int> sta;
    	int count=0;
    	ListNode *slow=head;
    	ListNode *fast=head;
    	
    	while(fast&&fast->next)
    	{
    		sta.push(slow->val);
    		
    		slow=slow->next;
    		fast=fast->next->next;
    		count+=2;
		}
		if(fast&&!fast->next)   // ����������ĵ���������㣬����ļ���������Ҫ�ر�ע�� 
			count+=1;
			
		slow=((count%2)?slow->next:slow);
		
		while(slow)
		{
			int temp=sta.top();
			sta.pop();
			
			if(temp!=slow->val)
				return false;
			else
				slow=slow->next;
		}
		
		return true;
    }
};
