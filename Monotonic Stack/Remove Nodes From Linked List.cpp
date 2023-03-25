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
    ListNode* removeNodes(ListNode* head) {
        // there we want a monotonically decreasing stack essentially
        stack<ListNode*> st;
        ListNode * node = head;
        while(node) {
            
            int x = node->val;
            while(!st.empty() && st.top()->val < x) {
                st.pop();
            }
            st.push(node);
            node = node->next;
        }
        
        auto ptr = st.top();
        st.pop();
        ptr->next = NULL;
        st.push(ptr);
        
        
        while(!st.empty()) {
            ListNode * ptr1 = st.top();
            st.pop();
            if(st.empty()) {
                return ptr1;
            } else {
                ListNode * ptr2 = st.top();
                st.pop();
                ptr2->next = ptr1;
                st.push(ptr2);
            }
        }
        
        return NULL;
    }
};
