#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;

int main(){
    /*
     Queue using array
     
     Operations
     
     1. front -> returns the first element in the queue O(1)
     2. enqueue -> insert an element to the queue O(1)
     3. dequeue -> deletes the first element of the queue O(1)
     4. size -> returns the size of queue O(1)

     */
    
    queue<int>q;
    q.push(5);
    q.push(10);
    q.push(15);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<"Queue size: "<<q.size()<<endl;
    
    return 0;
}
