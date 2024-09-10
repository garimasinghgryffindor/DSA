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
    int gcd(int x, int y) {
        if (x == 0) 
            return y; 
        if (y == 0) 
            return x; 
        if(x == y) return x;
        if(x < y) {
            return gcd(x, y%x);
        }
        return gcd(x%y, y);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode * ptr = head, *nxt = head->next;
        while(nxt) {
            ListNode * node = new ListNode(__gcd(ptr->val, nxt->val));
            ptr->next = node;
            node->next = nxt;
            ptr = nxt;
            nxt = nxt->next;
        }
        return head;
    }
};
