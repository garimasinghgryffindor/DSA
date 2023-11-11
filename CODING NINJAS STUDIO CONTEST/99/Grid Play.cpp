vector<int> canBeHappy(int n, int m, int q, vector<vector<int>> &v, vector<vector<int>> &queries) {

  // Initialize a 2-dimensional vector of integers 'count' to store the prefix sum.
  vector<vector<int>> count(n, vector<int>(m));
  for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {

          // Set 'count[i][j]' to the number of good cells in the rectangle with the top-left corner as ('0', '0') and the bottom-right corner as ('i', 'j').
          count[i][j] = count[i - 1][j] + count[i][j - 1] - count[i - 1][j - 1];
          if (v[i][j - 1] % 2 != v[i - 1][j] % 2) {
              count[i][j]++;
          }
      }
  }

  // Initialize vector of integers 'answer' to store the answer for each query.
  vector<int> answer;
  for (int i = 0; i < q; i++) {

      // Initialize the integers 'w', 'x', 'y' and 'z' to 'queries[i][0]', 'queries[i][1]', 'queries[i][2]' and 'queries[i][3]', respectively.
      int w = queries[i][0], x = queries[i][1], y = queries[i][2], z = queries[i][3];

      // Initialize an integer 'goodCell' to store the number of good cells in the given subrectangle.
      int goodCell = count[y][z] - count[y][x] - count[w][z] + count[w][x];

      // Calculate and store the answer of the 'i-th' query.
      if (goodCell > 0) {
          answer.push_back(1);
      }
      else {
          answer.push_back(0);
      }
  }

  // Return the calculated 'answer'.
  return answer;
}







