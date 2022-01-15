class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        int graph[k][k];
        memset(graph, 0, sizeof(graph));
        
        for(int i=0; i < n-1; i++){
            for(int j=i+1; j < n; j++){
                int a = dict[i].size(), b = dict[j].size();
                for(int x = 0; x < min(a, b); x++){
                    if(dict[i][x] != dict[j][x]){
                        graph[dict[i][x] - 'a'][dict[j][x] - 'a'] = 1;
                        break;
                    }
                }
            }
        }

        vector<int> in(k, 0);
        for(int i=0; i < k; i++){
            for(int j=0; j < k; j++){
                if(graph[i][j] == 1)
                    in[j]++;
            }
        }

        vector<bool> inserted(k, false);
        queue<int> q;
        for(int i=0; i < k; i++){
            if(in[i] == 0){
                q.push(i);
                inserted[i] = true;
            } 
        }
            
        string res;
        
        while(!q.empty()){
            int u = q.front();
            
            q.pop();
            res.push_back(u + 'a');
            for(int i=0; i < k; i++){
                if(graph[u][i] == 1)
                    in[i]--;
                    
                if(in[i] == 0 && !inserted[i]){
                    inserted[i] = true;
                    q.push(i);
                }
                    
            }
        }
        
        return res;
    }
};