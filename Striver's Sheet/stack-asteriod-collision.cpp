//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
       stack<int>st;
        st.push(asteroids[0]);
        for(int i = 1; i<N; i++)
        {
            if(asteroids[i]<0 && st.top()>0)
            {
                int f = 1;
                if(abs(asteroids[i])<abs(st.top())) continue;
                else if(abs(asteroids[i]) == abs(st.top())) st.pop();
                else
                {
                    while(st.size() && st.top()>0)
                    {
                        if(abs(st.top())<abs(asteroids[i])) st.pop();
                        else if(abs(st.top()) == abs(asteroids[i]))
                        {
                            f = 0;
                            st.pop();
                            break;
                        }
                        else
                        {
                            f = 0;
                            break;
                        }
                    }
                    if(f) st.push(asteroids[i]);
                }
            }
            else st.push(asteroids[i]);
        }
        vector<int>ans;
        while(st.size())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends