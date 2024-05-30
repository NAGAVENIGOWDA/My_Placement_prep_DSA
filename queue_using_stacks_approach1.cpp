#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
stack <int>s1,s2;

void enqueue(int data){
    s1.push(data);
}

void dequeue(){
    if(s1.empty() && s2.empty()){
        cout<<"queue is  empty";
        return;
        
    }
    else if(!s1.empty() && s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    cout<<"the deleted element is :"<<s2.top()<<endl;
    s2.pop();
}
 
int main(){

enqueue(10);
enqueue(20);
enqueue(30);
enqueue(40);
enqueue(50);
dequeue();
dequeue();
 
 
 
 
return 0 ;
}