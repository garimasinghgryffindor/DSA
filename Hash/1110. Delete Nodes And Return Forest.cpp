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
    
    void dfs(TreeNode*root, unordered_set<int>&del, unordered_set<TreeNode*>&st, TreeNode* par, bool left) {
        if(!root) return;
        int v = root->val;
        if(del.find(v) != del.end()) {
            if(st.find(root) != st.end()) {
                st.erase(root);
                if(root->left) {
                    st.insert(root->left);
                }
                if(root->right) {
                    st.insert(root->right);
                }
            } else {
                if(root->left) {
                    st.insert(root->left);
                }
                if(root->right) {
                    st.insert(root->right);
                }
            }
            
            if(left && par) {
                par->left = NULL;
            } else if(par) {
                par->right = NULL;
            }
            
            dfs(root->left, del, st, NULL, true);
            dfs(root->right, del, st, NULL, false);
            return;
        }
        
        dfs(root->left, del, st, root, true);
        dfs(root->right, del, st, root, false);
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<TreeNode*> st;
        unordered_set<int>del;
        for(int x: to_delete) {
            del.insert(x);
        }
        
        st.insert(root);
        dfs(root, del, st, NULL, true);
        vector<TreeNode*> res;
        for(auto x: st) {
            res.push_back(x);
        }
        
        return res;
    }
};
