#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;

/*
 Binary Search Tree is a data structure
 based on Binary Tree.
 
 -> left subtree less or equal
 -> right subtree greater or equal
 
 */
/*
 
 BST Insertion Theory
 1,5,4,3,6,7
 */

/*
 Search a value in BST
 
 */

class node{
public:
    int value;
    node* left;
    node* right;
};

class BST{
public:
    node* root;
    BST(){
        root=NULL;
    }
    
    node* CreateNewNode(int value){
        node* newnode=new node;
        newnode->value=value;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    
    void BFS(){
        if(root==NULL){
            return;
        }
            queue<node*>q;
            q.push(root);
            while(!q.empty()){
                node* a=q.front();
                q.pop();
                int p=-1,l=-1,r=-1;
                if(a->left!=NULL){
                    l=a->left->value;
                    q.push(a->left);
                }
                if(a->right!=NULL){
                    r=a->right->value;
                    q.push(a->right);
                }
                
                cout<<"Node value = "<<a->value<<" Left child = "<<l<<" right child = "<<r<<endl;
            }
    }
    
    void Insert(int value){
        node* a=CreateNewNode(value);
        if(root==NULL){
            root=a;
            return;
        }
        node* cur=root;
        node* prv=NULL;
        
        while(cur!=NULL){
            if(a->value>cur->value){
                prv=cur;
                cur=cur->right;
            }
            else{
                prv=cur;
                cur=cur->left;
            }
        }
        if(a->value>prv->value){
            prv->right=a;
        }
        else{
            prv->left=a;
        }
    }
    
    bool Search(int value){
        node* cur=root;
        while(cur!=NULL){
            if(value>cur->value){
                cur=cur->right;
            }
            else if(value<cur->value){
                cur=cur->left;
            }
            else{
                return true;
            }
        }
        return false;
    }
    
};

int main(){
    
    BST bst;
    
    bst.Insert(6);
    bst.Insert(4);
    bst.Insert(3);
    bst.Insert(5);
    bst.Insert(7);
    bst.Insert(8);
    
    bst.BFS();
    
    cout<<bst.Search(7)<<endl;
    cout<<bst.Search(17)<<endl;
    
    return 0;
}

