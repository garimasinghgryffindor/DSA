class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int maxFreq=0;
        vector<int> count(10001, 0);
        for(int i=0 ; i<barcodes.size() ; i++) {
            count[barcodes[i]]++;
            if(count[barcodes[i]] > count[maxFreq]) {
                maxFreq = barcodes[i];
            }
        }
        
        int i=0 ;
        while(count[maxFreq]) {
            barcodes[i] = maxFreq;
            count[maxFreq]--;
            i+=2;
        }
        
        for(int j=1 ; j<10001 ; j++) {
            while(count[j]) {
                if(i>=barcodes.size()) i=1;
                barcodes[i] = j;
                i+=2;
                count[j]--;
            }
        }
        
        return barcodes;
    }
};


// LEETCODE 1054

// In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].

// Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.



