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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        while(head->val == val) {
            ListNode * temp = head;
            head = head->next;
            delete temp;
            if(head == NULL)
                return head;
        }
        
        ListNode * prev = head , * curr = head->next;
        
        while(curr) {
            if(curr->val == val) {
                ListNode * temp = curr;
                prev->next = curr->next;
                delete temp;
                curr = prev->next;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};




LEETCODE 203

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.


