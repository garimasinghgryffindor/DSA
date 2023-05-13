Subset Sum : Sum of all Subsets (Recursion)

Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.


void recur(vector<int>num,vector<int>&res,int i,int sum) {
    if(i==num.size()){
        res.push_back(sum);
        return;
    }

    recur(num,res,i+1,sum);
    recur(num,res,i+1,sum+num[i]);
}

vector<int> subsetSum(vector<int> &num)
{
    // using recursion
    vector<int> res;
    recur(num,res,0,0);

    sort(res.begin(),res.end());

    return res;
}

