// Lowest Common Ancestor of a Binary Tree

// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined 
// between two nodes p and q as the lowest node in T that has both p and q as descendants 
// (where we allow a node to be a descendant of itself).”


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root == p or root == q) return root;  //if we found any of the p or q node return that node;
        TreeNode * l = lowestCommonAncestor(root->left, p,q);   //check in the left subtree
        TreeNode * r = lowestCommonAncestor(root->right, p,q);  //check in the right subtree
        if(l!=nullptr and r!=nullptr) return root;   //if both nodes are present - one is in left subtree and one is on right subtree return that node because that node is common ancestor
        return l == nullptr? r:l;   //conditional operator- return  'r' if l == nullptr else return 'l'
    }
};