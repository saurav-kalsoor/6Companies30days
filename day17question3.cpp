class Solution
{
    public:
    vector<string> AllParenthesis(int n) 
    {
        vector<string> res;
        string s = "";
        f(n, n, res, s);
        return res;
    }
    
    void f(int open, int close, vector<string>& res, string &s){
        if(open > close) return;
        
        if(open == 0 && close == 0){
            res.push_back(s);
            return;
        }
        
        if(open > 0){
            s.push_back('(');
            f(open -1, close, res, s);
            s.pop_back();
        }
            
        
        if(close > 0){
            s.push_back(')');
            f(open, close - 1, res, s);
            s.pop_back();
        }
            
    }
};