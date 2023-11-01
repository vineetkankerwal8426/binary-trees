#include<iostream>
using namespace std;

class node{
public:
    int value;
    node * left ;
    node * right;
    node(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class AVL{
public:
    node * root;
    AVL(){
        root = nullptr;
    }

    node * insert(node * root, int value){  //insert it normally like a binary search tree
        if(root == nullptr) {
            node * newNode = new node(value);
            return newNode;
        }
        else if (value<root->value){
            root->left = insert(root->left,value);
        }
        else {
            root->right =  insert(root->right,value);
        }
        return rotate(root);  //after inserting check whether the tree is unbalanced or not from that every particular node in bottom to up manner
    }

    node * rotate(node *root){
        if(height(root->left)-height(root->right) >1){
            if(height(root->left->left)-height(root->left->right) >0){
                //left left case
                return rightRotate(root);
            }
            else{
                //left right case
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        else if(height(root->left)-height(root->right) <-1){
            if(height(root->right->right)-height(root->right->left) >0){
                //right right case
                return leftRotate(root);
            }
            else{
                // right left case
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
    }
    node * rightRotate(node * root){
        node * child = root->left;
        node * childRight = child->right;
        child->right = root;
        root->left = childRight;
        return child;
    }
    
    node * leftRotate(node * root){
        node * child = root->right;
        node * childLeft = child->left;
        child->left = root;
        root->right = childLeft;
        return child;
    }

    int height(node * root){
        if(root== nullptr) return 0;
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left,right)+1;
        return ans;
    }
};