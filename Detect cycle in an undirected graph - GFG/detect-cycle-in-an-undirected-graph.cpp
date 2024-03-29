//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visi(V,0);
        int parent = -1;
        for(int i=0;i<V;i++){
            if(!visi[i]){
                if(dfs(i, adj, visi, parent)) return true;
            }
        }
        return false;
    }
    
    bool dfs(int src, vector<int> adj[], vector<int> &visi, int parent){
        
        visi[src]=1;
        for(int node: adj[src]){
            if(!visi[node]){
                if(dfs(node, adj, visi, src)) return true;
            }
            else{
                if(node != parent) return true;
            }
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends