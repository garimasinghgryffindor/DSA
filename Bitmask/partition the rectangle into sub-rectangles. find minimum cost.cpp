Given a rectangle with dimensions N'M and an integer K. You divide this rectangle into smaller sub-rectangles such that the given conditions are satisfied:
• Sub-rectangles must be parallel to the axis of the larger rectangle with dimensions N'M.
• Every sub-rectangle has at least one edge on the larger rectangle edge. Informally, there is no sub-rectangle that is surrounded by other sub-rectangles.
For a sub-rectangle with area S, the cost of this sub-rectangle is (S - K)?.
Calculate the minimum total cost to divide the larger rectangle into smaller sub-rectangles.
Note: All sub-rectangles must have an integral length of dimensions.
Function description
Complete the solve function. This function takes the following 3 parameters and returns the required answer:
• N. Represents the value of N
• M. Represents the value of M
• K: Represents the value of K
Input format for custom testing
Note: Use this input format if you are testing against custom input or writing code in a language where we don't provide boilerplate code.
• The first line contains T, which represents the number of test cases.
• For each test case:
• The first line contains an integer N.
• The second line contains an integer M.
• The third line contains an integer K.
  

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, int k, string bitmask) {
    if(bitmask[0] == '0' && bitmask[1] == '0' && bitmask[2] == '0' && bitmask[3] == '0') return -1;
    int whole = pow((n*m - k), 2);
    if(n == 1 && m == 1) return whole;
    
    // trying partitions against columns
    for(int col = 1; col < m; col++) {
        string newbitmask = bitmask;
        string newbitmask2 = bitmask;
        newbitmask[2] = '0';
        int ans1 = solve(n, col, k, newbitmask);
        newbitmask2[0] = '0';
        int ans2 = solve(n, m-col, k, newbitmask2);
        
        if(ans1 == -1 || ans2 == -1) continue;
        
        whole = min(whole, ans1 + ans2);
    }
    
    // trying partitions against rows
    for(int row = 1; row < n; row++) {
        string newbitmask = bitmask;
        string newbitmask2 = bitmask;
        newbitmask[3] = '0';
        int ans1 = solve(row, m, k, newbitmask);
        newbitmask2[1] = '0';
        int ans2 = solve(n-row, m, k, newbitmask2);
        
        if(ans1 == -1 || ans2 == -1) continue;
        
        whole = min(whole, ans1 + ans2);
    }
    
    return whole;
}

int main()
{
    int n, m, k;
    n = 5, m = 5, k = 15;
    string bitmask = "1111";
    int res = solve(n, m, k, bitmask);
    cout<<res<<endl;
    return 0;
}



