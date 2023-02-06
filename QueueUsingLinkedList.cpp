#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;

//Queue using linked-list

class node{
public:
    int data;
    node* next;
};


class Queue{
public:
    node* head;
    node* tail;
    int sz;
    
    Queue(){
        head=NULL;
        tail=NULL;
        sz=0;
    }
    
    node* CreateNode(int val){
        node* newnode=new node;
        newnode->data=val;
        newnode->next=NULL;
        return newnode;
    }
    
    void enqueue(int val){
        sz++;
        node* newnode=CreateNode(val);
        if(head==NULL){
            head=newnode;
            tail=newnode;
            return;
        }
        tail->next=newnode;
        tail=newnode;
    }
    
    void dequeue(){
        if(sz==0){
            cout<<"Queue is empty."<<endl;
            return;
        }
        
        if(sz==1){
            
            delete head;
            head=NULL;
            tail=NULL;
            sz--;
            return;
        }
        node* a=head;
        head=head->next;
        sz--;
        delete a;
    }
    int front(){
        if(sz==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return head->data;
    }
    int size(){
        return sz;
    }
    
};


int main(){
    /*
     Queue using array
     
     Operations
     
     1. front -> returns the first element in the queue O(1)
     2. enqueue -> insert an element to the queue O(1)
     3. dequeue -> deletes the first element of the queue O(1)
     4. size -> returns the size of queue O(1)

     */
    
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    
    cout<<"Queue size: "<<q.size()<<endl;
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<"Queue size: "<<q.size()<<endl;
    
    return 0;
}
