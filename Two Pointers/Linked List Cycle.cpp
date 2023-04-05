/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



class Solution {
public:
    // using hashing
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        ListNode *node = head;
        while(node) {
            if(st.find(node) != st.end())
                return true;
            st.insert(node);
            node = node->next;
        }
        
        return false;
    }
};



class Solution {
public:
    // using slow pointer fast pointer
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        
        if(head == NULL)
            return false;
        
        while(fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        
        return false;
    }
};
