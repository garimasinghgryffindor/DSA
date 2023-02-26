//Remove nth duplicate element from the given linked list.
//Example: 1 -> 2 -> 3 -> 1 -> 2 -> 3 ->1 ->2 ->3, n=2 Here the nth(2nd) duplicate
//element in this list is 2.
//So, return, 1 -> 3 -> 1 -> 3 -> 1 -> 3

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
 
/* A linked list node */
struct Node {
    int data;
    struct Node* next;
};
 
// Utility function to create a new Node
struct Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

struct Node* removeDuplicates(Node * root, int n) {
    unordered_set<int> set;
    unordered_set<int> dupes;
    Node * curr = root;
    Node * prev = NULL;
    unordered_map<int, vector<Node*> > mp;

    int res = 0;
    bool found = false;

    while(curr!=NULL) {
        if(!found && set.find(curr->data) != set.end()) {
            // i.e; a duplicate
            if(dupes.find(curr->data) == dupes.end()) {
                dupes.insert(curr->data);
                n--;
                if(n==0) {
                    // will be removed
                    res = curr->data;
                    found = true;
                }
            }
        } else {
            set.insert(curr->data);
        }

        mp[curr->data].push_back(prev);
        prev = curr;
        curr = curr->next;
    }

    reverse(mp[res].begin(), mp[res].end());

    for(auto x: mp[res]) {
        if(x == NULL) {
            root = root->next;
        }

        else if(x->next == root) {
            root = root->next;
        }

        else {
            x->next = x->next->next;
        }
    }

    return root;
}

int main()
{
    /* The constructed linked list is:
     10->12->11->11->12->11->10*/

    //struct Node* start = newNode(10);
    //start->next = newNode(12);
    //start->next->next = newNode(11);
    //start->next->next->next = newNode(11);
    //start->next->next->next->next = newNode(12);
    //start->next->next->next->next->next = newNode(11);
    //start->next->next->next->next->next->next = newNode(10);

    struct Node* start = newNode(10);
    start->next = newNode(10);
    start->next->next = newNode(10);
    start->next->next->next = newNode(11);
    start->next->next->next->next = newNode(12);
    start->next->next->next->next->next = newNode(11);
    start->next->next->next->next->next->next = newNode(10);
 
    printf("Linked list before removing duplicates ");
    printList(start);
 
    struct Node* newRoot = removeDuplicates(start,1);
 
    printf("\nLinked list after removing duplicates ");
    printList(newRoot);
    return 0;
}
