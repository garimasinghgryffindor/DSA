class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        unordered_map<int,int> types;
        int start = 0,i;
        for(i=0 ; i<fruits.size() ; i++) {
            types[fruits[i]]++;
            if(types.size()>2) {
                types[fruits[start]]--;
                if(types[fruits[start]]==0) {
                    types.erase(fruits[start]);
                }
                start++;
            }
        }
        
        return i-start;
    }
};


// LEETCODE 904


// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.

