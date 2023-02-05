class Solution {
public:
    string sortString(string s) {
        string res = "";
        char prev;
        vector<int>count(26,0);
        for(auto x: s) {
            count[x-'a']++;
        }
        
        int len = s.length();
        int stage = 0;
        while(len) {
            if(stage == 0) {
                // finding the least
                for(int j=0 ; j<26 ; j++) {
                    if(count[j] > 0) {
                        res += j+'a';
                        prev = j;
                        stage = 1;
                        count[j]--;
                        len--;
                        break;
                    }
                }
            } else if(stage == 1) {
                // find the next smallest letter
                int f = 0;
                for(int j=prev+1 ; j<26 ; j++) {
                    if(count[j] > 0) {
                        count[j]--;
                        res += j+'a';
                        f = 1;
                        prev = j;
                        len--;
                        break;
                    }
                }
                if(f == 0) {
                    stage = 2;
                }
            } else if(stage == 2) {
                // find the largest
                for(int j=25 ; j>=0 ; j--) {
                    if(count[j] > 0) {
                        count[j]--;
                        res+=j+'a';
                        prev = j;
                        len--;
                        stage = 3;
                        break;
                    }
                }
            } else if(stage == 3) {
                int f = 0;
                for(int j=prev-1 ; j>=0 ; j--) {
                    if(count[j]>0) {
                        count[j]--;
                        res += j+'a';
                        f = 1;
                        len--;
                        prev = j;
                        break;
                    }
                }
                if(f == 0){
                    stage = 0;
                }
            }
        }
        
        return res;
    }
};


// LEETCODE 1370

// You are given a string s. Reorder the string using the following algorithm:

// 1. Pick the smallest character from s and append it to the result.
// 2. Pick the smallest character from s which is greater than the last appended character to the result and append it.
// 3. Repeat step 2 until you cannot pick more characters.
// 4. Pick the largest character from s and append it to the result.
// 5. Pick the largest character from s which is smaller than the last appended character to the result and append it.
// 6. Repeat step 5 until you cannot pick more characters.
// 7. Repeat the steps from 1 to 6 until you pick all characters from s.
// In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

// Return the result string after sorting s with this algorithm.





