#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
 
int n;
int S;
cin>>n;
cin>>S;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}


//brute force
/*
int sum;
for(int i=0;i<n;i++){
    sum=a[i];
    for(int j=i+1;j<n;j++){
        sum=sum+a[j];
        if(sum==S){
            cout<<i+1<<' '<<j+1<<endl;
        }
        else{
            cout<<"this is not the subarray"<<endl;
        }

    }
}
 
 */

//optimized code

int i=0,j=0,sum=0;
int s;

while(j<n && sum+a[j]<=S){
    sum=sum+a[j];
    j++;
       
}
if(sum==S){
    cout<<i<<" "<<j;
}




return 0 ;
}