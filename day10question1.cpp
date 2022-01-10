class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        set<pair<int, int>> s;
        queue<pair<int, int>> q;
        
        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                if(grid[i][j] == 1){
                    s.insert({i, j});
                }
                else if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        int time = -1;
        
        while(!q.empty() && !s.empty()){
            int k = q.size();
            while(k--){
                pair<int, int> p = q.front();
                q.pop();
                
                int x= p.first, y = p.second;
                if(grid[x][y] == -1) continue;
                grid[x][y] = -1;
                
                if(s.find(p) != s.end()) s.erase(p);
                
                if(s.empty()) break;
                
                if(x - 1 >= 0 && grid[x-1][y] == 1)
                    q.push({x-1, y});
                if(x+1 < n && grid[x+1][y] == 1)
                    q.push({x+1, y});
                if(y-1 >= 0 && grid[x][y-1] == 1)
                    q.push({x, y-1});
                if(y+1 < m && grid[x][y+1] == 1)
                    q.push({x, y+1});
            }
            time++;
        }
        
        if(s.empty()) return max(time, 0);
        
        return -1;
    }
};