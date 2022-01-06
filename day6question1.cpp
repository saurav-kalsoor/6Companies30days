class Solution {
  public:
    
    long long dp[501][201][2];
    bool found[501][201][2];
    
    
    long long f(int n, int k, bool bought, int *arr){
        if(n == 0){
            return 0;
        }
        
        if(k == 0){
            if(bought){
                long long mx = LONG_MIN;
                for(int i=0; i < n; i++) mx = max(mx, (long long)arr[i]);
                
                found[n][k][bought] = true;
                return dp[n][k][bought] = mx;
            }else{
                return 0;
            }
        }
        
        if(found[n][k][bought]) return dp[n][k][bought];
        found[n][k][bought] = true;
        
        if(bought){
            return dp[n][k][bought] = max((long long)arr[n-1] + f(n-1, k, false, arr), 
                                            f(n-1, k, true, arr));
        }else{
            return dp[n][k][bought] = max(f(n-1, k-1, true, arr) - (long long)arr[n-1], 
                                            f(n-1, k, false, arr));
        }
        
    }
    
    int maxProfit(int k, int n, int A[]) {
        memset(found, false, sizeof(found));
        int lo = 0, hi = n-1;
        while(lo < hi){
            swap(A[lo], A[hi]);
            lo++;
            hi--;
        }
        return (int)f(n, k, false, A);
    }
    
    
};