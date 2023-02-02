// LEETCODE 876

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * slow , *fast;
        slow = head , fast = head;
        
        while(slow->next != NULL && fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        if(fast->next == NULL)
            return slow;
        return slow->next;
    }
};
