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
    ListNode* reverse(ListNode * head) {
        ListNode *curr = head, *prev = NULL, *nxt;
        while(curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        ListNode * rev = reverse(head);
        
        ListNode* curr = rev;
        ListNode * dummy = new ListNode(0);
        ListNode * curr2 = NULL;
        
        int carry = 0;
        while(curr || carry) {
            int ans = 0;
            if(curr) ans += 2*curr->val;
            ans += carry;
            carry = ans/10;
            ans = ans%10;
            ListNode * node = new ListNode(ans);
            node->next = curr2;
            curr2 = node;
            
            if(curr)
            curr = curr->next;
        }
        
        return curr2;
    }
};
