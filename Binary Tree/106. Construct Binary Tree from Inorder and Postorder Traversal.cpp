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
     void createMapping(vector<int>& inorder, unordered_map<int,int>& nodeToIndex, int size) {
        for(int i = 0; i < size; i++) {
            nodeToIndex[inorder[i]]=i;
        }
    }
    
    TreeNode *build(vector<int>&inorder,vector<int>&postorder,int&index , int l , int r , unordered_map<int , int> &mp) {
        if(l>r)
            return NULL;
        
        int position = mp[postorder[index--]];
        int element = inorder[position];
        TreeNode * node = new TreeNode(element);
        
        node->right = build(inorder , postorder , index , position+1 , r , mp);
        node->left = build(inorder , postorder , index , l , position-1 , mp);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int postOrderIndex=postorder.size()-1;
        unordered_map<int,int>mp; 
        createMapping(inorder , mp , inorder.size());
        TreeNode * res = build(inorder , postorder , postOrderIndex , 0 , n-1 , mp);
        
        return res;
    }
};


