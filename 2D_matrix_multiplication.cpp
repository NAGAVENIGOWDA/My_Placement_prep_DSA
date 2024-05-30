#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
 
int n1,n2,n3,n4;
cin>>n1>>n2>>n3>>n4;
int M1[n1][n2];
int M2[n3][n4];
int ans[n1][n4];

for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
        cin>>M1[i][j];
    }
}

for(int i=0;i<n3;i++){
    for(int j=0;j<n4;j++){
        cin>>M2[i][j];
    }
}

for(int i=0;i<n1;i++){
    for(int j=0;j<n4;j++){
        ans[i][j]=0;
    }
}

for(int i=0;i<n1;i++){
    for(int j=0;j<n4;j++){
        for(int k=0;k<(min(n2,n3));k++){
            ans[i][j]+=M1[i][k]*M2[k][j];
        }
    }
}

for(int i=0;i<n1;i++){
    for(int j=0;j<n4;j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<"\n";
}

 
 
 
return 0 ;
}