/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

/*
    Time Complexity: O((n + q) * log(n))
    Space Complexity: O(n)
*/

long long numberOfSubarrays(long long i, long long j) {
   
    // Count the subarrays between the indices 'i' and 'j'.
    return (j - i - 1) * (j - i) / 2;
}
long long update(set<long long> &indices, long long i) {

    // Find the next and previous indices in the set 'indices'.
    long long high = (*indices.upper_bound(i));
    long long low = (*(--indices.lower_bound(i)));

    // Calculate the change required in the 'answer'.
    long long change = numberOfSubarrays(low, i) + numberOfSubarrays(i, high);
    change -= numberOfSubarrays(low, high);
    
    cout<<"low   : "<<low<<"      high. :  "<<high<<"     change :  "<<change<<endl;

    return change;
}


vector<long long> findScore(long long n, long long q, vector<long long> &v, vector<vector<long long>> &queries) {
    // Initialize the array of set 'indices' to store the indices for each number.
    set<long long> indices[n + 1];

    // Initialize an integer 'answer' equal to 'n * (n + 1) * (n + 1) / 2'.
    long long answer = (n * (n + 1) / 2) * (n + 1);
    
    cout<<"Answer originally:   "<< answer<<endl;

    // Store the indices for each element.
    for (int i = 0; i < n; i++) {
        indices[v[i]].insert(i);
    }

    // Calculate the initial answer.
    for (int i = 0; i <= n; i++) {
        indices[i].insert(-1);
        indices[i].insert(n);

        // Subtract the number of subarrays between the adjacent indices from the 'answer'.
        for (auto iterator = indices[i].begin();; iterator++) {
            auto nextIterator = iterator;
            nextIterator++;
            if (nextIterator == indices[i].end()) {
                break;
            }
            answer -= numberOfSubarrays(*iterator, *nextIterator);
        }
    }
    
    cout<<"Answer after:   "<< answer<<endl;

    // Initialize a vector 'answerVector' to store the answers for each query.
    vector<long long> answerVector;
    for (int count = 0; count < q; count++) {
        long long i = queries[count][0], x = queries[count][1];

        // Calculate the changes required in the answer.
        long long oldValue = update(indices[v[i]], i);
        long long newValue = update(indices[x], i);

        // Update the 'answer'.
        answer += oldValue - newValue;

        // Update the set of indices and the array accordingly.
        indices[v[i]].erase(i);
        v[i] = x;
        indices[v[i]].insert(i);

        // Store the current answer in the 'answerVector'.
        answerVector.push_back(answer);
    }
    return answerVector;
}

int main()
{
    long long n, q;
    cout<<"Enter n:  ";     cin>>n;
    cout<<"Enter q:  ";     cin>>q;
    vector<long long> v;
    vector<vector<long long>> queries;
    
    cout<<"enter elements:  ";
    for(int i = 0; i < n; i++) {
        long long x;
        cin>>x;
        v.push_back(x);
    }
    
    for(int i = 0; i < q; i++) {
        long long x, y;
        cin>>x>>y;
        queries.push_back({x,y});
    }
    
    vector<long long> ans = findScore(n,q,v,queries);
    
    for(int i = 0; i < q; i++) {
        cout<<ans[i]<<"   "; 
    }
    
    return 0;
}
