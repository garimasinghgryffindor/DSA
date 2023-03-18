class BrowserHistory {
public:
    class Node{
        public:
        string url;
        Node* prev;
        Node* next;
        
        Node(string url){
            this->url = url;
            prev = NULL;
            next = NULL;
        }
    };
    
    Node* curr;
    
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        curr->next = new Node(url);
        Node * nextNode = curr->next;
        nextNode->prev = curr;
        curr = nextNode;
    }
    
    string back(int steps) {
        while(curr->prev!=NULL && steps-->0) {
            curr = curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(curr->next!=NULL && steps-->0) {
            curr = curr->next;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
