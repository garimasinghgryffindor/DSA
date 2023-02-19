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
    int calHeight(TreeNode *root) {
        if(!root)
            return 0;
        return 1 + max(calHeight(root->left), calHeight(root->right));
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // using level order traversal
        
        // calculating the height
        int height = calHeight(root);
        if(height == 0)
            return {};
        
        list<int> res2[height];
        vector<vector<int>> res(height);
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()) {
            TreeNode * node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(level%2 == 0) {
                // i.e; even level
                res2[level].push_back(node->val);
            } else {
                // i.e; odd level
                res2[level].push_front(node->val);
            }
            if(node->left != NULL) {
                q.push({node->left,level+1});
            }
            if(node->right != NULL) {
                q.push({node->right, level+1});
            }
        }
        
        for(int i=0 ; i<height ; i++) {
            for(auto x: res2[i]) {
                res[i].push_back(x);
            }
        }
        
        return res;
    }
};


LEETCODE 103

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).


