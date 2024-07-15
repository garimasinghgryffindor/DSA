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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode * root = NULL;
        unordered_map<int, TreeNode*> mp;
        unordered_set<int>children;
        for(auto x: descriptions) {
            int par = x[0];
            int child = x[1];
            bool left = x[2];
            TreeNode * p = NULL, * c = NULL;
            if(mp.find(par) == mp.end()) {
                p = new TreeNode(par);
                mp[par] = p;
            } else {
                p = mp[par];
            }
            
            if(mp.find(child) == mp.end()) {
                c = new TreeNode(child);
                mp[child] = c;
            } else {
                c = mp[child];
            }
            
            children.insert(child);
            
            if(left) {
                p->left = c;
            } else {
                p->right = c;
            }
        }
        
        for(auto x: descriptions) {
            if(children.find(x[0]) == children.end()) {
                return mp[x[0]];
            }
        }
        
        return root;
    }
};
