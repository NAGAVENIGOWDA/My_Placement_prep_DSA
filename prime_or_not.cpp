#include<iostream>
using namespace std;
 
 
int main(){
 
 int n;
 cin>>n;
 int div=2;
 while(div<n){
    if(n%div==0 ){
        
        break;
    }
    else{
        div=div+1;
    }
 }
 if(div==n ){
    cout<<"It is a prime number";
 }
 else{
    cout<<"not a prime";
 }
 
 
 
return 0 ;
}