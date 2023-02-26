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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * newList = new ListNode() , *iter1 = list1, *iter2 = list2;
        ListNode* curr = newList;
        
        while(iter1!=NULL && iter2!=NULL) {
            if(iter1->val <= iter2->val) {
                curr->next = iter1;
                iter1 = iter1->next;
            }
            else {
                curr->next = iter2;
                iter2 = iter2->next;
            }
            curr=curr->next;
        }
        
        while(iter1!=NULL) {
            curr->next = iter1;
            iter1 = iter1->next;
            curr=curr->next;
        }
        
        while(iter2!=NULL) {
            curr->next = iter2;
            iter2 = iter2->next;
            curr = curr->next;
        }
        
        return newList->next;
    }
};



LEETCODE 21
  
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

