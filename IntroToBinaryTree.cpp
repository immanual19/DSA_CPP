#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;

/*
 Non-linear data structure
 */
/*
 
 1. Node 0....infinity
 2. Every node has a single parent
 3. No cycle (Acyclic)
 
 */

/*
 Binary Tree
 1. At most 2 child
 2. Left and right child
 
 
 Application
 
 1. Binary Search Tree
 2. Heap/Priority Queue
 3. AVL Tree
 4. Red Black Tree
 5. Treap
 6. Splay Tree
 7. Segment Tree
 */

/*
 Graph
 
 1. node/vertex
 2. edge (connection between two nodes)
 3. Cycle (Cyclic)
 
 
 Application
 
 1. Shortest path
 
 */

/*
 Binary Tree variation
 
 1. Full Binary Tree (Every node has either 0 or 2 child)
 2. Complete Binary Tree (Every node has 2 child except (n-1)th level)
 3. Perfect Binary Tree (All levels are filled)
 
 */

/*
 Binary tree code
 
 1. Left node
 2. Right node
 3. Parent
 
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
    node* allnode[6];
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
    
    void print_tree_info(){
        for(int i=0;i<6;++i){
            int p=-1;
            int l=-1;
            int r=-1;
            if(allnode[i]->parent!=NULL){
                p=allnode[i]->parent->id;
            }
            if(allnode[i]->left!=NULL){
                l=allnode[i]->left->id;
            }
            if(allnode[i]->right!=NULL){
                r=allnode[i]->right->id;
            }
            cout<<"Node: "<<i<<endl;
            cout<<"Parent: "<<p<<endl;
            cout<<"Left: "<<l<<endl;
            cout<<"Right: "<<r<<endl;
        }
    }
};

int main(){
    
    BinaryTree bt;
    bt.build_binary_tree();
    bt.print_tree_info();
    return 0;
}
