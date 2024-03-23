#include "common.h"

void reorderList(ListNode* head) {
	ListNode* slow = head, *fast = head, *secondLast = nullptr;

	while(fast && fast->next)
	{
		secondLast = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	if(slow == fast) return;
	secondLast->next = nullptr;
	secondLast = nullptr;

	ListNode* last = nullptr, *cur = slow, *next1 = nullptr, *next2 = nullptr;
	while(cur)
	{
		next1 = cur->next;
		cur->next = last;
		last = cur;
		cur = next1;
	}
	cur = head;
	while(cur && last)
	{
		next1 = cur->next;
		cur->next = last;
		next2 = last->next;
		last->next = next1;
		secondLast = last;
		cur = next1;
		last = next2;
	}
	if(last) secondLast->next = last;
}