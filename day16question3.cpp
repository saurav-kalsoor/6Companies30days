class Solution
{
  public:
    long long dp[1001][1001];
    long long mod = 1e9+7;
    int kvowelwords(int N, int K) {
        memset(dp, -1, sizeof(dp));
        return (int)f(N, K, K);
    }
    
    long long f(int n, int k, int K){
        
        if(k < 0) k = K;
        
        if(n == 0) return 1;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        long long res = (f(n-1, K, K)*21)%mod;
        if(k > 0){
            long long r1 = (f(n-1, k-1, K)*5)%mod;
            res = (res + r1)%mod;
        }
        return dp[n][k] = res;
    }
};