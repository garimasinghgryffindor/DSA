class Solution {
public:
    bool recur(TreeNode * root) {
        if(!root) return true;
        if(root->left == NULL && root->right == NULL) return root->val == 1;
        bool l = recur(root->left);
        bool r = recur(root->right);
        if(root->val == 2) {
            return l || r;
        } else {
            return l && r;
        }
    }
    
    bool evaluateTree(TreeNode* root) {
        return recur(root);
    }
};
