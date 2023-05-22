// CODE STUDIO

// Binary Search

#include <bits/stdc++.h> 

bool isPossible(vector<int>num,int n,long long mid) {
	int res = 1;
	long long sum=0;
	for(int i=0 ; i<num.size() ; i++) {
		if(sum + num[i] <= mid) {
			sum += num[i];
        } else if (num[i] > mid) {
			return false;
        } else {
            res++;
            sum = num[i];
        }
		// res++;
        if(res > n) {
			return false;
		}
	}

	return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	if(n > m) return -1;

	long long low = time[0], high = 0;

	for(int i=0 ; i<m ; i++) {
		if(time[i] < low) {
			low = time[i];
		}
		high += time[i];
	}

	// binary search

	while(low<=high) {
		// keep searching
		long long mid = low + (high-low)/2;

		if(isPossible(time,n,mid)) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return low;
}
