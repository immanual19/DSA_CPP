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
    
    void build_binary_tree(){
        node* allnode[6];
        for(int i=0;i<6;++i){
            allnode[i]=CreateNewNode(i);
        }
        allnode[0]->left=allnode[1];
        allnode[0]->right=allnode[2];
        
        allnode[1]->left=allnode[5];
        allnode[1]->parent=allnode[0];
        
        allnode[2]->left=allnode[3];
        allnode[2]->right=allnode[4];
        allnode[2]->parent=allnode[0];
        
        allnode[5]->parent=allnode[1];
        
        allnode[3]->parent=allnode[2];
        allnode[2]->parent=allnode[2];
        root=allnode[0];
    }
    
    void BFS(){
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
    bt.build_binary_tree();
    bt.BFS();
    return 0;
}
