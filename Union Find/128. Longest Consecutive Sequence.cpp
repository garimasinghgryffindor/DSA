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


// // optimal

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size()==0 || nums.size()==1)
//             return nums.size();
        
//         set<int> st;
//         for(auto x: nums) {
//             st.insert(x);
//         }
        
//         int maxm = 0;
        
//         for(auto x: nums) {
//             if(!st.count(x-1)) {
//                 int currStreak = 1;
//                 int currNum = x;
//                 while(st.count(currNum+1)) {
//                     currNum++;
//                     currStreak++;
//                 }
                
//                 maxm = max(maxm, currStreak);
//             }
//         }
        
//         return maxm;
//     }
// };


// using Union find
class Solution {
     unordered_map<int,int> mp;
public:
    int find(int x) {
        if(mp[x] <= -(1e9+1)) {
            return x;
        }
        return find(mp[x]);
    }
    
    void union_(int x, int y) {
        int px = find(x), py = find(y);
        if(px != py) {
            if(mp[px] <= mp[py]) {
                // px is larger
                mp[px] = mp[px] + 1e9 + mp[py] + 1e9 + -(1e9);
                mp[py] = px;
            } else {
                mp[py] = mp[py] + 1e9 +  mp[px] + 1e9 + -(1e9);
                mp[px] = py;
            }
        }
    }
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        for(int x: nums) {
            if(mp.find(x) == mp.end()) mp[x] = -(1e9+1);
        }
        
        for(int x: nums) {
            if(mp.find(x-1) != mp.end()) {
                union_(x-1, x);
            }
        }
        
        int res = 0;
        for(auto x: mp) {
            int size = x.second;
            res = min(res, size);
        }
        
        if(res == 0) return 0;
        
        return abs(res + 1e9);
    }
};


