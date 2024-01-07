int minSwaps(int arr[], int n) {

    // Complete the function
    // using sliding window
    int countOfOnes = 0, res = INT_MAX;
    
    for(int i = 0; i < n; i++) {
        countOfOnes+=arr[i];
    }
    
    if(countOfOnes == 0) return -1;
    
    int count = 0;
    for(int i = 0; i < countOfOnes; i++) {
        if(arr[i] == 1) count++;
    }
    
    res = min(res, countOfOnes - count);
    
    for(int i = countOfOnes; i < n; i++) {
        if(arr[i-countOfOnes] == 1) {
            count--;
        }
        if(arr[i] == 1) {
            count++;
        }
        
        res = min(res, countOfOnes - count);
    }
    
    return res;
    
}


