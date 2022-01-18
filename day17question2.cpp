class Solution{
    public:
    long long numOfWays(int n, int x)
    {
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        for(int i=1; i <= n; i++){
            long long val = pow(i, x);
            for(int j=n; j >= i; j--){
                if(val > j) break;
                dp[j] += dp[j - val];
            }
        }
        return dp[n];
    }
};