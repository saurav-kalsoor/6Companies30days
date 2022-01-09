class Solution{
    public:
    string colName (long long int n)
    {
        
        string res = "";
        while(n > 0){
            n--;
            res.push_back('A' + (n%26));
            n /= 26;
        }
        
        
        reverse(res.begin(), res.end());
        return res;
    }
};