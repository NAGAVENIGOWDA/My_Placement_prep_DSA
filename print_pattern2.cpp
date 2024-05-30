#include<iostream>
using namespace std;
 //reverse pyramid
 /*
 
 6
******
*****
****
***
**
*

*/
 
int main(){
 
 
 int col;
 cin>>col;
 
 for(int i=col;i>0;i--){
    for(int j=1;j<=i;j++){
        cout<<"*";
    }
    cout<<endl;
 }
 
 
return 0 ;
}