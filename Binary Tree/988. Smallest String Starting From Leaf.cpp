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
    void dfs(TreeNode *root, string&res, string temp) {
        if(!root) return;
        
        char c = root->val + 'a';
        string temp2;
        temp2.append(1, c);
        string curr = temp +  temp2;
        
        if(!root->left && !root->right) {
            reverse(curr.begin(), curr.end());
            if(res.empty() || res > curr) {
                res = curr;
            }
            return;
        }
        
        dfs(root->left, res, curr);
        dfs(root->right, res, curr);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string res;
        dfs(root, res, "");
        return res;
    }
};


