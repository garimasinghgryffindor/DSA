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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *curr = head->next;
        ListNode * node = new ListNode();
        ListNode * newList = node;
        int sum = 0;
        while(curr!=NULL) {
            if(curr->val != 0){
                sum+=curr->val;
            } else {
                node->next = new ListNode(sum);
                sum = 0;
                node = node->next;
            }
            curr = curr->next;
        }
        
        return newList->next;
    }
};
