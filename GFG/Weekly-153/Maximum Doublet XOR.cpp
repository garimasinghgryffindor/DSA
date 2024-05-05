/*

Definition for singly Link List Node
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
  
    Node * findMid(Node * head) {
        Node * slow = head, * fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node * reverse(Node * head) {
        Node * curr = head, * prev = NULL, * next;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
  
    int maximumDoubletXOR(struct Node* head) {
        int xor_ = 0;
        Node * mid = findMid(head);
        Node * sec = mid->next;
        mid->next = NULL;
        Node * rev = reverse(sec);
        
        Node * node = head, * node2 = rev;
        
        while(node && node2) {
            int temp = node->data ^ node2->data;
            xor_ = max(xor_, temp);
            node = node->next;
            node2 = node2->next;
        }
        
        return xor_;
    }
};
