#include "common.h"

bool hasCycle(ListNode *head) {
	int i = 10001;
	while(head && --i) head = head->next;;
	return head;
}