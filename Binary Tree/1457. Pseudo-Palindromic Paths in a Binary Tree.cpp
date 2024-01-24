class Solution {
public:
    vector<int> path; // keep track of paths
    int count; // output variable
    int arr[10]; // array keeping freq of occurance of indices
    
    void checkPalindrome(){
        
        int c  = 0;
        for(int i=1; i<10; ++i){
            if(arr[i]&1) c++; // if odd, increment count
        }
        
        if(c<=1){ // palindrome is possible
            count++;
        }
    }
    
     void dfs(TreeNode* node){
    if(!node) 
        return;
        
        if(node->left==NULL && node->right==NULL){// possible path
           
            path.emplace_back(node->val); // add node to path
            arr[node->val]++; // increment the freq of that node val
			
            checkPalindrome(); // check if palindrome
			
            arr[path.back()]--; // decrease freq as back element will be popped
            path.pop_back(); // pop leaf node
            return;
            
        }
        
        // if not leaf node
        path.emplace_back(node->val);
        arr[node->val]++;
        
        // traverse sub graph
        dfs(node->left);
        dfs(node->right);
        
        // going to parent, so pop last element in path
        arr[path.back()]--;
        path.pop_back();
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        count = 0;
        memset(arr, 0, sizeof(arr));
        dfs(root);
        
        return count;
    }
};
