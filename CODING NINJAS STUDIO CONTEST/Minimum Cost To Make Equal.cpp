int makeStringsEqual(int n, int a, int b, string& s, string& t) {
    // Write your code here.
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == t[i]) continue;
        int temp = 0;
        temp = abs(s[i]-t[i]);
        int temp2 = 0;
        temp2 = s[i]-'a' + b + 'z'-t[i];
        int temp3 = 0;
        temp3 = 'z'-s[i] + a + t[i]-'a';
        res += min({temp, temp2, temp3});
    }
    return res;
}
