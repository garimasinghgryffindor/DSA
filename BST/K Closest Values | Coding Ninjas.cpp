// Approach 1
void inorder(TreeNode<int>* root, vector<int>&arr) {
    if(!root) return;

    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

vector<int> kClosestValues(TreeNode<int> *root, double target, int k) {
    // Write your code here.
    vector<int>sorted;
    // here i will get the elements in ascending order

    inorder(root, sorted);
    // cout<<sorted.size()<<endl;
    // now we can use two-pointer approach to find k closest elements in this sorted array

    int left = 0, right = sorted.size()-1;

    while(right - left + 1 > k) {
        if(abs((double)sorted[left] - target) > abs((double)sorted[right] - target)) {
            left++;
        } else {
            right--;
        }
    }
    // cout<<"left: "<<left<<"    right : "<<right<<endl;
    vector<int>res(sorted.begin()+left, sorted.begin()+right+1);

    return res;
}


// Approach 2
