//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class disjointSet{
     public:
     vector<int>parent;
     vector<int>size;
     disjointSet(int n){
         
         parent.resize(n);
         size.resize(n);
         
         for(int i=0;i<n;i++){
             parent[i]=i;
             size[i]=1;
         }
         
     }
     
     
     int findParent(int node){
         
         if(node==parent[node])  return node;
         
         return parent[node]=findParent(parent[node]);
     }
     
     void unionBySize(int u ,int v){
         
         int pu=findParent(u);
         int pv=findParent(v);
         
         
         if(pu==pv) return ;
         
         if(size[pu] < size[pv]){
             
             parent[pu]=pv;
             size[pv]+=size[pu];
         }
         else{
             parent[pv]=pu;
             size[pu]+=size[pv];
         }
     }
    
};


class Solution {
  public:
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
       int n = details.size();
        disjointSet ds(n);
        unordered_map<string, int> mapMailNode;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                string mail = details[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    ds.unionBySize(mapMailNode[mail],i);
                }
            }
        }

        vector<string> mergedMail[n];
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for (auto it : mergedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> adj;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            string s;
            cin >> s;
            temp.push_back(s);
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            adj.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.mergeDetails(adj);
        sort(res.begin(),res.end(),[](const vector<string>& a, const vector<string>& b){
            return a[0]<=b[0];
        });
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]"
             << "\n";
    }
}

// } Driver Code Ends