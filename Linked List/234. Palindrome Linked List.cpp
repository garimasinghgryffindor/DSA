// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         ListNode * ptr = head;
//         stack<int>st;
//         while(ptr) {
//             st.push(ptr->val);
//             ptr = ptr->next;
//         }
        
//         ptr = head;
//         while(ptr) {
//             int tp = st.top(); st.pop();
//             if(tp != ptr->val) return false;
//             ptr = ptr->next;
//         }
        
//         return true;
//     }
// };


// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         ListNode * ptr = head;
//         stack<int>st;
//         while(ptr) {
//             st.push(ptr->val);
//             ptr = ptr->next;
//         }
        
//         ptr = head;
//         while(ptr) {
//             int tp = st.top(); st.pop();
//             if(tp != ptr->val) return false;
//             ptr = ptr->next;
//         }
        
//         return true;
//     }
// };



// class Solution {
// public:
//     ListNode * reverse(ListNode * ptr) {
//         if(!ptr) return NULL;
//         if(ptr->next == NULL) return ptr;
//         ListNode * nxt = ptr->next;
//         ListNode * newHead = reverse(nxt);
//         ptr->next = NULL;
//         nxt->next = ptr;
//         return newHead;
//     }
    
//     bool isPalindrome(ListNode* head) {
//         ListNode * slow = head, * fast = head;
//         while(fast->next && fast->next->next) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
        
//         ListNode * secondHalf = slow->next;
//         slow->next = NULL;
        
//         secondHalf = reverse(secondHalf);
        
//         slow = head;
//         fast = secondHalf;
//         while(slow && fast) {
//             if(slow->val != fast->val) return false;
//             slow = slow->next; fast = fast->next;
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode * slow = head, * fast = head, *prev = NULL, *nxtptr;
        while(fast && fast->next) {
            fast = fast->next->next;
            nxtptr = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxtptr;
        }
        
        slow = fast ? slow->next : slow;
        
        while(slow) {
            if(slow->val != prev->val) return false;
            slow = slow->next;
            prev = prev->next;
        }
        return true;
    }
};



