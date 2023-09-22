
vector<int> firstNegative(vector<int> arr, int n, int k) {
	vector<int>res;
	list<int> ls;
	int l = 0, r = 0;
	while(r < n) {
		if(arr[r] < 0) {
			ls.push_back(arr[r]);
		}
		if(r-l+1 == k) {
			if(ls.empty()) res.push_back(0);
			else {
				res.push_back(ls.front());
				if(arr[l] == ls.front()) {
					ls.pop_front();
				}
			}
			l++;
			r++;
		} else {
			r++;
		}
	}
	return res;
}
