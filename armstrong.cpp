#include<iostream>
#include<bits/stdc++.h>

using namespace std;
 
 
int main(){
 int n;
 cin>>n;
 int original_n=n;
 int sum=0;
 int remainder;
 while(n>0){
    remainder=n%10;
    sum=sum+pow(remainder,3);
    n=n/10;
 }
 if(sum==original_n){
    cout<<"It is armstrong!";
 }
 else{
     cout<<"It is not armstrong!";
 }
 
 
 
 
return 0 ;
}