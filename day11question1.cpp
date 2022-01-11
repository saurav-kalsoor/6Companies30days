class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0; i < n; i++) sum += arr[i];
	    
	    bool dp[n+1][sum+1];
	    memset(dp, false, sizeof(dp));
	    
	    for(int i=0; i <= n; i++) dp[i][0] = true;
	    
	    for(int i=1; i <= n; i++){
	        for(int j=0; j <= sum; j++){
	            dp[i][j] = dp[i-1][j];
	            if(j - arr[i-1] >= 0) 
	                dp[i][j] = dp[i][j] | dp[i-1][j-arr[i-1]];
	        }
	    }
	    
	    for(int s = sum/2; s >= 0; s--){
	        if(dp[n][s]){
	            return sum - 2*s;
	        }
	    }
	    return sum;
	} 
};