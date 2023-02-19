class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <TreeNode*> parent , child;
        vector<vector<int> > result;
        
        if(root==NULL)
            return result;
        
        parent.push_back(root);
        vector<int> innerVector;
        innerVector.push_back(root->val);
        result.push_back(innerVector);
        innerVector.clear();
        int f=1;
        
        while(!parent.empty())
        {
            if((parent.front())->left!=NULL)
            {
                child.push_back((parent.front())->left);
                innerVector.push_back(((parent.front())->left)->val);
            }
            
            if((parent.front())->right!=NULL)
            {
                child.push_back((parent.front())->right);
                innerVector.push_back(((parent.front())->right)->val);
            }
            
            parent.erase(parent.begin());
            
            if(parent.empty() && child.empty())
                break;
            
            if(parent.empty())
            {
                if(f==1)
                {
                    reverse(innerVector.begin() , innerVector.end());
                }
                f*=-1;
                result.push_back(innerVector);
                copy(child.begin() , child.end() , back_inserter(parent));
                child.clear();
                innerVector.clear();
            }
        }
        
        return result;
    }
};



LEETCODE 103

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).


