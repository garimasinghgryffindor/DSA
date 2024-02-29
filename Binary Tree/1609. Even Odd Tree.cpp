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
    bool isEvenOddTree(TreeNode* root) {
        bool even = true;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            int prev = even ? INT_MIN : INT_MAX;
            while(sz--) {
                TreeNode * node = q.front();    q.pop();
                int val = node->val;
                if(even) {
                    if(val%2 == 0) return false;
                    
                    if(prev < val) {
                        // A ok
                    } else {
                        return false;
                    }
                } else {
                    if(val%2 != 0) return false;
                    
                    if(prev > val) {
                        // A ok
                    } else {
                        return false;
                    }
                }
                prev = val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            even = !even;
        }
        
        return true;
    }
};
