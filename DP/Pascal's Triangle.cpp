class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> vec;
        
        for(int i=0 ; i<numRows ; i++) {
            if(i==0) {
                vec.push_back({1});
            } 
            else {
                vector<int> curr;
                curr.push_back(1);
                for(int j=0 ; j<i-1 ; j++) {
                    curr.push_back(vec[i-1][j]+vec[i-1][j+1]);
                }
                curr.push_back(1);
                
                vec.push_back(curr);
            }
        }
        
        return vec;
    }
};
