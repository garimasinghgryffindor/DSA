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

// ITERATIVE
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *nextNode;
        
        while(head) {
            nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
};



// RECURSIVE

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL || head->next == NULL)
//             return head;
        
//         ListNode * newHead = reverseList(head->next);
        
//         head->next->next = head;
//         head->next = NULL;
        
//         return newHead;
//     }
// };



LEETCODE 206
  
Given the head of a singly linked list, reverse the list, and return the reversed list.

