// USING SORTING
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>vec(heights.begin(), heights.end());
        sort(vec.begin(), vec.end());
        int res = 0;
        for(int i = 0; i < heights.size(); i++) {
            if(heights[i] != vec[i]) res++;
        }
        return res;
    }
};


// USING COUNTING SORT
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>vec;
        int res = 0;
        vector<int>freq(101, 0);
        for(int x: heights) {
            freq[x]++;
        }
        
        int count = 0;
        for(int i = 1; i <= 100; i++) {
            int f = freq[i];
            vector<int>temp(f, i);
            copy(temp.begin(), temp.end(), back_inserter(vec));
            count += f;
        }
        
        for(int i = 0; i < heights.size(); i++) {
            if(heights[i] != vec[i]) res++;
        }
        return res;
    }
};

