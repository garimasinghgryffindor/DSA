class Solution {
public:
    void swap(int &a , int &b){
        int temp=a;
        a = b;
        b = temp;
    }
    
    void nextPermutation(vector<int>& nums) {
        int n=nums.size() , f=0;
        
        int i;
        for(i=n-1 ; i>0 ; i--){
            if(nums[i]>nums[i-1]){
                f=1;
                break;
            }
        }
        
        if(f==0){
            sort(nums.begin() , nums.end());
            return;
        }
        
        i--;
        
        //  if the permutation is the last permutation
        for(int j=n-1 ; j>i ; j--){
            if(nums[j] > nums[i])
            {
                swap(nums[j] , nums[i]);
                break;
            }
        }
    
        reverse(nums.begin()+i+1 , nums.end());
    }
};
