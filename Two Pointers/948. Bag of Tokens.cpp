class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0 , temp=0 , f=0;
        
        sort(tokens.begin() , tokens.end());
        int i=0 , j=tokens.size()-1;
        
        while(i<=j){
            if(temp>0 && i!=j){
                if(tokens[j]>power && f)
                {
                    power+=tokens[j];
                    temp--;
                    j--;
                }
            }
            
            if(tokens[i]<=power){
                power-=tokens[i];
                temp++;
                score=max(score , temp);
                if(i+1<tokens.size() && tokens[i+1]>power){
                    f=1;
                } else {
                    f=0;
                }
            }
            i++;
        }
        
        return score;
    }
};


