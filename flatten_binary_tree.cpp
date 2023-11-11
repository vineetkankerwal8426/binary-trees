// Flatten Binary Tree to Linked List

// Given the root of a binary tree, flatten the tree into a "linked list":
// * The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// * The "linked list" should be in the same order as a pre-order traversal of the binary tree.


//recursive approach 
void flatten(TreeNode* root) {
        if(!root) return;
        if(root->left){  //check if root->left is not nullptr because if it is null then we dont have to swap left to right;
            TreeNode * temp = root->left;
            TreeNode * prev = root;
            while(temp){ 
                prev = temp;
                temp=temp->right;
            }
            prev->right = root->right;     //insert root->right to the most right of the root->left;
            root->right = root->left;      //swap root->left to root->right;
            root->left = nullptr;  //after inserting root->right to the most right of root->left and swaping root->left to right  make root->left null;
            }
        flatten(root->right);  //call again for the root->right because now root->left become null and all the nodes come to root->left;
    }


//iterative approach
void flatten(TreeNode* root){
        if(!root) return ;
        TreeNode * current = root;
        while(current){
            if(current->left){
                TreeNode * temp = current->left;
                while(temp->right){
                    temp = temp->right;
                }
                temp->right = current->right;
                current->right = current->left;
                current->left = nullptr;
            }
            current = current->right;
        }
    }