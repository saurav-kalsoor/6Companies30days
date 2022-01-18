class Solution{
public:
    
    bool fun(int arr[], int n, int sum){
        if(sum < 0)
            return false;
            
        if(sum == 0)
            return true;
        
        if(n == 0)
            return false;
        
        return fun(arr, n-1, sum - arr[n-1]) || fun(arr, n-1, sum);
    }

    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for(int i=0;i<n;i++)
            sum += arr[i];
        
        if(sum % 2 != 0)
            return 0;
        
        sum /= 2;
        
        bool dp[sum+1][n+1];
        for(int i=0;i<=n;i++)
            dp[0][i] = true;
        for(int i=0;i<=sum;i++)
            dp[i][0] = false;
        
        for(int i=1;i<=sum;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = dp[i][j-1];
                if(i >= arr[j-1])
                    dp[i][j] = dp[i][j] || dp[i-arr[j-1]][j-1];
            }
        }
        
        return dp[sum][n];
    }
};