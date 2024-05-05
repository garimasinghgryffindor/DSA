const int64_t mod = 1e9 + 7;
class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        
        int n = nums.size();
        int64_t max_a = *max_element(nums.begin(),nums.end());
        int64_t min_a = *min_element(nums.begin(),nums.end());
        int64_t sum = accumulate(nums.begin(),nums.end(),0LL);

        int64_t best_cost = 4e18;

        for( int64_t eq = max_a ; eq <= 2 * max_a ; eq++ ){

           int64_t total_increements = eq * n - sum;
           int64_t cost = 0;
           int64_t min_a_add = eq - min_a;

           // operations needed to make all others equal < operations needed to make min_a equal 
           // so min_a can't be paired then so needs cost1 operations
           
           if(  eq * (n-1) - (sum-min_a) <= (eq - min_a) ){
                int64_t extra = (1LL * eq - min_a) - (eq * (n-1) - ( sum - min_a ));
                cost += 1LL * extra * cost1;
                total_increements -= extra;
           }



            // if odd increements are left then use a cost1 operation
           if( total_increements & 1 ){
                total_increements -= 1;
                cost += cost1;
           }

           cost += min( total_increements * cost1 , (total_increements / 2) * cost2 );
           best_cost = min( best_cost , cost );

        }
        
        return best_cost%mod;
    }
};
