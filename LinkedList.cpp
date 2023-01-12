#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;

class Node{
public:
    int data;
    Node* next;
};

class LinkedList{
  
public:
    Node* head;
    
    LinkedList(){
        head=NULL;
    }
    //Creates a new node with data=value and next=NULL
    
    Node* createNewNode(int value){
        Node *newNode=new Node;
        newNode->data=value;
        newNode->next=NULL;
        
        return newNode;
        
    }
    
    // Insert new value at Head
    void insertAtHead(int value){
        Node *a=createNewNode(value);
        if(head==NULL){
            head=a;
            return;
        }
        //If head is not NULL
        a->next=head;
        head=a;
    }
    //Prints the Linked List
    void traverse(){
        Node* a=head;
        while(a!=NULL){
            cout<<a->data<<" ";
            a=a->next;
        }
        cout<<endl;
    }
    //Search for a single value
    int searchDistinctValue(int value){
        Node* a=head;
        int index=0;
        while(a!=NULL){
            if(a->data==value){
                return index;
            }
            a=a->next;
            index++;
        }
        return -1;
    }
    //Search all possible occurrence
    void searchAllValue(int value){
        Node* a=head;
        int index=0;
        while(a!=NULL){
            if(a->data==value){
                cout<<value<<" found at index "<<index<<endl;
            }
            a=a->next;
            index++;
        }
       
    }
    
};

int main(){
    
    /*
     1. Linear Data Structure
     2. Dynamic Daa Structure
     */
    
    /*
     1. Linked List structure
     2. Insertion at head
     3. Search for values
     */
    
    LinkedList l;
    
    l.insertAtHead(10);
    l.insertAtHead(20);
    l.insertAtHead(30);
    l.insertAtHead(30);
    l.traverse();
    cout<<"10 is found at index "<<l.searchDistinctValue(10)<<endl;
    cout<<"5 is found at index "<<l.searchDistinctValue(5)<<endl;
    l.searchAllValue(30);
    
    
    return 0;
}
