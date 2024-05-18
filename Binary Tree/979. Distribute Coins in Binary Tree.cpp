class Solution {
public:
    int helper(TreeNode* root, TreeNode* parent= NULL) {
        if (!root) return 0;
        int  moves=helper(root->left, root)+helper(root->right, root);
        int x=root->val-1;
        if (parent) parent->val += x;
        moves+=abs(x);
        return moves;
    }
    
    int distributeCoins(TreeNode* root) {
        return helper(root);
    }
};
