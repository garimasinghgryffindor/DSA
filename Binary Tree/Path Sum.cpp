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
    
    bool hasSum(TreeNode* root, int targetSum,int sum)
    {
        
        if(root==NULL)
            return false;
        
        sum+=root->val;
        int s1=sum;
        
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==targetSum)
            {
                return true;
            }
            
        }
        
        if(root->left!=NULL)
        {
            bool res = hasSum(root->left,targetSum,sum);
            if(res==true)
                return true;
        }
        
        if(root->right!=NULL)
        {
            sum=s1;
            bool res = hasSum(root->right,targetSum,sum);
            if(res==true)
                return true;
        }
        
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        //  DFS
        int sum=0;
        return hasSum(root,targetSum,sum);
    }
};



LEETCODE 112
  
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

