class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        // let's try using level order traversal
        bool notRight = false;
        int lastLevel = -1;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        
        while(!q.empty()) {
            auto x = q.front();
            q.pop();
            TreeNode * node = x.first;
            int parentLevel = x.second;
            
            if((node->right || node->left) && notRight && parentLevel + 1 > lastLevel) {
                return false;
            }
                
            
            if(!notRight) {
                if(node->left) {
                    q.push({node->left, parentLevel+1});
                }
                
                if(node->right && !node->left) {
                    return false;
                }
                
                if(node->right) {
                    q.push({node->right, parentLevel+1});
                }
                else {
                    lastLevel = parentLevel+1;
                    notRight = true;
                }
            } else {
                int currentLevel = parentLevel+1;
                if(currentLevel == lastLevel) {
                    if(node->left) {
                        return false;
                    }
                    
                    if(node->right) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};



Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
  
  
