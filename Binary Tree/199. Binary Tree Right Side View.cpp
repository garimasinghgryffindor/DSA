class Solution {
public:
    int height(TreeNode*root) {
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    
    void bfs(TreeNode*root, vector<int>&res,vector<bool> vis,int h) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()) {
            TreeNode* x = q.front().first;
            int level = q.front().second;
            q.pop();
            if(!vis[level]) {
                res[level] = x->val;
                vis[level] = true;
            }
            if(x->right != NULL) {
                q.push({x->right, level+1});
            }
            if(x->left != NULL) {
                q.push({x->left, level+1});
            }
        }
    }
    
    vector<int> rightSideView(TreeNode* root) {
        int h = height(root);
        if(h==0)
            return {};
        
        vector<int> res(h);
        vector<bool> vis(h,false);
        bfs(root,res,vis,h);
        return res;
    }
};
