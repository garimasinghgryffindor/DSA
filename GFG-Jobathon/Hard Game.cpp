Geek is playing a game with N levels. Each level, denoted as the ith level, requires energyArr|i] energy to complete. Geek begins with K energy and can rest at levels that require zero energy to regain K energy. When at level i, they can move to level it1 only after expending energyArril energy.
Geek possesses a power-up that allows them to start the game from any level, but it can be used only once.
Find the level number from which to start in order to guarantee a win. If multiple such levels are possible, return the largest level number. If there is no level that ensures victory, return -1.

class Solution {
  public:
    int powerup(int N, int K, vector<int> &arr) {

        long long energy = K;
        for(int i = N-1; i >= 0; i--) {
            if(arr[i] == 0) {
                energy += K;
            }
            if(energy - arr[i] >= 0) return i;
            else energy -= arr[i];
        }
        return -1;
    }
};
