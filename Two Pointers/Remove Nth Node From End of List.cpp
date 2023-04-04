class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dummy = new ListNode();
        dummy->next = head;
        ListNode * fast = dummy, *slow = dummy;
        int x = n;
        while(x--) {
            fast = fast->next;
        }
        
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};
