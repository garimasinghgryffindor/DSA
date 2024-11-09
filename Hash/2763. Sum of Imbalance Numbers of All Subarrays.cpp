class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int ans=0; //total count of imbalance numbers
        for(int i=0; i<nums.size(); i++){
            int t=0; //count of imbalance numbers of subarrays starting from ith position
            vector<int> vis(1005, 0); //an array to keep track of which number is visited or not in the subarray
            vis[nums[i]]=1;
            for(int j=i+1; j<nums.size(); j++){
                if(vis[nums[j]]==1){
                    //nums[j] is already present in visited array
                    ans+=t;
                    continue;
                }
                vis[nums[j]]=1;
                if(vis[nums[j]+1]==1 && vis[nums[j]-1]==1){
                    //if nums[j]+1 and nums[j]-1 are also present in visited array 
                    t--; // when nums[j] was not present, then 't' was containing the count of the pair (nums[j]+1 and nums[j]-1), 
                        //now that nums[j] is present we have to decrement the current count of imbalance numbers(t) 
                    ans+=t;
                    continue;
                }
                if(vis[nums[j]+1]==1 || vis[nums[j]-1]==1){
                    //if only one of the value nums[j]+1 or nums[j]-1 is present, then the current count of imbalance numbers does not change
                    ans+=t;

                }  
                else{
                    t++;
                    ans+=t;
                }
            }
        }
        return ans;
    }
};
