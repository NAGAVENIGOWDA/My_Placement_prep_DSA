#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 

int prec(char x){
    if(x=='^'){
        return 3;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
    else if(x=='+' || x=='-'){
        return 1;
    }
    else{
        return 0;
    }
}
string infixTopostfix(string s){
    
    string res;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' ){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }

        }
        else{
             while( !st.empty()  && prec(st.top() ) >= prec(s[i]) ){
                res+=st.top();
                st.pop();

             }
             st.push(s[i]);
        }

    }

    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
return res;
}
 
int main(){
 

cout<<infixTopostfix("(a-b/c)*(a/k-l)");
 
 
 
 
return 0 ;
}