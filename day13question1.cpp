class Solution
{
    public:
    
    vector<int> x = {-1, -1, -1, 0, 1, 1, 1, 0};
    vector<int> y = {-1, 0, 1, 1, 1, 0, -1, -1};
    
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int res = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    res = max(res, dfs(i, j, n, m, grid, visited));
                }
            }
        }
        
        return res;
    }
    
    bool isSafe(int i, int j, int n, int m){
        return (i >= 0 && j >= 0 && i < n && j < m);
    }
    
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>> &visited){
        if(visited[i][j] || grid[i][j] == 0) return 0;
        visited[i][j] = true;
        int count = 1;
        for(int a = 0; a < 8; a++){
            if(isSafe(i + x[a], j + y[a], n, m))
                count += dfs(i + x[a], j + y[a], n, m, grid, visited);
        }
        
        return count;
    }
};