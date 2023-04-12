/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/




// brute force
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;
        int i=0;
        Node* ptr = head;
        while (ptr) {
            m[ptr] =new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        return m[head];
    }
};




class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * ptr = head;
        
        if(head == NULL)
            return NULL;
        
        while(ptr) {
            Node * node = new Node(ptr->val);
            // saving the next pointer
            Node * nxt = ptr->next;
            // making the new link
            ptr->next = node;
            // rejoining the next node to the newly created node
            node->next = nxt;
            
            ptr = ptr->next->next;
        }
        
        ptr = head;
        Node *newHead = head->next;
        Node *ptr2 = newHead;
        

        // making the random pointer connections
        while(ptr2) {
            if(ptr->random) {
                ptr2->random = ptr->random->next;
            }
            else {
                ptr2->random = NULL;
            }
            
            if(ptr2->next == NULL)
                break;
            
            ptr2 = ptr2->next->next;
            ptr = ptr->next->next;
        }
        
        
        // removing the remaking the connections  
        ptr = head, ptr2 = newHead;
        
        while(ptr2) {
            Node * nxt = ptr2->next;
            if(ptr2->next)
                ptr2->next = ptr2->next->next;
            ptr->next = nxt;
            ptr2 = ptr2->next;
            ptr = ptr->next;
        }
        
        return newHead;
    }
};
