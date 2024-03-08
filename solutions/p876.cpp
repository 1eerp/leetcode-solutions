#include "common.h"

ListNode* middleNode(ListNode* head) {
	ListNode* temp = head;
	int i = 0;
	// Count nodes
	while(temp && ++i) temp = temp->next;
	
	// Half
	i >>= 1;

	// Move to middle
	while(i--) head = head->next;
	
	return head;
}