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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int min_ = INT_MAX, max_ = -1;
        int first_critical = -1;
        int prev_critical = -1;
        int idx = 0;
        
        if(head->next->next == NULL || head->next->next->next == NULL) return {-1, -1};
        ListNode* prev = head, *curr = head->next;
        
        while(curr->next != NULL) {
            ListNode * nxt = curr->next;
            if(curr->val < prev->val && curr->val < nxt->val) {
                // minima
                if(first_critical == -1) {
                    first_critical = idx;
                    prev_critical = idx;
                } else {
                    min_ = min(min_, idx - prev_critical);
                    prev_critical = idx;
                }
                
            } else if(curr->val > prev->val && curr->val > nxt->val) {
                // maxima
                if(first_critical == -1) {
                    first_critical = idx;
                    prev_critical = idx;
                } else {
                    min_ = min(min_, idx - prev_critical);
                    prev_critical = idx;
                }
                
            }
            
            idx++;
            prev = curr;
            curr = curr->next;
        }
        
        if(prev_critical != -1) {
            max_ = prev_critical - first_critical;
        }
        
        if(max_ == INT_MIN || min_ == INT_MAX) {
            return {-1, -1};
        }
        
        return {min_, max_};
    }
};
