#include "common.h"
#include "leetcode.h"

bool isEvenOddTree(TreeNode* root) {
	bool evenLevel = true;
	int lvlNodeCount = 1;
	int nextLevelCount = 0;
	int lastVal = 0;

	std::queue<TreeNode*> q;
	q.push(root);
	
	while(q.size())
	{
		if(!lvlNodeCount)
		{
			lvlNodeCount = nextLevelCount; 
			nextLevelCount = 0;
			evenLevel = !evenLevel;
			lastVal = evenLevel * 0 + !evenLevel * 1000001;
		}
		TreeNode* node = q.front();
		if(node->left) {q.push(node->left); nextLevelCount++;}
		if(node->right) {q.push(node->right); nextLevelCount++;}
		bool valIsOdd = node->val % 2;
		if((evenLevel && ( !valIsOdd || node->val <= lastVal)) || (!evenLevel && (valIsOdd || lastVal <= node->val))) return false;
		lastVal = node->val;
		q.pop();
		lvlNodeCount--;
	}

	return true;
}