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
    int sz;
    LinkedList(){
        head=NULL;
        sz=0;
    }
    //Creates a new node with data=value and next=NULL
    
    Node* CreateNewNode(int value){
        Node *newNode=new Node;
        newNode->data=value;
        newNode->next=NULL;
        
        return newNode;
        
    }
    
    // Insert new value at Head
    void InsertAtHead(int value){
        sz++;
        Node *a=CreateNewNode(value);
        if(head==NULL){
            head=a;
            return;
        }
        //If head is not NULL
        a->next=head;
        head=a;
    }
    //Prints the Linked List
    void Traverse(){
        Node* a=head;
        while(a!=NULL){
            cout<<a->data<<" ";
            a=a->next;
        }
        cout<<endl;
    }
    //Search for a single value
    int SearchDistinctValue(int value){
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
    void SearchAllValue(int value){
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
    
    int GetSize(){
        
//        Time Complexity O(n)
//
//        int sz=0;
//        Node *a=head;
//        while(a!=NULL){
//            sz++;
//            a=a->next;
//        }
//        return sz;
        return sz;
    }
    
    void InsertAtAnyIndex(int index,int value){
        if(index<0 || index>sz){
            return;
        }
        if(index==0){
            InsertAtHead(value);
            return;
        }
        sz++;
        Node* a=head;
        int cur_index=0;
        while(cur_index!=index-1){
            a=a->next;
            cur_index++;
        }
        Node* newNode=CreateNewNode(value);
        newNode->next=a->next;
        a->next=newNode;
    }
    
    void DeleteAtHead(){
        if(head==NULL){
            return;
        }
        sz--;
        Node *a=head;
        head=a->next;
        delete a;
    }
    
    void DeleteAnyIndex(int index){
        
        if(index<0 || index>sz-1){
            return;
        }
        
        if(index==0){
            DeleteAtHead();
            return;
        }
        sz--;
        Node* a=head;
        int cur_index=0;
        while(cur_index!=index-1){
            a=a->next;
            cur_index++;
        }
        Node* b=a->next;
        a->next=b->next;
        delete b;
    }
    
};

int main(){
    
    /*
     1. Linear Data Structure
     2. Dynamic Data Structure
     */
    
    /*
     1. Linked List structure
     2. Insertion at head
     3. Search for values
     */
    
    LinkedList l;
    
    l.InsertAtHead(10);
    l.InsertAtHead(20);
    l.InsertAtHead(30);
    l.InsertAtHead(30);
    l.Traverse();
    cout<<"10 is found at index "<<l.SearchDistinctValue(10)<<endl;
    cout<<"5 is found at index "<<l.SearchDistinctValue(5)<<endl;
    l.SearchAllValue(30);
    cout<<l.GetSize()<<endl;
    l.InsertAtAnyIndex(1, 100);
    l.Traverse();
    cout<<l.GetSize()<<endl;
    l.DeleteAtHead();
    l.Traverse();
    cout<<l.GetSize()<<endl;
    l.DeleteAnyIndex(2);
    l.Traverse();
    return 0;
}
