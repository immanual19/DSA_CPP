#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;
/*
 Binary Tree
 BFS (Breadth First Search)
 
 BFS uses a queue.
 
 insert root node to queue.
 queue={0}
 1st step=pop first child and insert {left child of 0=1, right child of 0=2}
 2nd step=pop first child and insert {right child of 0=2, left child of 1=3,right child of 1=4}
 3rd step=pop first child and insert {left child of 1=3, right child of 1=4, left child of 2=5}
 4th step=pop first child {right child of 1=4, left child of 2=5}
 5th step=pop first child {left child of 2=5}
 6th step=pop first child {}
 
 DFS (Depth First Search)
 =>Inorder
 =>Preorder
 =>Postorder
 */

class node{
public:
    int id;
    node* left;
    node* right;
    node* parent;
    
};

class BinaryTree{
public:
    node* root;
    
    BinaryTree(){
        root=NULL;
    }
    
    node* CreateNewNode(int id){
        node* newnode=new node;
        newnode->id=id;
        newnode->left=NULL;
        newnode->right=NULL;
        newnode->parent=NULL;
        
        return newnode;
    }
    
    void Insertion(int id){
        
        node* newnode=CreateNewNode(id);
        
        if(root==NULL){
            root=newnode;
            return;
        }
        queue<node*>q;
        q.push(root);
        while(!q.empty()){
            node* a=q.front();
            q.pop();
            if(a->left!=NULL){
                
                q.push(a->left);
            }
            else{
                a->left=newnode;
                newnode->parent=a;
                return;
            }
            if(a->right!=NULL){
                q.push(a->right);
            }
            else{
                a->right=newnode;
                newnode->parent=a;
                return;
            }
        }
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
                l=a->left->id;
                q.push(a->left);
            }
            if(a->right!=NULL){
                r=a->right->id;
                q.push(a->right);
            }
            
            if(a->parent!=NULL){
                p=a->parent->id;
            }
            cout<<"Node id = "<<a->id<<" Parent id = "<<p<<" Left child = "<<l<<" right child = "<<r<<endl;
        }
    }
};

int main(){
    
    BinaryTree bt;
    bt.Insertion(0);
    bt.Insertion(1);
    bt.Insertion(2);
    bt.Insertion(3);
    bt.Insertion(4);
    bt.Insertion(5);
    bt.BFS();
    return 0;
}
