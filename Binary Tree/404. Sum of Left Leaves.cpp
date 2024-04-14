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
    void helper(TreeNode * root , int f , int&sum){
        if(root == NULL)
            return;
        if(f==1 && root->left == NULL && root->right == NULL){
            sum+=root->val;
            return;
        }
        helper(root->left , 1 , sum);
        helper(root->right , 2 , sum);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root , 0 , sum);
        return sum;
    }
};
