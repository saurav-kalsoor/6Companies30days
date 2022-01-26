class Solution {
public:
    int dp[500][500][2];
    bool stoneGame(vector<int>& arr) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return f(0, n-1, 1, arr);
    }
    
    int f(int i, int j, int turn, vector<int>& arr){
        if(i == j) return turn ? arr[i] : 0;
        
        if(dp[i][j][turn] != -1) return dp[i][j][turn];
        
        if(turn){
            return dp[i][j][turn] = max(f(i+1, j, 0, arr) + arr[i], f(i, j-1, 0, arr) + arr[j]);
        }
        
        return dp[i][j][turn] = min(f(i+1, j, 1, arr), f(i, j-1, 1, arr));
    }
};