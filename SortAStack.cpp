#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;
template <class T>
class Node{
  
public:
    T data;
    Node* next;
    Node* prev;
};

template <class T>

class DoublyLinkedList{
public:
    int sz;
    Node<T>* head;
    DoublyLinkedList(){
        head=NULL;
        sz=0;
    }
    
    Node<T>* CreateNewNode(T data){
        Node<T>* newnode=new Node<T>;
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=NULL;
        return newnode;
    }
    
    
    //Time Complexity O(1)
    
    void InsertAtHead(T data){
        sz++;
        Node<T>* newnode=CreateNewNode(data);
        if(head==NULL){
            head=newnode;
            return;
        }
        Node<T>* a=head;
        newnode->next=a;
        a->prev=newnode;
        head=newnode;
    }
    
    int GetSize(){
        
        return sz;
    }
    void DeleteAtHead(){
        if(head==NULL){
            return;
        }
        sz--;
        Node<T>* a=head;
        Node<T>* b=head->next;
        delete a;
        if(b!=NULL){
            b->prev=NULL;
        }
        head=b;
    }
    
};
template<class T>
class Stack{
  
public:
    DoublyLinkedList<T> dl;
    Stack(){
        
    }
    T top(){
        if(dl.GetSize()==0){
            cout<<"Stack is empty"<<endl;
            T a;
            return a;
        }
        return dl.head->data;
    }
    void push(T val){
        dl.InsertAtHead(val);
    }
    void pop(){
        if(dl.GetSize()==0){
            cout<<"Stack is empty"<<endl;
            return;
        }
        dl.DeleteAtHead();
        
    }
    int getSize(){
        return dl.GetSize();
    }
};

int main(){
    
    Stack<int> st;
    Stack<int>tmp;
    
    st.push(5);
    st.push(2);
    st.push(7);
    st.push(8);
    st.push(3);
    while(st.getSize()>0){
        int t=st.top();
        st.pop();
        while(tmp.getSize()>0){
            if(tmp.top()<t){
                break;
            }
            st.push(tmp.top());
            tmp.pop();
        }
        tmp.push(t);
    }
    swap(st,tmp);
    
    while(st.getSize()>0){
        cout<<st.top()<<endl;
        st.pop();
    }
    
    return 0;
}
