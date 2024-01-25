// Problem statement
// You are given an array 'A' with 'N' integers. It is guaranteed that 'N' is even.

// Let's define the score of the array 'A' as the sum of the minimum element among the first 'N / 2' elements and the minimum element among the last 'N / 2' elements of the array.

// You are required to find the maximum score of the array 'A' that can be achieved after rearranging the elements of 'A' in any order.

// Example:
// N = 6
// A = [1, 2, 5, 1, 4, 8]
// We can rearrange the elements such that 'A' is ['1', '2', '1', '8', '4', '5']. The minimum element among the first 'N / 2' elements is '1', and among the last 'N / 2' elements is '4'. So the score of the array 'A' is '1 + 4' = '5'.
// It can be proved that we can not achieve a score greater than '5'.
// So the answer for this case is '5'.

  
int maximumScore(int n, vector<int> v) {
    // Write your code here.
    sort(v.begin(), v.end());
    return v[0] + *(v.begin()+n/2);
}
