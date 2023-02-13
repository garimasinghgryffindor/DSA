class Solution {
public:
    bool checkBST(TreeNode*root,long lowerBound,long upperBound){
        if(!root)
            return true;
        
        if(root->val <= lowerBound || root->val >= upperBound)
            return false;
        
        return checkBST(root->left,lowerBound,root->val) && checkBST(root->right,root->val,upperBound);
    }
    
    bool isValidBST(TreeNode* root) {
        return checkBST(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max() );
    }
};


LEETCODE 98
