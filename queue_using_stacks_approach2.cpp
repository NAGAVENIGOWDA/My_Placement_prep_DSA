#include <iostream>
#include <bits/stdc++.h>
using namespace std;

stack<int> st;

void enqueue(int x)
{
    st.push(x);
}

void insertatBottom(int x)
{
    if (st.empty())
    {
        st.push(x);
    }
    else
    {
        int ele = st.top();
        st.pop();
        insertatBottom(x);
        st.push(ele);
    }
}
void reverse()
{
    if (st.empty())
    {
        return;
    }
    else
    {
        int x = st.top();
        st.pop();
        reverse();
        insertatBottom(x);
    }


}

void dequeue(){
    if(st.empty()){
        cout << "the stack is empty" << endl;
        return;

    }
    else{
        cout<<"the deleted ele is :"<<st.top()<<endl;
        st.pop();
    }
}

int main()
{

    // using call stack/recursion--only 1 stack
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    reverse();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    return 0;
}