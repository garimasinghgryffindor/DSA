// RECURSION
// TLE

// class Solution {
// public:
//     int recur(int n,vector<bool>visP,vector<bool>visD,int visCount) {
//         if(visCount == 2*n)
//             return 1;
        
//         int res = 0;
        
//         for(int i=0 ; i<n ; i++) {
//             if(!visP[i]) {
//                 visP[i] = true;
//                 res += recur(n,visP,visD,visCount+1);
//                 visP[i] = false;
//             }
            
//             if(visP[i] && !visD[i]) {
//                 visD[i] = true;
//                 res += recur(n,visP,visD,visCount+1);
//                 visD[i] = false;
//             }
//         }
        
//         return res;
//     }
    
//     int countOrders(int n) {
//         vector<bool>visP(n,false);
//         vector<bool>visD(n,false);
//         int visCount = 0;
//         return recur(n,visP,visD,visCount);
//     }
// };




// TABULATION
// we will be using the intution->
// at n = 1-> there is 1 way
// at n = 2-> there are 6 possible ways
// p1. p2  d1  d2 
// p1. p2. d2. d1
//.. so forth
// at n=3-> 
// we will that at n = n-1
// on how many positions can we place dn and pn
// at n = 3->. n=2-> we have total 4 elements
// so pickup can be placed at 5 total locations
// and delivery can also be placed respectively->
// if pos = 0-> so delivery can be at 0,1,2,3,4=> 5 loc
// if pos = 1-> so delivery can be at 1,2,3,4=> 4 loca
// so total can be = 5*6/2=> 15 for 1 sequence
// and 15*6 => 90 for all

class Solution {
public:
   
    int countOrders(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 6;
        
        long long MOD = 1e9+7;
        
        vector<long long> dp(n+1,-1);
        dp[1] = 1;
        dp[2] = 6;
        
        for(int i=3 ; i<=n ; i++) {
            dp[i] = (dp[i-1] * (2*(i-1) + 1)*(2*(i-1) + 2)/2)%MOD;
        }
        
        return dp[n];
    }
};




// further optimizing the space

class Solution {
public:
   
    int countOrders(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 6;
        
        long long MOD = 1e9+7;
        
        long long prev = 6;
        
        for(int i=3 ; i<=n ; i++) {
            prev = (prev * (2*(i-1) + 1)*(2*(i-1) + 2)/2)%MOD;
        }
        
        return (int)prev;
    }
};
