// Code Studio

#include <bits/stdc++.h> 
int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin() , positions.end());

	int minDist = 1;
	int maxDist = positions[n-1] - positions[0];
	
	int res=0;
	int low = minDist;
	int high = maxDist;
	while(low <= high){
		int mid = low + (high - low)/2;
		// if "i" is the minimum distance -> let us see how many chess players can be easily accomodated
		int prev = positions[0];
		int count = 1;
		for(int j=1 ; j<n ; j++) {
			if(positions[j] - prev >= mid) {
				// A ok
				count++;
				prev = positions[j];
				if(count == c) {
					res = max(res, mid);
					break;
				}
			}
		}

		if(count == c) {
			low = mid+1;
		}
		else if(count < c) {
			high = mid-1;
		} else {
			low = mid+1;
		}
	}

	return res;
}
