class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return root;
        
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};





LEETCODE 226

Given the root of a binary tree, invert the tree, and return its root.
  
  
