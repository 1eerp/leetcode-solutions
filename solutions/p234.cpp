#include "common.h"

bool isPalindrome(ListNode* head) {
	ListNode* slow = head, *fast = head;
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	
	ListNode* last = nullptr, *cur = slow, *next;
	while(cur)
	{
		next = cur->next;
		cur->next = last;
		last = cur;
		cur = next;
	}

	while(last)
	{
		if(head->val != last->val) return false;
		head = head->next;
		last = last->next;
	}

	return true;
}