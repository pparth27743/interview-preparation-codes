#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int curr = 0;


TreeNode *preorder(vector<int> &pre, unordered_multimap<int, int> &mp, int l, int r){
    
    if(l > r) return NULL;

    TreeNode *root = new TreeNode(pre[curr++]);
    auto itr = mp.find(root->val);
    int index = itr->second;
    mp.erase(itr);
    root->left = preorder(pre, mp, l, index-1);
    root->right = preorder(pre, mp, index+1, r);

    return root;
}



TreeNode* buildTree(vector<int> &A, vector<int> &B) {

    unordered_multimap<int, int> mp;
    int n = A.size();
    curr = 0;
    
    for(int i=0; i<n; i++)
        mp.insert({B[i], i});

    return preorder(A, mp, 0, n-1);
}



int main(){

    int inorder[] = {2, 1, 3};
    int preorder[] = {1, 2, 3};

    vector<int> A(begin(inorder), end(inorder));
    vector<int> B(begin(preorder), end(preorder));
   
    TreeNode *root = buildTree(A, B);

    return 0;
}

