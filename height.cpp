#include<iostream>
#include<queue>
using namespace std;

// recursive approach to find height of a tree 

int height(TreeNode * root){
    if(root == nullptr){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left,right)+1;
    return ans;
}

// iterative approach to find height of a tree 
// making level order traversal approach

int height(TreeNode * root){
    queue<TreeNode *> q;
    q.push(root);
    int h =0;
    TreeNode * temp;
    while(true){
        int c = q.size();
        if(c==0){
            return h;
        }
        h+=1;
        while(c>0){
            temp = q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            c--;
        }
    }
}