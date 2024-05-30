#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
 
 int n,K;
 cin>>n>>K;
 int array[n];
 for(int i=0;i<n;i++){
    cin>>array[i];
 }

sort(array, array+n);

int i=0,j=n-1;

while(i<j){

    if((array[i]+array[j])==K){
        cout<<i<<" "<<j;
        break;
      
    }
    else if(array[i]+array[j] >K){
        j--;
    }
   else{
    i++;
  }
}



 
 
 
return 0 ;
}