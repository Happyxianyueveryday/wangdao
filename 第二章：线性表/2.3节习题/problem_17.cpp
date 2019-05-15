/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// 本题是链表专题下的经典习题，leetcode链接见: https://leetcode-cn.com/problems/palindrome-linked-list/

// A. 下面先给出一个时间复杂度O(n)，空间复杂度O(n)的最简写法，使用栈进行实现，快速而简洁有力
// 算法步骤描述: 创建一个栈，使用类似于查找链表中间结点的双指针法: 
//               (1) 创建快指针fast和慢指针slow
//               (2) 循环进行以下步骤直到快指针fast指向NULL: 将慢指针slow指向的结点值入栈，然后快指针fast向前移动两步，慢指针slow向前移一步，并再循环中同时统计 整个链表的结点个数
//               (3) 若结点个数为奇数，则初始化新的指针test=slow->next，若结点个数为偶数，则初始化新指针test=slow 
//               (4) 循环进行以下步骤直到指针test为空: 将指针test的值和栈顶元素比较，若相等则继续进行循环，若不相等，则直接返回false表示链表不是回文链表
//               (5) 上述所有步骤执行完毕后，若栈为空则返回true，若栈非空则返回false 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	// 0. 处理空链表和单元素链表的特殊情况
		if(!head||!head->next) 
		return true;
    	
        // 1. 首先，查找中间结点，将中间结点之前的结点值（包括中间结点自身）入栈，并同时计算链表中的结点个数是奇数还是偶数 
        ListNode *fast=head;
        ListNode *slow=head;
        
        stack<int> sta;
        
        while(fast&&fast->next)
        {
        	sta.push(slow->val);   // 注意，这样的写法中最后slow到达的中间结点并未入栈 
        	
        	slow=slow->next;
        	fast=fast->next->next;
		}
		
		bool isodd;
		
		if(!fast)    // 若由于fast==NULL而退出循环，则结点个数为偶数 
		isodd=false;
		else         // 若由于fast->next==NULL而退出循环，则结点个数为奇数 
		isodd=true; 
		
		// 2. 初始化新的游标指针test
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



// B. 方法2: 反转后半部分链表，然后从头结点和中间结点开始比较 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	// 0. 处理特殊情况  
    	if(!head||!head->next)
    	return true;
    	
    	// 1. 快慢指针法查找中间结点
    	ListNode *fast=head, *slow=head, *slowprev=NULL;
		while(fast&&fast->next)
		{
			slowprev=slow;
			slow=slow->next;
			fast=fast->next->next;
		}
		
		// 2. 反转从slow开始的后续链表部分
		if(slow&&slow->next)  // 仅有从slow开始存在两个结点以上才需要进行反转 
		{
			ListNode *now=slow->next, *nowprev=slow;
			
			while(now)
			{
				nowprev->next=now->next;
				now->next=slowprev->next;
				slowprev->next=now;
				
				now=nowprev->next;
			}
		}
		
		// 3. 从链表头结点和中间结点开始进行比较
		ListNode *pos1=head, *pos2=slowprev->next;  //指针slow已经改变，需要注意 
		
		while(pos2&&pos1!=slowprev->next)
		{
			if(pos1->val!=pos2->val)
			return false;
			else
			{
				pos1=pos1->next;
				pos2=pos2->next;
			}
		}
		
		return true;
    }
}; 
