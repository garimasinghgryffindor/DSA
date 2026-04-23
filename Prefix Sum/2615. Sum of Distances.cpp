class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long>res(n);
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for(auto iter: mp) {
            int x = iter.first;
            auto group = iter.second;
            long long sum = 0;
            for(int iter2: iter.second) {
                sum += iter2;
            }

            long long leftSum = 0;
            int groupsz = group.size();

            cout<<"num: "<<x<<endl;
            cout<<"sum: "<<sum<<endl;
            for(int i = 0; i < groupsz; i++) {
                long long rightSum = sum - leftSum - group[i];
                long long left = 1LL * group[i] * i - leftSum;
                long long right = rightSum - 1LL * group[i] * (groupsz - i - 1);
                cout<<left<<" <-L   R->"<<rightSum<<endl;
                res[group[i]] = left + rightSum;
                leftSum += group[i];
            } cout<<endl;
        }

        return res;
    }
};

// https://www.canva.com/design/DAHHsic_qnk/zrzvof9fpBhBWPOjUPs_gA/edit?ui=e30
