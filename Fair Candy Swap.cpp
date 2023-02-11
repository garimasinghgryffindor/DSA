// class Solution {
// public:
//     int binarySearch(vector<int>arr, int key) {
//         int k=0, n=arr.size();
//         for(int i=n/2 ; i>=1 ; i/=2) {
//             while(i+k<n && arr[i+k]<=key) {
//                 k+=i;
//             }
//         }
        
//         return arr[k]==key ? k : -1;
//     }
    
//     vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
//         sort(aliceSizes.begin(),aliceSizes.end());
//         sort(bobSizes.begin(), bobSizes.end());
//         int sum1=0 , sum2=0, sumAvg=0;
//         for(auto x: aliceSizes) {
//             sum1+=x;
//         }
        
//         for(auto x: bobSizes) {
//             sum2+=x;
//         }
        
//         sumAvg = (sum1+sum2)/2;
//         int diff = sumAvg-sum1;
        
//         for(int i=0 ; i<aliceSizes.size() ; i++) {
//             int searchElement = aliceSizes[i] + diff;
//             int x = binarySearch(bobSizes, searchElement);
//             if(x==-1)
//                 continue;
//             return {aliceSizes[i], searchElement};
//         }
        
//         return {};
//     }
// };



class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        unordered_set<int> set;
        int sum1=0 , sum2=0, sumAvg=0;
        for(auto x: aliceSizes) {
            sum1+=x;
        }
        
        for(auto x: bobSizes) {
            sum2+=x;
            set.insert(x);
        }
        
        sumAvg = (sum1+sum2)/2;
        int diff = sumAvg-sum1;
        
        for(int i=0 ; i<aliceSizes.size() ; i++) {
            int searchElement = aliceSizes[i] + diff;
            if(set.find(searchElement)==set.end()) {
                continue;
            }
            return {aliceSizes[i], searchElement};
        }
        
        return {};
    }
};



// LEETCODE 888

// Alice and Bob have a different total number of candies. You are given two integer arrays aliceSizes and bobSizes where aliceSizes[i] is the number of candies of the ith box of candy that Alice has and bobSizes[j] is the number of candies of the jth box of candy that Bob has.

// Since they are friends, they would like to exchange one candy box each so that after the exchange, they both have the same total amount of candy. The total amount of candy a person has is the sum of the number of candies in each box they have.

// Return an integer array answer where answer[0] is the number of candies in the box that Alice must exchange, and answer[1] is the number of candies in the box that Bob must exchange. If there are multiple answers, you may return any one of them. It is guaranteed that at least one answer exists.



