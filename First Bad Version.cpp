// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int lb,ub,mid;
    lb=1,ub=n;
    
    while(lb<=ub)
    {
        if(lb%2 == 0 || ub%2 == 0)
        {
            mid= lb/2 + ub/2;
        }
        
        else{
            mid= lb/2 + ub/2 + 1;
        }
            
        
        if(isBadVersion(mid) && (!isBadVersion(mid-1)))
        {
            break;
        }
        
        else if(isBadVersion(mid))
        {
            ub=mid-1;
        }
        
        else{
            lb=mid+1;
        }
    }
    
    return mid;
}


/*
LEETCODE 278
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product 
fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version.
You should minimize the number of calls to the API.
*/







