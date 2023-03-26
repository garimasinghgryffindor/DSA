// REC + MEM

class Solution {
public:
    string recur(vector<int>& cost,int target,unordered_map<int,string>&dp) {
        if(target < 0)
            return "0";
        if(target == 0)
            return "";
        if(dp.count(target) > 0) {
            return dp[target];
        }
        
        string curr,res="0";
        for(int i=1 ; i<=9 ; i++) {
            curr = recur(cost,target-cost[i-1],dp);
            if(curr == "0") {
                // leave it
                // cannot be solved 
                continue;
            }
            curr = to_string(i) + curr;
            if(res.length() <= curr.length()) {
                res = curr;
            }
        }
        
        dp[target] = res;
        return res;
    }
    
    string largestNumber(vector<int>& cost, int target) {
        unordered_map<int,string>dp;
        return recur(cost,target,dp);
    }
};




// TABULATION

class Solution {
public:
    string maxi(string a,string b){
        if(a.size()>b.size()){
            return a;
        }
        else if(a.size()<b.size()){
            return b;
        }
        else{
            if(a>b){
                return a;
            }
            return b;
        }
        return "";
    }
    string largestNumber(vector<int>& cost, int target) {
        unordered_map<int,map<int,string> > dp;
        for(int i=0;i<=target;i++){
            for(int j=0;j<=9;j++){
                if(i==0){
                    dp[i][j]="";
                }
                else if(j==0){
                    dp[i][j]="0";
                }
                else if(cost[j-1]<=i && dp[i-cost[j-1]][j]!="0"){
                    dp[i][j]=maxi(to_string(j)+dp[i-cost[j-1]][j],dp[i][j-1]);
                }
                else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[target][9];
    }
};

