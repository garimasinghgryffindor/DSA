class Solution {
public:
    int sum=0;
    
    void preorder(TreeNode* root , int n){
        if(root==NULL)
            return;
        
        n=n*10+root->val;
        if(root->left == NULL && root->right==NULL){
            sum+=n;
        } else {
            preorder(root->left , n);
            preorder(root->right , n);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        preorder(root , 0);
        return sum;
    }
};



You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.
  
  
