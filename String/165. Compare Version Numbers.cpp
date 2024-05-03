// class Solution {
// public:
//     int compareVersion(string version1, string version2) {
//         int i = 0, j = 0;
//         int n = version1.length(), m = version2.length();
        
//         while(i < n || j < m) {
//             string temp = version1, temp2 = version2;
//             int x = i, y = j;
//             while(i < n && version1[i] != '.') {
//                 i++;
//             }
//             while(j < m && version2[j] != '.') {
//                 j++;
//             }
            
//             if(x < n) temp = temp.substr(x, i-x+1);
//             else temp = "0";
//             if(y < m) temp2 = temp2.substr(y, j-y+1);
//             else temp2 = "0";
//             int first = stoi(temp);
//             int second = stoi(temp2);
//             if(first > second) return 1;
//             if(second > first) return -1;
//             i++;
//             j++;
//         }
        
//         return 0;
//     }
// };



// BETTER SPACE COMPLEXITY
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n = version1.length(), m = version2.length();
        
        while(i < n || j < m) {
            int first = 0, second = 0;
       
            while(i < n && version1[i] != '.') {
                first = first*10 + (version1[i] - '0');
                i++;
            }
            while(j < m && version2[j] != '.') {
                second = second*10 + (version2[j] - '0');
                j++;
            }
            
            if(first > second) return 1;
            if(second > first) return -1;
            i++;
            j++;
        }
        
        return 0;
    }
};
