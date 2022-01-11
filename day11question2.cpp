class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    vector<int> in(n, 0);
	    
	    vector<int> adj[n];
	    for(auto p : prerequisites){
	        int u = p.first, v = p.second;
	        adj[v].push_back(u);
	        in[u]++;
	    }
	    
	    queue<int> q;
	    vector<bool> visited(n, false);
	    for(int i=0; i < n; i++){
	        if(in[i] == 0) q.push(i);
	    }
	    
	    while(!q.empty()){
	        int u = q.front();
	        q.pop();
	        visited[u] = true;
	        for(int child : adj[u]){
	            in[child]--;
	            if(in[child] == 0)
	                q.push(child);
	        }
	    }
	    
	    for(int i=0; i < n; i++){
	        if(!visited[i]) return false;
	    }
	    return true;
	}
};