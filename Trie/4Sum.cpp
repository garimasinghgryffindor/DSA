class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        set<vector<int>> st;
        vector<int> innerVector;
        vector <vector<int> >::iterator it;
        sort(nums.begin(),nums.end());
        
        int len = nums.size();
        
        for(int i=0 ; i<len-3 ; i++)
        {
            for(int l=i+1 ; l<len-2 ; l++)
            {
                int j = l+1;
                int k = len-1;
            
                while(j<k)
                {
                    int sum=nums[i];
                    
                    if((sum>0 && nums[l] > INT_MAX - sum) || (sum<0 && nums[l] < INT_MIN - sum))
                        break;
                    sum+=nums[l];
                    
                    if((sum>0 && nums[j] > INT_MAX - sum) || (sum<0 && nums[j] < INT_MIN - sum))
                        break;
                    sum+=nums[j];
                    
                    if((sum>0 && nums[k] > INT_MAX - sum) || (sum<0 && nums[k] < INT_MIN - sum))
                        break;
                    sum+=nums[k];
                    
                    if(sum==target)
                    {
                        innerVector.push_back(nums[i]);
                        innerVector.push_back(nums[l]);
                        innerVector.push_back(nums[j]);
                        innerVector.push_back(nums[k]);
                    
                        st.insert(innerVector);
                        innerVector.clear();
                        
                        j++;
                        k--;
                    }
                
                    else if(sum<target)
                    {
                        j++;
                    }
                
                    else
                    {
                        k--;
                    }
                }
            }
            
        }
        
        vector <vector<int> > res(st.begin(), st.end());
        
        return res;
    }
};
