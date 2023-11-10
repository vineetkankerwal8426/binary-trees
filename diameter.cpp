// Diameter of Binary Tree


class Solution {
public:
    int diameter(TreeNode * root,int &ans){  //calculate height of a tree
        if(root == nullptr) return 0;
        int left = diameter(root->left,ans);
        int right = diameter(root->right,ans);
        int a = left + right +1;
         ans = max(ans,a);           //diameter of a tree is left height+right height and we have to calculate max diameter
        return max(left,right)+1; 
    }

    int diameterOfBinaryTree(TreeNode* root) {
       int ans =0;  //initially diameter is zero 
        diameter(root,ans);
        return ans-1;      // it is calculating number of nodes instead of number of edges, that's why we substract 1;
    }
};