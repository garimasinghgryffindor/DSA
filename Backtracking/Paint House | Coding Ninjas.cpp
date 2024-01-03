#include<bits/stdc++.h>

// MEMOIZATION
int recur(vector<vector<int>>&cost, int idx, int prevColor,vector<vector<int>>&memz) {
	if(idx == cost.size()) {return 0;}
	if(memz[idx][prevColor+1] != -1) return memz[idx][prevColor+1];
	// try coloring with all the possible colors
	// except for the previously used color

	int costHere = INT_MAX;
	for(int i = 0; i < 3; i++) {
		if(i != prevColor) {
			costHere = min(costHere, cost[idx][i] + recur(cost, idx+1, i, memz));
		}
	}

	return memz[idx][prevColor+1] = costHere;
}



// TABULATION
int minCost(vector<vector<int>> &cost)
{
	vector<vector<int>> memz(cost.size()+1, vector<int>(4, -1));
	// int res = recur(cost, 0 , -1, memz);

	for(int i = 0; i <= 3; i++) {
		memz[cost.size()][i] = 0;
	}

	for(int i = cost.size()-1; i >= 0; i--) {
		for(int prevColor = 0; prevColor <= 2; prevColor++) {
			int costHere = INT_MAX;
			for(int k = 0; k < 3; k++) {
				if(k != prevColor) {
					costHere = min(costHere, cost[i][k] + memz[i+1][k]);
				}
			}

			memz[i][prevColor] = costHere;
		}
	}

	return min({memz[0][0], memz[0][1], memz[0][2]});
}



