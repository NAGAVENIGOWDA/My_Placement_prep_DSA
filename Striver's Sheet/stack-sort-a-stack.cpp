//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insertAtBottom(stack<int>& st, int x) {
    if (st.empty() || (!st.empty() && st.top() <= x)) {
        st.push(x);
        return;
    }

    int el = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(el);
}

void SortedStack::sort() {
    // Your code here
    
    if (s.empty()) {
        return;
    }

    int x = s.top();
    s.pop();
    sort();
    insertAtBottom(s, x);
}