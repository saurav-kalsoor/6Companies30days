class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int dp[10001];
    int FindMaxSum(int arr[], int n)
    {
        memset(dp, -1, sizeof(dp));
        return f(n, arr);
    }
    
    int f(int n, int arr[]){
        if(n <= 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int res = max(f(n-1, arr), arr[n-1] + f(n-2, arr));
        return dp[n] = res;
    }
};