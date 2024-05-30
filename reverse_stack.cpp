#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;
 
//using extra stack  
int main(){
 
stack <int> stk1;
stack <int > stk2;
stk1.push(1);
stk1.push(2); 
stk1.push(3);
stk1.push(4);
stk1.push(5);
stk1.push(6);
//stack 1 2 3 4 5 6(top) while popping 6 5 4 3 2 1
//op : 6 5 4 3 2 1(top) --while popping 1 2 3 4 5 6

while(!stk1.empty()){
      stk2.push(stk1.top());
      stk1.pop();
}

while(!stk2.empty()){
    cout<<stk2.top()<<" ";
    stk2.pop();
}




 
 
 
return 0 ;
}