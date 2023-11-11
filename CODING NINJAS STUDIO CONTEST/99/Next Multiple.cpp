int nextMultiple(int n, int m) {
    if(n <= m) return m;
    int quot = n/m;
    return m*(quot+ 1);
}
