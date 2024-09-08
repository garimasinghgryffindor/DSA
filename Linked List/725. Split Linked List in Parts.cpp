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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        ListNode* temp = head;
        int n=0 ;
        //counting the nodes
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int x = n/k;
        int x1 = x;
        if(n<k){
            x=1;
            x1=1;
        }
        int f=0;
        temp=head;
        while(temp!=NULL){
            int y ;
            ListNode *temp2=temp;
            if(n%k!=0 && n>k){
                y=x+1;
                n--;
            }
            else{
                y=x;
            }
            while(y-1 && temp!=NULL){
                temp=temp->next;
                y--;
            }
            res.push_back(temp2);
            ListNode *temp3;
            if(temp!=NULL){
                temp3 = temp->next;
                temp->next = NULL;
                temp = temp3;
            }
        }
        if(res.size()<k){
            while(res.size()<k){
                res.push_back(NULL);
            }
        }
        return res;
    }
};
