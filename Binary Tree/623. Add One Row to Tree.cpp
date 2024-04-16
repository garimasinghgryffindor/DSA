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
    void setDepth(TreeNode*root , int val , int depth){
        if(depth == 2){
            TreeNode *leftSubtree = root->left;
            TreeNode *rightSubtree = root->right;
                root->left = new TreeNode(val);
                root->left->left = leftSubtree;
                root->right = new TreeNode(val);
                root->right->right = rightSubtree;
            return;
        }
        
        if(root->left!=NULL)
        setDepth(root->left , val , depth-1);
        if(root->right!=NULL)
        setDepth(root->right , val , depth-1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode *head;
        if(depth == 1){
            head = new TreeNode(val);
            head->left = root;
            return head;
        }
        
        setDepth(root , val , depth);
        
        return root;
    }
};
