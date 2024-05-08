class Solution {
public:
    
    static bool compare(pair<int , int> a , pair<int , int> b)
    {
        return a.first > b.first;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        vector <pair <int , int> > vec;
        vector <string> res(score.size());
        
        for(int i=0 ; i<score.size() ; i++)
        {
            vec.push_back(make_pair(score[i] , i));
        }
        
        sort(vec.begin() , vec.end() , compare);
        
        for(int i=0 ; i<score.size() ; i++)
        {
            if(i==0)
            {
                res[vec[i].second] = "Gold Medal";
            }
            
            else if(i==1)
            {
                res[vec[i].second] = "Silver Medal";
            }
            
            else if(i==2)
            {
                res[vec[i].second] = "Bronze Medal";
            }
            
            else
            {
                res[vec[i].second] = to_string(i+1);
            }
        }
        
        return res;
    }
};
