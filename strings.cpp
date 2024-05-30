#include<iostream>
#include<bits/stdc++.h>
#include<strings.h>
using namespace std;
 
 
int main(){
 
string s1="Wpllo";
string s2="World";

//-1,0,1
cout<<(s1.compare(s2))<<endl;

s1.clear();
cout<<s1.empty()<<endl; //if empty -1 else 0

string s3="nincompoop";

for(int i=0;i<s3.size();i++){
    cout<<s3[i]<<endl;
}
 


return 0 ;
}