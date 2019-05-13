/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // ����ʵ���Ϻ�leetcode����Ŀ�غϣ�leetcodeԭ����μ�: https://leetcode-cn.com/problems/odd-even-linked-list/
 // ����DNA�����Ŀ���㷨���������
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
    	 
        ListNode *odd=new ListNode(0);     // ����������� 
        ListNode *even=new ListNode(0);    // ż��������� 
        
        ListNode *now=head;
        ListNode *oddnow=odd;
        ListNode *evennow=even;
        
        int count=1;
        
        while(now)
        {
        	if(count%2)
        	{
        		oddnow->next=new ListNode(now->val);
        		oddnow=oddnow->next;
			}
			else
			{
				evennow->next=new ListNode(now->val);
				evennow=evennow->next;
			}
			now=now->next;
			count+=1;
		}
		
		oddnow->next=even->next; 
		
		return odd->next;
    }
};
