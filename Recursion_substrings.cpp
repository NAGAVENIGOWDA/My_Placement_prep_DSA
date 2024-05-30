#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
void substrings(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string ros=s.substr(1);
    substrings(ros,ans);
    substrings(ros,ans+ch);
}
 
int main(){
 
substrings("ABC"," ");
 
 
 
 
return 0 ;
}