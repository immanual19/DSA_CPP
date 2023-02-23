#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;

/*
 Insert(x) O(log n)
 Max/Min O(1)
 Delete(index) O(log n)
 */

/*
 Heap is a Complete Binary Tree
 
 Every level is field up except last level
 
 Max Heap for finding max value in O(1)
 Min Heap for finding min value in O(1)
 
 */

/*
 Max Heap properties:
 
 Value will be decrease while level increases
 
 Min Heap properties:
 
 Value will be increase while level increases
 */
/*
 
 Insertion
 up_heapify
 
 */

class MaxHeap{
public:
    vector<int>nodes;
    MaxHeap(){
        
    }
    
    //O(log n)
    
    void up_heapify(int idx){
        /*
         (idx-1)/2 is the parent node of the current node we are in
         */
        while(idx>0 && nodes[idx]>nodes[(idx-1)/2]){
            swap(nodes[idx],nodes[(idx-1)/2]);
            idx=(idx-1)/2;
        }
    }
    
    //O(log n)
    
    void insert(int x){
        nodes.push_back(x);
        up_heapify(nodes.size()-1);
    }
    
    //O(n)
    
    void printHeap(){
        for(int i=0;i<nodes.size();++i){
            cout<<nodes[i]<<" ";
        }
        cout<<endl;
    }
    
    void down_heapify(int idx){
        while(true){
            int largest=idx;
            int l=2*idx+1;
            int r=2*idx+2;
            if(l<nodes.size() && nodes[largest]<nodes[l]){
                largest=l;
            }
            if(r<nodes.size() && nodes[largest]<nodes[r]){
                largest=r;
            }
            if(largest==idx){
                break;
            }
            swap(nodes[idx],nodes[largest]);
            idx=largest;
        }
    }
    
    //O(log n)
    
    void Delete(int idx){
        if(idx>=nodes.size()){
            return;
        }
        swap(nodes[idx],nodes[nodes.size()-1]);
        nodes.pop_back();
        down_heapify(idx);
    }
    
    //O(1)
    
    int getMax(){
        if(nodes.empty()){
            cout<<"Heap is empty."<<endl;
            return -1;
        }
        return nodes[0];
    }
    
    //O(log n)
    
    int extractMax(){
        if(nodes.empty()){
            cout<<"Heap is empty."<<endl;
            return -1;
        }
        int ret=nodes[0];
        Delete(0);
        return ret;
    }
};



int main(){
    
    MaxHeap heap;
    heap.insert(4);
    heap.insert(7);
    heap.insert(9);
    heap.insert(1);
    heap.insert(10);
    heap.printHeap();
    heap.Delete(8);
    heap.printHeap();
    cout<<"Max element: "<<heap.getMax()<<endl;
    cout<<"Max element: "<<heap.extractMax()<<endl;
    heap.printHeap();
    return 0;
}
