/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // 本题实际上和leetcode的题目重合，leetcode原题请参见: https://leetcode-cn.com/problems/odd-even-linked-list/
 // 刻在DNA里的题目，算法已无需多言
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
    	 
        ListNode *odd=new ListNode(0);     // 奇数结点链表 
        ListNode *even=new ListNode(0);    // 偶数结点链表 
        
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
