#include "common.h"

class FBLVSolution {
public:
    int findBottomLeftValue(TreeNode* root) {
        Traverse(root,0);
        return leftMostVal;
    }

    void Traverse(TreeNode* root, int row)
    {
        if(root->right) Traverse(root->right, row+1);
        if(root->left) Traverse(root->left, row+1);
        else if(root->right == nullptr && row >= lowestRow)
        {
            leftMostVal = root->val;
            lowestRow = row;
            return;
        }
    }
private:
    int lowestRow = -1;
    int leftMostVal = 0;
};