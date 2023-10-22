int minimumSum(vector<int>& arr) {
    int n = arr.size();

    if (n < 3) {
        return -1; // Not enough elements to form a triplet
    }

    vector<int> leftMin(n);
    vector<int> rightMin(n);

    leftMin[0] = INT_MAX;
    for (int i = 1; i < n; i++) {
        leftMin[i] = min(leftMin[i - 1], arr[i - 1]);
    }

    rightMin[n - 1] = INT_MAX;
    for (int i = n - 2; i >= 0; i--) {
        rightMin[i] = min(rightMin[i + 1], arr[i + 1]);
    }

    int minSum = INT_MAX;

    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > leftMin[i] && arr[i] > rightMin[i]) {
            minSum = min(minSum, leftMin[i] + arr[i] + rightMin[i]);
        }
    }

    if (minSum == INT_MAX) {
        return -1; // No mountain triplet found
    }

    return minSum;
}


