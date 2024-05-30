#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool balancedParanthesis(string s)
{
    stack<char> st;
    bool ans = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (s[i] == ')')
            {
                if (st.top() == '(')
                {

                    st.pop();
                }

                else
                {
                    ans = false;
                    break;
                }
            }
            else if (s[i] == ']')
            {
                if (st.top() == '[')
                {

                    st.pop();
                }

                else
                {
                    ans = false;
                    break;
                }
            }
            else if (s[i] == '}')
            {
                if (st.top() == '{')
                {
                    st.pop();
                }

                else
                {
                    ans = false;
                    break;
                }
            }
        }
    }
    if (!st.empty())
    {
        return false;
    }
    return ans;
}
int main()
{
    bool ans = balancedParanthesis("{[()}");
    if (ans)
    {
        cout << "balanced" << endl;
    }
    else
    {
        cout << "not balanced" << endl;
    }

    return 0;
}