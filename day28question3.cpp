class Solution {
public:
    long dp[201][201];
    int getMoneyAmount(int n) {
        memset(dp, -1, sizeof(dp));
        return (int)f(1, n);
    }
    
    long f(long i, long j){
        if(i >= j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        long res = INT_MAX;
        for(long guess = i; guess <= j; guess++){
            int r1 = f(i, guess-1);
            int r2 = f(guess+1, j);
            
            res = min(res, max(r1, r2) + guess);
        }
        return dp[i][j] = res;
    }
};