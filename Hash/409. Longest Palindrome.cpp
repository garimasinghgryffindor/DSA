class Solution {
public:
    int longestPalindrome(string s) {
        int sum=0;
        unordered_map<char , int> mp;
                   // char   freq
        for(int i=0 ; i<s.length() ; i++){
            mp[s[i]]++;
        }
        
        int odd_flag = 0;
        for(auto i : mp){
            if(i.second % 2 ==0){
                sum+=i.second;
            } else {
                if(odd_flag == 0){
                    odd_flag = 1;
                    sum+=i.second;
                } else {
                    if(i.second>1){
                        sum+=i.second-1;
                    }
                }
            }
        }
        
        return sum;
    }
};
