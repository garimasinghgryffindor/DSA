
// we are using inorder traversal
// because inorder traversal of a bst is in ascending order.
// and we can get min difference using any two consecutive nodes
class Solution {
public:
    int mint = INT_MAX;
    TreeNode * prev = NULL;
    int minDiffInBST(TreeNode* root) {
        if(root==NULL)
            return mint;
        minDiffInBST(root->left);
        
        if(prev!=NULL)
        {
            mint = min(mint , root->val - prev->val);
        }
        
        prev = root;
        
        minDiffInBST(root->right);
        return mint;
    }
};



//  LEETCODE 783
// Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.
