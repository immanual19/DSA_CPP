#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;

/*
 Stack using array
 1. Static Array
 2. Dynamic Array
 */
class Stack{
public:
    
    int *a;
    int stack_size;
    int array_cap;
    Stack(){
        a=new int[1];
        array_cap=1;
        stack_size=0;
    }
    //Makes the array capacity multiplied by 2
    
    void increase_size(){
        int *tmp;
        tmp=new int[array_cap*2];
        for(int i=0;i<array_cap;++i){
            tmp[i]=a[i];
        }
        swap(a,tmp);
        delete []tmp;
        array_cap=array_cap*2;
    }
    
    //Add an element in the stack O(1)
    void push(int val){
        if(stack_size+1>=array_cap){
            increase_size();
        }
        stack_size++;
        a[stack_size-1]=val;
    }
    
    //Delete the topmost element from the stack
    void pop(){
        if(stack_size==0){
            cout<<"Stack is empty"<<endl;
            return;
        }
        a[stack_size-1]=0;
        stack_size--;
    }
    //Returns the top element from the stack
    int top(){
        if(stack_size==0){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return a[stack_size-1];
    }
    
};

int main(){
    /*
     1. Remove top element
     2. Add a top element
     */
    
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
