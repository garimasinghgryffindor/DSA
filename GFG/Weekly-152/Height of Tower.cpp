// User function Template for C++

class Solution {
  public:
    int HeightTower(int n, int k, vector<int>& a) {
        // code here
        stack<int> s;
        int j=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            s.push(a[i]);
            if(sum>k)
            {
                j=j+1;
                int temp=j;
                while(!s.empty()&&temp)
                {
                    sum-=s.top();
                    s.pop();
                    temp--;
                }
                if(s.empty())sum=0;
            }
        }
        return sum;
    }
};
