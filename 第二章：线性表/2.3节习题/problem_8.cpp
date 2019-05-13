/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// 本题是一道leetcode原题，原题地址见: https://leetcode-cn.com/problems/intersection-of-two-linked-lists/ 
 
// 查找相交链表的第一个相交结点的算法是: 初始化两个游标指针now1和now2，now1指向第一个链表的首结点headA，now2指向第二个链表的首结点headB，然后每次同时移动两个指针一步（移动时若第一次遇到now1->next为空，则移动now1到headB，即now1=headA，now2同理），循环进行上述步骤直到now1或者now2为空或者now1==now2时为止，若因为now1==NULL或者now2==NULL停止则不存在交点，若因为now1==now2停止则存在交点，交点就是now1或者now2 
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) { 
    	
    	ListNode *now1=headA;   // 游标指针now1 
    	ListNode *now2=headB;   // 游标指针now2 
    	
        int flag1=0;    // 标记指针now1是否为第一次遇到NULL结点 
        int flag2=0;    // 标记指针now2是否为第一次遇到NULL结点
		
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
