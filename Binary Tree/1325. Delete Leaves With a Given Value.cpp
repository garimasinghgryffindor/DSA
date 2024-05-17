class Solution {
public:
    TreeNode* recur(TreeNode* root, int target) {
        if(!root) return NULL;
        
        TreeNode* left = recur(root->left, target);
        TreeNode* right = recur(root->right, target);
        
        root->left = left;
        root->right = right;
        
        // if now it is a leaf node
        if(!root->left && !root->right) {
            if(root->val == target) {
                return NULL;
            }
        }
        
        return root;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return recur(root, target);
    }
};
