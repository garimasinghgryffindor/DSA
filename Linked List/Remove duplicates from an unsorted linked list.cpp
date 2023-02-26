#include <unordered_set>
class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates(Node *head) 
    {
     // your code goes here
     unordered_set<int> set;
     set.insert(head->data);
     Node *curr = head->next, *prev = head;
     
     while(curr!=NULL) {
         if(set.find(curr->data) == set.end()) {
             // i.e; element not found in the set-> unique element
             set.insert(curr->data);
             prev = curr;
             curr = curr->next;
         } else {
             // duplicate element
             prev->next = curr->next;
             curr = prev->next;
         }
     }
     
     return head;
    }
};

