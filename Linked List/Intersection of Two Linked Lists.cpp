class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2=0;
        ListNode * temp1 = headA, *temp2 = headB;
        while(temp1) {
            len1++;
            temp1=temp1->next;
        }
        while(temp2) {
            len2++;
            temp2=temp2->next;
        }
        
        int flag = 0;
        if(len1-len2 >= 0) {
            
        } else {
            flag = 1;
        }
        
        ListNode * ptr, *ptr2;
        if(flag) {
            ptr = headB;
            ptr2 = headA;
        } else {
            ptr = headA;
            ptr2 = headB;
        }
        
        int diff = abs(len1-len2);
        
        while(diff--) {
            ptr = ptr->next;
        }
        
        while(ptr && ptr2) {
            if(ptr == ptr2) {
                return ptr;
            }
            
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        
        return NULL;
        
    }
};
