// SIMULATION 
// QUEUE

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int>res(n);
        deque<int>indices;
        
        sort(deck.begin(), deck.end());
        
        for(int i = 0; i < n; i++) {
            indices.push_back(i);
        }
        
        for(int i = 0; i < n; i++) {
            int newIndex = indices.front();     indices.pop_front();
            res[newIndex] = deck[i];
            
            if(!indices.empty()) {
                int tp = indices.front();   indices.pop_front();
                indices.push_back(tp);
            }
        }
        
        return res;
    }
};
