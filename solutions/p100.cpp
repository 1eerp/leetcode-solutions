#include "common.h"
#include "leetcode.h"

bool isSameTree(TreeNode* p, TreeNode* q) {
	// If both are nullptr return true OR If only a single pointer is null, or if the values are not the same or the subtrees are different return false otherwise return true;
	return (p == q) || !(!p || !q || p->val != q->val || !isSameTree(p->left, q->left) || !isSameTree(p->right, q->right));
}