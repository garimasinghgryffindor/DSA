class Solution {
public:
    void swap(char & a, char &b) {
        char temp = a;
        a = b;
        b = temp;
    }
    
    int largestInteger(int num) {
        string ans = to_string(num);
        
        int n = ans.length();
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<i ; j++) {
                if((int)ans[i]%2==0 && (int)ans[j]%2==0) {
                    // both even
                    if(ans[j] < ans[i]) {
                        // swap
                        swap(ans[j],ans[i]);
                    }
                } else if((int)ans[i]%2!=0 && (int)ans[j]%2!=0) {
                    // both odd
                    if(ans[j] < ans[i]) {
                        // swap
                        swap(ans[j],ans[i]);
                    }
                }
            }
        }
        
        return stoi(ans);
        
    }
};
