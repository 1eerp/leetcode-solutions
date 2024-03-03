#include "common.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
	if(!head->next) return nullptr;
	vector<ListNode*> nodes;
	nodes.reserve(30);

	while(head)
	{
		nodes.push_back(head);
		head = head->next;
	}
	
	int ns = nodes.size();
	if(n == ns)
	{
		delete nodes[0];
		return nodes[1];
	}
	else 
	{
		int index = ns-n;
		nodes[index-1]->next = nodes[index]->next;
		delete nodes[ns-n];
		return nodes[0];
	}
}