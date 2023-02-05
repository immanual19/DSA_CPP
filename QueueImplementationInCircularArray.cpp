#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;

const int MAX_SIZE=500;



class Queue{
public:
    int a[MAX_SIZE];
    int l,r;
    int sz;
    Queue(){
        l=0;
        r=-1;
        sz=0;
        /*
         l>r, Queue is empty
         size=r-l+1
        */
    }
    void enqueue(int val){
        if(sz==MAX_SIZE){
            cout<<"Queue is full."<<endl;
            return;
        }
        r++;
        if(r==MAX_SIZE){
            r=0;
        }
        a[r]=val;
        sz++;
    }
    void dequeue(){
        if(sz==0){
            cout<<"Queue is empty."<<endl;
            return;
        }
        l++;
        if(l==MAX_SIZE){
            l=0;
        }
        sz--;
    }
    int front(){
        if(sz==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return a[l];
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
    q.enqueue(6);
    q.enqueue(7);
    
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
