class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) {
        vector<bool> visited(V, false);
        dfs(c, c, d, visited, adj);
        return !visited[d];
    }
    
    void dfs(int u, int c, int d, vector<bool> &visited, vector<int> adj[]){
        if(visited[u]) return;
        visited[u] = true;
        
        for(int child : adj[u]){
            if(!(u == c && child == d))
                dfs(child, c, d, visited, adj);
        }
    }
};