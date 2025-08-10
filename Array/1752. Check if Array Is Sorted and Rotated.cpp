class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        // remove duplicates
        vector<int>dedup;
        bool alreadySorted = true;
        dedup.push_back(nums[0]);
        for(int i = 1; i < n; i++) {
            if(dedup[dedup.size()-1] != nums[i]) {
                dedup.push_back(nums[i]);
            }
            if(nums[i-1] > nums[i]) {
                alreadySorted = false;
            }
        }

        if(alreadySorted) return true;

        // find the peak point
        int sz = dedup.size();

        int peak = -1;
        for(int i = 0; i < sz-1; i++) {
            if(dedup[i] > dedup[i+1]) {
                // peak point detected
                peak = i;
                break;
            }
        }

        for(int i = 1; i <= peak; i++) {
            if(dedup[i-1] > dedup[i]) return false;
        }  // left half is okay

        for(int i = peak+1; i < sz-1; i++) {
            if(dedup[i] > dedup[i+1]) return false;
        }  // right half is okay

        // check whether left half is connected to the right half
        if(dedup[0] < dedup[dedup.size()-1]) return false;
        
        return true;
    }
};

