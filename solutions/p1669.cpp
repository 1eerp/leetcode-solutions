#include "common.h"

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
	int i = 0;
	ListNode* head = list1, *middleFront = nullptr;
	// Get to the first node to remove
	while(i < a)
	{
		middleFront = list1;
		list1 = list1->next;
		i++;
	}
	// If a node exists before the first node to remove, append to list2
	// It is guaranteed the first node will not be removed, hence no need for a branch
	middleFront->next = list2;

	// Get to the end of list2
	while(list2->next)
		list2 = list2->next;
	
	// Get to the last node thats to be removed
	ListNode* delNode = nullptr;
	while(a++ < b)
	{
		delNode = list1;
		list1 = list1->next;
		delete delNode;
	}

	// Connect last node of list2 to the start of the second split of list1
	list2->next = list1->next;

	// Delete last node to be removed;
	delete list1;
	
	return head;
}