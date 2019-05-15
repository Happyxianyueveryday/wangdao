/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// 本题是leetcode原题，原题链接在: https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/ 

// 查找链表中倒数第k个结点主要需要使用的方法是双指针法，具体算法步骤如下: 
// (1) 建立快慢双指针fast和slow，初始化fast和slow指向链表的首结点head
// (2) 将快指针fast向前移动k步 
// (3) 循环执行下述步骤直到快指针fast指向NULL为止: 将fast和slow均同时前移一步 
// (4) 上述步骤结束后，慢指针slow就指向链表的倒数第k个结点 
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	
        // 1. 初始化快慢指针fast和slow，以及慢指针slow的前驱结点slowprev 
		ListNode *fast=head, *slow=head, *slowprev=NULL;
		
		
		// 2. 将快指针向前移动k步
		for(int i=0;i<n;i++) 
		{
			fast=fast->next;
		}
		
		// 3. 同时移动快慢指针，直到快指针到达空结点为止
		while(fast) 
		{
			slowprev=slow;
			slow=slow->next;
			fast=fast->next;
		}
		
		// 4. 这时slow就指向链表的倒数第k个结点，删除该结点即可，注意特殊处理要删除的结点是第一个结点的情况
		if(!slowprev)    // 要删除的结点是第一个结点
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
