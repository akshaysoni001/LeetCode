//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    
	   // BFS Approch kahan's Algorithm
	   
	   vector<int> indegree(V,0);
	   vector<int> topo;
	   queue<int> q;
	   for(int i=0;i<V;i++){
	       for(int node: adj[i]){
	           indegree[node]++;
	       }
	   }
	   
	   for(int i=0;i<V;i++){
	       if(indegree[i]==0) q.push(i);
	   }
	    
	   while(!q.empty()){
	       int node = q.front();
	       topo.push_back(node);
	       q.pop();
	       
	       for(int x: adj[node]){
	           indegree[x]--;
	           if(indegree[x]==0) q.push(x);
	       }
	   }
	    
	    
        return topo;
	   // DFS Approch
	    vector<int> visi(V, 0);
	    vector<int> path(V, 0);
	    stack<int> st;
	    vector<int> ans;
	    for(int i=0;i<V;i++){
	        if(visi[i]==0){
	            dfs(i, adj, visi, path, st);
	        }
	    }
	    while(!st.empty()){
	        ans.push_back(st.top());
	       // cout<<st.top()<<" ";
	        st.pop();
	    }
	    
	    return ans;
	}
	
	void dfs(int node, vector<int> adj[], vector<int> &visi, vector<int> &path, stack<int> &st){
	    
	    visi[node]=1;
	    for(int n: adj[node]){
	        if(visi[n]==0){
	            dfs(n, adj, visi, path, st);
	        }
	        
	    }
	    st.push(node);
	    
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends