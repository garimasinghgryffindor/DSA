// Problem statement
// You are given a binary string ‘S’ of length ‘N’. The string is considered a crazy-bitstring if it either contains only ‘0s’ or only ‘1s’, or if the count of ‘1s’ and ‘0s’ is equal.

// You are also given an array ‘A’ of length ‘N’, where ‘A[i]’ represents the cost to remove the ‘ith’ character from the string.

// Your task is to determine the minimum cost required to transform the given string into a crazy-bitstring by removing any number of characters. and return it.

// Example:
// ‘N’ = 5
// ‘S’ = “00111”
// ‘A’ = [1, 0, 40, 5, 0]

// If you remove the ‘4th’ (0 - based indexing) character of the string, the string will get converted into a crazy bitstring. The cost will be equal to ‘0’. There is no other way to convert this string into a crazy bitstring with the cost less than or equal to ‘0’.
// Hence, the answer for this test case is ‘0’.



long long crazyBitstring(int n, string &s, vector <int> &a) {
   // Write your code here.
   long long res0 = 0, res1 = 0;
   // try using only 0's
   // find the cost of all 1's
   // try using only 1's 
   // find the cost of all 0's
   // keep count of all 0's and 1's
   // insert them in a priority queue

   priority_queue<int, vector<int>, greater<int> >pq0, pq1;
   // int n = s.length();

   for(int i = 0; i < n; i++) {
      if(s[i] == '0') {
         res1+=a[i];
         pq0.push(a[i]);
      } else if(s[i] == '1') {
         res0+=a[i];
         pq1.push(a[i]);
      }
   }

   if(pq1.size() == pq0.size()) return 0;

   long long res2 = 0;
   if(pq1.size() > pq0.size()) {
      while(pq1.size() > pq0.size()) {
         res2+=pq1.top();
         pq1.pop();
      }
   } else {
      while(pq0.size() > pq1.size()) {
         res2+=pq0.top();
         pq0.pop();
      }
   }

   return min({res1, res2, res0});
}
