#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 
int main(){

int n;
cin>>n;
char a[n+1];
cin>>a;

int i=0;
int j=n-1;

while(i<j){
    if(a[i]!=a[j]){
       break;
    }
    else{
         i++;
        j--;
    }
}

if(i == j || i==j+1){
    cout<<"it is palindrome";

}
else{
    cout<<"its not palindrome";
}




 
 
 
 
return 0 ;
}