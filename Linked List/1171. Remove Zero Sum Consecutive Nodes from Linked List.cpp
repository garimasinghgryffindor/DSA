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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode * dummy = new ListNode(0) , *curr = dummy;
        curr->next = head;
        int prefix = 0;
        unordered_map<int, ListNode*> mp;
        
        while(curr) {
            prefix += curr->val;
            if(mp.count(prefix)) {
                curr = mp[prefix]->next;
                int p = prefix + curr->val;
                while(p!=prefix) {
                    mp.erase(p);
                    curr = curr->next;
                    p+=curr->val;
                }
                mp[prefix]->next = curr->next;
            } else {
                mp[prefix] = curr;
            }
            curr = curr->next;
        }
        
        return dummy->next;
    }
};
