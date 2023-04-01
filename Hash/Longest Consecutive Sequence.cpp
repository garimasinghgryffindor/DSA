// brute force

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size()==0 || nums.size()==1)
//             return nums.size();
        
//         sort(nums.begin() , nums.end());
//         int maxm=0 , tempMax=1;
//         for(int i=1 ; i<nums.size() ; i++){
//             if(nums[i] == nums[i-1]+1){
//                 tempMax++;
//             }
//             else if(nums[i] == nums[i-1]);
//             else{
//                 maxm = max(maxm , tempMax);
//                 tempMax = 1;
//             }
//         }
//         maxm = max(maxm , tempMax);
        
//         return maxm;
//     }
// };



// optimal

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1)
            return nums.size();
        
        set<int> st;
        for(auto x: nums) {
            st.insert(x);
        }
        
        int maxm = 0;
        
        for(auto x: nums) {
            if(!st.count(x-1)) {
                int currStreak = 1;
                int currNum = x;
                while(st.count(currNum+1)) {
                    currNum++;
                    currStreak++;
                }
                
                maxm = max(maxm, currStreak);
            }
        }
        
        return maxm;
    }
};
