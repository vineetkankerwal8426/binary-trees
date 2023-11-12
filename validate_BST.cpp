// Validate Binary Search Tree
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

class Solution {
public:
    bool helper(TreeNode * root, long low,long high){  //we have to compare with int thats why we have taken long int for the edge cases of int 2^31
        if(root == nullptr) return true;
        if(  root->val<=low){  
            return false;
        }
        if(root->val>=high){
            return false;
        }
        bool left = helper(root->left,low,root->val);
        bool right = helper(root->right,root->val,high);
        return (left&&right);
    }

    bool isValidBST(TreeNode* root) { 
       return helper(root,LONG_MIN,LONG_MAX);  //call helper function and it will do all calculations
    }
};