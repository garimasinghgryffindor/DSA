/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root , vector<int>&in){
        if(root==NULL)
            return;
        inorder(root->left , in);
        in.push_back(root->val);
        inorder(root->right , in);
    }
    
    TreeNode* balanced_bst(TreeNode *head , vector<int> in , int l , int r){
        if(l>r)
            return NULL;
        int mid = l + (r-l)/2;
        
        head = new TreeNode(in[mid]);
        head->left = balanced_bst(head->left , in , l , mid-1);
        head->right = balanced_bst(head->right , in , mid+1 , r);
        
        return head;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root , in);
        TreeNode *head;
        head = balanced_bst(head , in , 0 , in.size()-1);
        
        return head;
    }
};
