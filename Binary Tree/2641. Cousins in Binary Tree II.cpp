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
    TreeNode* replaceValueInTree(TreeNode* root) {
        TreeNode * res;
        
        queue<pair<TreeNode*, TreeNode*> > q;
        // q.push(root);
        
        res = new TreeNode(0);
        
        if(root->left) {
            res->left = new TreeNode(0);
            q.push({root->left, res->left});
        }
        if(root->right) {
            res->right = new TreeNode(0);
            q.push({root->right, res->right});
        }
        
        int sum = 0;
        while(!q.empty()) {
            int sz = q.size();
            int newsum = 0;
            while(sz--) {
                auto temp = q.front();  q.pop();
                auto org = temp.first;
                auto ans = temp.second;
                ans->val = sum + ans->val;
                
                if(org->left && org->right) {
                    ans->left = new TreeNode(-1*(org->left->val + org->right->val));
                    ans->right = new TreeNode(-1*(org->left->val + org->right->val));
                    newsum += org->left->val;
                    newsum += org->right->val;
                    q.push({org->left, ans->left});
                    q.push({org->right, ans->right});
                } else if(org->left) {
                    ans->left = new TreeNode(-1*(org->left->val));
                    newsum += org->left->val;
                    q.push({org->left, ans->left});
                } else if(org->right) {
                    ans->right = new TreeNode(-1*(org->right->val));
                    newsum += org->right->val;
                    q.push({org->right, ans->right});
                }
            }
            // cout<<"newsum :  "<<newsum<<endl;
            sum = newsum;
        }
        
        return res;
    }
};
