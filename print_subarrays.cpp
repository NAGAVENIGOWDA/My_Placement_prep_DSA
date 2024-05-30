#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
 
int n;
int array[n];
cin>>n;

for(int i=0;i<n;i++){
    cin>>array[i];
}


for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        for(int k=i;k<=j;k++){
            cout<<array[k]<<' ';
        }
        cout<<endl;
    }
}
 
 
 
 
return 0 ;
}