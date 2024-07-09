//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> color(V, -1);
        //for connected components
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!bfsCheck(i, adj, color)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
private:
    bool bfsCheck(int start, vector<int> adj[], vector<int>& color) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        color[start] = 0;
        
        while (!q.empty()) {
            auto top = q.front();
            int node = top.first;
            int col = top.second;
            q.pop();
            
            for (auto adjNode : adj[node]) {
                if (color[adjNode] == -1) {
                    //not colored
                    color[adjNode] = !col;
                    q.push({adjNode, !col});
                    
                } 
                
                else {
                    //already colored -but color of adj node is same color as node is-false
                    if (color[adjNode] == col) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends