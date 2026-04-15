class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int res = -1;
        int n = words.size();
        int right = startIndex;
        int left = startIndex;
        for(int i = 0; i < n; i++) {
            right = (startIndex+i)%n;
            left = (startIndex-i+n)%n;
            if(words[left] == target) {
                return i;
            }
            if(words[right] == target) {
                return i;
            }
        }
        return -1;
    }
};
