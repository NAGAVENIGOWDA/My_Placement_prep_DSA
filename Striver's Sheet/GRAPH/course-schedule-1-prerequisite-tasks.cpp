//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int V,int P, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int>adj[V];
	    
	    for(auto it : pre){
	        adj[it.second].push_back(it.first);
	    }
	    
	    
	    
	    
	    queue<int>q;
	    vector<int>topo;
	    //find indegree
	    
	    int indeg[V]={0};
	    
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i]){
	            indeg[it]++;
	        }
	    }
	    
	    
	    //find the nodes which have indeg=0 and push it to the queue
	    
	    for(int i=0;i<V;i++){
	        
	        if(indeg[i]==0){
	            q.push(i);
	        }
	    }
	    
	    
	    while(!q.empty()){
	        
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        //traverse through adj nodes and reduce their indeg
	        
	        for(auto it : adj[node]){
	            
	            indeg[it]--;
	            
	            if(indeg[it]==0){
	                q.push(it);
	                
	            }
	        }
	    }
	//if topo size is same as number of nodes -means no cycle
	
     return (topo.size()==V)?true:false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends