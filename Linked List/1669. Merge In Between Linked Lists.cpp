class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int diff = b-a+1;
        ListNode * dummy = new ListNode(0);
        dummy->next = list1;
        ListNode*fast = dummy;
        while(diff-- && fast) {
            fast = fast->next;
        }
        
        int x = 0;
        ListNode *slow = dummy;
        while(x < a) {
            slow = slow->next;
            fast = fast->next;
            x++;
        }
        
        slow->next = list2;
        ListNode * ptr = list2;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        
        ptr->next = fast->next;
        
        return dummy->next;
    }
};
