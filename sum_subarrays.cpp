#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
 
 int n;
 int array[10];
 cin>>n;
for(int i=0;i<n;i++){
    cin>>array[i];
}
 
int sum;
for(int i=0;i<n;i++){
    sum=0;
    for(int j=i;j<n;j++){
           sum+=array[j];
           cout<<sum<<" ";
    }
}
 
 
return 0 ;
}