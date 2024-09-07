/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool preorder(TreeNode * head , ListNode * node){
        if(node == NULL)
            return true;
        if(head == NULL)
            return false;

        return head->val == node->val && (preorder(head->left, node->next) || preorder(head->right , node->next));
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root)
            return false;

        return preorder(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
