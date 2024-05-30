#include<iostream>
#include<bits/stdc++.h>
using namespace std;
  int operations=0;
int occurance_string(string s){
    size_t found=s.find("xy");
    if(found==string::npos) return 0;
    else{


        s.replace(found,2,"yyx");
        return (1+occurance_string(s));

    }
    

}
 
int main(){

string s="yyxyy";
//replace xy with yyx;

cout<<occurance_string(s)<<endl;
 
 
 
 
return 0 ;
}