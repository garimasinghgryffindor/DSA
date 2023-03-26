
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n,-1));
        ListNode * node = head;
        int right = n-1, left = 0, top = 0, bottom = m-1;

        int i=0,j=0;
        while(node) {
            // go right
            for(i=left ; i<=right ; i++) {
                if(node == NULL)
                    break;
                res[top][i] = node->val;
                node = node->next;
            }
            top++;
            
            // go down ;
            for(j=top ; j<=bottom ; j++) {
                if(node == NULL)
                    break;
                res[j][right] = node->val;
                node = node->next;
            }
            right--;
            
            // go left
            for(i=right ; i>=left ; i--) {
                if(node == NULL)
                    break;
                res[bottom][i] = node->val;
                node = node->next;
            }
            bottom--;
            
            // go up
            for(j=bottom ; j>=top ; j--) {
                if(node == NULL)
                    break;
                res[j][left] = node->val;
                node = node->next;
            }
            left++;
        }
        
        return res;
    }
};
