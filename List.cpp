#include<bits/stdc++.h>
using namespace std;

void print(list<int>l){
    
    //O(n)
    
    list<int>::iterator it=l.begin();
    while(it!=l.end()){
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
}

void Insert(list<int>&l,int index,int val){
    auto it=l.begin(); //O(1)
    advance(it, index); //O(index)
    l.insert(it, val);
}

void Delete(list<int>&l, int index){
    auto it=l.begin();
    advance(it, index);
    l.erase(it);
}

int main(){
    
    list<int>l;
    
    //push_front O(1)
    
    l.push_front(10);
    l.push_front(20);
    l.push_front(30);
    
    print(l);
    
    l.push_back(40);
    l.push_back(50);
    
    print(l);
    
    l.pop_back();
    l.pop_back();
    
    print(l);
    
    l.pop_front();
    l.pop_front();
    
    print(l);
    
    l.push_back(200);
    l.push_back(300);
    
    auto it=l.begin();
    advance(it, 1);
    
    l.insert(it, 100);
    print(l);
    Insert(l,4,400);
    print(l);
    Delete(l,2);
    print(l);
    cout<<l.size()<<endl;
    return 0;
}
