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


