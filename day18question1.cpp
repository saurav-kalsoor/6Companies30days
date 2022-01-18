class Solution {
public:
    int dp[501][501][2];
    int maxCoins(vector<int>&arr,int n)
    {
        memset(dp, -1, sizeof(dp));
	    return f(0, n-1, true, arr);
    }
    
    int f(int i, int j, bool chance, vector<int>& arr){
        if(i == j) return chance ? arr[i] : 0;
        if(i > j) return 0;
        
        if(dp[i][j][chance] != -1) return dp[i][j][chance];
        
        if(chance){
            return dp[i][j][chance] = max(arr[i] + f(i+1, j, false, arr), arr[j] + f(i, j-1, false, arr));
        }
        
        int r1 = f(i+1, j, true, arr);
        int r2 = f(i, j-1, true, arr);
        
        return dp[i][j][chance] = min(r1, r2);
    }
};