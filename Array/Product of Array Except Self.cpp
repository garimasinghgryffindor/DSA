vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> lhs(n),rhs(n);
    lhs[0] = nums[0];
    rhs[n-1] = nums[n-1];
    for(int i=1 ; i<n ; i++) {
        lhs[i] = lhs[i-1] * nums[i];
        rhs[n-1-i] = rhs[n-i] * nums[n-1-i]; 
    }
    
    for(int i=0 ; i<n ; i++) {
        int l = 1, r = 1;
        if(i!=0) {
            l = lhs[i-1];
        }
        if(i!=n-1) {
            r = rhs[i+1];
        }
        nums[i] = l*r;
    }
    
    return nums;
}


vector<int> productExceptSelf(vector<int>& nums) {
    long long prod = 1;
    int count_zero = 0;
    int n = nums.size();
    
    vector<int> res(n, 0);
    
    for(int i : nums) {
        if(i == 0) count_zero++;
        
        if(count_zero > 1) {
            prod = 0;
            return res;
        } else if(i == 0) {
            // leave prod as it is
        } else {
            prod *= i;
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(nums[i] == 0) {
            res[i] = prod;
        } else if(count_zero == 1){
            res[i] = 0;
        } else {
            res[i] = prod / nums[i];
        }
    }
    
    return res;
}

