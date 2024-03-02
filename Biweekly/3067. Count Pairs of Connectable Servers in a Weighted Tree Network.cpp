class Solution {
public:
    void exploreNodes(int currentNode, int parent, int targetSum, int currentWeight, int &result, vector<vector<pair<int, int>>>& adjacencyList) {
        if (currentWeight % targetSum == 0) {
            result++;
        }
        for (pair<int, int> neighbor : adjacencyList[currentNode]) {
            if (neighbor.first == parent) {
                continue;
            }
            exploreNodes(neighbor.first, currentNode, targetSum, neighbor.second + currentWeight, result, adjacencyList);
        }
    }

    int calculatePairs(int currentNode, int targetSum, vector<vector<pair<int, int>>>& adjacencyList) {
        vector<int> subResults;
        int totalSum = 0;
        for (pair<int, int> neighbor : adjacencyList[currentNode]) {
            int result = 0;
            exploreNodes(neighbor.first, currentNode, targetSum, neighbor.second, result, adjacencyList);
            subResults.push_back(result);
            totalSum += result;
        }
        int finalResult = 0;
        for (auto &subResult : subResults) {
            totalSum -= subResult;
            finalResult += subResult * totalSum;
        }
        return finalResult;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int targetSum) {
        int numberOfNodes = edges.size() + 1;
        vector<vector<pair<int, int>>> adjacencyList(numberOfNodes + 1);
        for (auto edge : edges) {
            adjacencyList[edge[0]].push_back({edge[1], edge[2]});
            adjacencyList[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int> resultVector(numberOfNodes, 0);
        for (int i = 0; i < numberOfNodes; i++) {
            resultVector[i] += calculatePairs(i, targetSum, adjacencyList);
        }
        return resultVector;
    }
};
