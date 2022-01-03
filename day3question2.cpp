class Solution {
	public:
		
		int CountWays(string str){
		    int n = str.length();
		    long mod = 1e9 + 7;
		    long dp[n];
		    
		    if(str[n-1] == '0')
		        dp[n-1] = dp[n-2] = 0;
		    else
		        dp[n-1] = 1;
		    
		    if(str[n-2] == '0') 
		        dp[n-2] = 0;
		    else 
		        dp[n-2] = dp[n-1];
		    
		    if(str[n-2] == '1' || (str[n-2] == '2' && str[n-1] <= '6')) dp[n-2]++;
		    
		    
		    for(int i=n-3; i >= 0; i--){
		        if(str[i] == '0'){
		            dp[i] = 0;
		            continue;
		        } 
		        
		        dp[i] = dp[i+1];
		        
		        if(str[i] == '1'|| (str[i] == '2' && str[i+1] <= '6') )
		            dp[i] = (dp[i] + dp[i+2])%mod;
		    }
		    
		    return (int)dp[0];
		}

};