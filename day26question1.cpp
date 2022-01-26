class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int start, int end) {
        vector<pair<int, double>> graph[n];
        
        int m = edges.size();
        for(int i=0; i < m; i++){
            int u = edges[i][0], v = edges[i][1];
            double p = prob[i];
            graph[u].push_back({v, p});
            graph[v].push_back({u, p});
        }
        priority_queue<pair<double, int>> pq;
        pq.push({1.0 ,start});
        
        vector<double> reach(n, 0.0);
        vector<bool> visited(n, false);
        reach[start] = 1.0;

        for(int c = 0; c < n; c++){
            while(!pq.empty() && visited[pq.top().second]) pq.pop();
            
            if(pq.empty()) break;
            
            auto pi = pq.top();
            pq.pop();
            int u = pi.second;

            double p = pi.first;
            
            visited[u] = true;
            
            for(auto v : graph[u]){
                if(!visited[v.first] && p*v.second > reach[v.first]){
                    reach[v.first] = p*v.second;
                    pq.push({reach[v.first], v.first});
                }
            }
        }
        
        return reach[end];
    }
};

