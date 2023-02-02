#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;

class Node{
  
public:
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList{
public:
    int sz;
    Node* head;
    DoublyLinkedList(){
        head=NULL;
        sz=0;
    }
    
    Node* CreateNewNode(int data){
        Node* newnode=new Node;
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=NULL;
        
        return newnode;
    }
    
    
    //Time Complexity O(1)
    
    void InsertAtHead(int data){
        sz++;
        Node* newnode=CreateNewNode(data);
        if(head==NULL){
            head=newnode;
            return;
        }
        Node* a=head;
        newnode->next=a;
        a->prev=newnode;
        head=newnode;
    }
    
    void Insert(int index, int data){
        
        if(index>sz){
            return;
        }
        
        if(index==0){
            InsertAtHead(data);
            return;
        }
        Node* a=head;
        int cur_index=0;
        while(cur_index!=index-1){
            a=a->next;
            cur_index++;
        }
        Node* newnode=CreateNewNode(data);
        newnode->next=a->next;
        newnode->prev=a;
        Node* b=a->next;
        b->prev=newnode;
        a->next=newnode;
        sz++;
    }
    
    void Traverse(){
        Node* a=head;
        while(a!=NULL){
            cout<<a->data<<" ";
            a=a->next;
        }
        cout<<endl;
    }
    
    int GetSize(){
        
        return sz;
    }
    void DeleteAtHead(){
        if(head==NULL){
            return;
        }
        sz--;
        Node* a=head;
        Node* b=head->next;
        delete a;
        if(b!=NULL){
            b->prev=NULL;
        }
        head=b;
    }
    
};

class Stack{
  
public:
    DoublyLinkedList dl;
    Stack(){
        
    }
    int top(){
        if(dl.GetSize()==0){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return dl.head->data;
    }
    void push(int val){
        dl.InsertAtHead(val);
    }
    void pop(){
        if(dl.GetSize()==0){
            cout<<"Stack is empty"<<endl;
            return;
        }
        dl.DeleteAtHead();
        
    }
    
};

int main(){
    
    Stack st;
    st.push(3);
    cout<<st.top()<<endl;
    st.push(4);
    cout<<st.top()<<endl;
    st.push(5);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    return 0;
}

