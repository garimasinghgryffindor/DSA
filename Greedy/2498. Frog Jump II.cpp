Claim 1: It is optimal that we make use of all rocks: There is never a benefit of not including a rock in Path 1 or Path 2, it is always positive or neutral.
Claim 2: It is never optimal to choose two consecutive rocks: If we choose rock_i, and rock_i+1, then rock_i+2 will have to do (rock_i+2)-(rock_i) work to return. Because the array is strictly increasing, it holds that (rock_i+2)-(rock_i) > (rock_i+1-rock_i)
Therefore one path must lie on each even index and the other path must lie on each odd index. We iterate through them and find the maximum distance.

  
  
class Solution {
public:
    int maxJump(vector<int>& stones) {
        int res = stones[1] - stones[0];
        
        // odd path
        for(int i=3 ; i<stones.size() ; i+=2) {
            res = max(res, stones[i]-stones[i-2]);
        }
        
        // even path
        for(int i=2 ; i<stones.size() ; i+=2) {
            res = max(res, stones[i]-stones[i-2]);
        }
        
        return res;
    }
};


You are given a 0-indexed integer array stones sorted in strictly increasing order representing the positions of stones in a river.

A frog, initially on the first stone, wants to travel to the last stone and then return to the first stone. However, it can jump to any stone at most once.

The length of a jump is the absolute difference between the position of the stone the frog is currently on and the position of the stone to which the frog jumps.

More formally, if the frog is at stones[i] and is jumping to stones[j], the length of the jump is |stones[i] - stones[j]|.
The cost of a path is the maximum length of a jump among all jumps in the path.

Return the minimum cost of a path for the frog.
