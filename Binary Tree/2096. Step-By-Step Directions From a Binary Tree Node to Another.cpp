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
    bool findPath(TreeNode* root, int n, string &path) {
        if (!root) return false;
        if (root->val == n) return true;
        
        // Check in the left subtree
        path.push_back('L');
        if (findPath(root->left, n, path)) return true;
        path.pop_back();
        
        // Check in the right subtree
        path.push_back('R');
        if (findPath(root->right, n, path)) return true;
        path.pop_back();
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;
        
        // Find path to startValue and destValue
        findPath(root, startValue, pathToStart);
        findPath(root, destValue, pathToDest);
        
        // Find the first diverging point
        int i = 0;
        while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]) {
            i++;
        }
        
        // Create the result path: Up moves to common ancestor + Down moves to destValue
        string result(pathToStart.size() - i, 'U');
        result += pathToDest.substr(i);
        
        return result;
    }
    
};
