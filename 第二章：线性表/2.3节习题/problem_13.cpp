/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// 本题实际上和leetcode的合并链表一题类似，原题地址在: https://leetcode-cn.com/problems/merge-two-sorted-lists/

// 将两个递增链表合并为一个递增链表的方法和归并排序中的归并过程在实质上是一样的，因此这里略去对算法的描述 
 
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
