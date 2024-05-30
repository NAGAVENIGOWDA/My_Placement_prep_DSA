#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;
 
 
void reverseSentenceUsingStack(string s){
    //how you doing
    stack<string> stk;
    string word="";
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            word+=s[i];
        }
        else{
              stk.push(word);
              word="";
        }
        

    }
    stk.push(word); //last word

    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();

    }
}
int main(){

string s;
cout<<"enter a sentence to be reversed"<<endl;
getline(cin,s);
reverseSentenceUsingStack(s);
 
 
 
 
return 0 ;
}