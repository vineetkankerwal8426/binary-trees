#include<iostream>
using namespace std;

class node{
public:
    int value;
    node * left;
    node * right;
    node(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST{
public:
    node * root;
    BST(){
        root = nullptr;
    }

    // iterative way to insert node in binary search tree
    void insert(int value){
        node * temp = root;
        node * prev = nullptr;
        
        while(temp!=nullptr){
            prev = temp;
            if(value==temp->value)
        {
            string msg="ERROR:Invalid insert!! This value already exist in BST.";
            throw msg;
        }
            else if (value<temp->value){
                temp= temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        if(temp ==root){
            root = new node(value);
            return;
        }
        else if(value<prev->value){
            prev->left = new node(value);
        }
        else{
            prev->right = new node(value);
        }
    }


    //recursive way to insert node in binary search tree
    void insertrecur(int value){
        root = insertrecur(root,value);
    }
    node * insertrecur(node * root,int value){
        if(root == nullptr){
            node * newNode = new node(value);
            return newNode ;
        }
        if(value<root->value){
            root->left = insertrecur(root->left,value);
        }
        else{
            root->right = insertrecur(root->right,value);
        }
        return root;
    }
};