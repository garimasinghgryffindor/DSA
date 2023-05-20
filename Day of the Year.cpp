class Solution {
public:
    
    bool findLeap(int year) {
        if(year%400 == 0)
            return true;
        if(year%100 == 0)
            return false;
        if(year%4 == 0)
            return true;
        return false;
    }
    
    int dayOfYear(string date) {
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        
        // finding whether year is leap year or not
        bool leap = findLeap(year);
        
        int ans = 0;
        
        vector<int>days{31,28,31,30,31,30,31,31,30,31,30,31};
        
        for(int i=0 ; i<month-1 ; i++) {
            ans+=days[i];
            if(i==1 && leap) {
                ans++;
            }
        }
        
        ans += day;
        
        return ans;
    }
};
