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


int min_index=INT_MAX;

int index_array[n];
for(int i=0;i<n;i++){
    index_array[i]=-1;
}

for(int i=0;i<n;i++){
    if(index_array[array[i]]==-1){
        index_array[array[i]]=i;
    }
    else{
        if(min_index>index_array[array[i]]){
            min_index=index_array[array[i]];
        }
    }
}

if(min_index==INT_MAX){
    cout<<min_index;
}
else{
        cout << min_index+1;

}



 

 
 
return 0 ;
}