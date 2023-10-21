// MULTI SOURCE DFS TRAVERSAL
You are given a binary tree with n nodes, where each node in the tree contains a value. Your task is to find the maximum sum of the values of the nodes along the path from one node through one of its descendants (i.e., no two children of same node can be included in one path). However, this binary tree comes with a curse: you are not allowed to choose the left child or right child more than k times along the path from a parent to its child. In simpler terms, you can take at most k left steps and at most k right steps when selecting the path from a particular node.
int fun (Node* node, int l, int r){
    if(node==NULL)
    return 0;
    if(l==0 &&r==0)
    return node->data;
    int x = node->data;
    int y=x;
    if(l!=0)
    x+=fun(node->left,l-1,r);
    if(r!=0)
    y+=fun(node->right,l,r-1);
    return max(x,y);
}

void fun1(Node * node,int k,int &t){
    if(node==NULL)
    return;
    t=max(t,fun(node,k,k));
    fun1(node->left,k,t);
    fun1(node->right,k,t);
}

int maximumSum(int n, Node* root, int k) {
        // code here
        int t = 0;
        fun1(root,k,t);
        return t;
    }
