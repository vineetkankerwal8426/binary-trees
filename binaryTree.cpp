#include<iostream>
using namespace std;

class node{
public:
    node * left;
    node * right;
    int value;
    node(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class binaryTree{
    node * root;
public:
    binaryTree(){
        root = nullptr;
    }
    void buildTree(){
        cout<<"enter the value of root node"<<endl;
        int value;  cin>>value;
        root = new node(value);
        buildTree(root);
    }
    void buildTree(node* root){
        cout<<"Do you want to enter left node of "<<root->value<<endl;
        bool left ; cin>>left;

        if(left){
            cout<<"enter the value of the left node of "<<root->value<<endl;
            int value; cin>>value;
            root->left = new node(value);
            buildTree(root->left);
        }
        cout<<"Do you want to enter right node of "<<root->value<<endl;
        bool right; cin>>right;
        if(right){
            cout<<"enter the value of the right node of "<<root->value<<endl;
            int value; cin>>value;
            root->right = new node(value);
            buildTree(root->right);
        }
        return;
    }
};