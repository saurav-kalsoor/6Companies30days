class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(long long n,long long p)
    {
        if(p == 0) return 1;
        if(p == 1) return n;
        
        long long res;
        
        if(p%2 == 0){
            res = power(n, p/2)%mod;
            res = (res * res)%mod;
        }else{
            res = (n * power(n, p-1))%mod;
        }
        
        return res%mod;
    }

};