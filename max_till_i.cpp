#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 /*
 
6 
0 -9 1 3 -4 5
max-0
max[0,-9]=0
max[0,-9,1] =1;
max[0,-9,1,3]=3
op:
0
0
1
3
3
5


*/
 
int main(){
 
 int n;
 int arr[100];
 cin>>n;
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }

 int max=0;
    for(int j=0;j<n;j++){
          if(arr[j]>arr[max]){
            max=j;
          }
          cout<<arr[max]<<endl;
    }
   
 
 
 
 
return 0 ;
}