vector<int> iterateTillZ(int x, int y, int z) {
    vector<int>res;
    for(int i = 1; i <= z; i++) {
        if(i%x == y) {
            res.push_back(i);
        }
    }
    return res;
}
