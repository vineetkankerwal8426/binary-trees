// 124. Binary Tree Maximum Path Sum

// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
// A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any non-empty path.


class Solution {
public:
    int ans = INT_MIN;

    //helper fuction that will update our ans;
    int helper(TreeNode * root){
        if(root == nullptr){
            return 0;
        }
        int left = helper(root->left);  //calculate the sum of left 
        int right = helper(root ->right);  //calculate the sum of right 
        left = max(0,left);  //check if there is negative value, if yes make it 0;
        right = max(0,right);
        int pathsum = left + right + root->val;  //sum of that path will left + right + value of that particular node;
        ans = max(ans,pathsum);  // if that path sum is greater than ans update accordingly
        return max(left,right)+root->val;  // return value should be of only one path, thats why take max of left and right, add root->val and then return it
    } 
    //main function that will execute first
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};