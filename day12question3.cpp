class Solution
{
    public:
    vector<vector<char>> v = {
        {},
        {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
    
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> res;
        string s;
        recurr(a, 0, N, s, res);
        return res;
    }
    
    void recurr(int a[], int i, int n, string s, vector<string> &res){
        if(i == n){
            res.push_back(s);
            return;
        } 
    
        for(char c : v[a[i]]){
            recurr(a, i+1, n, s + c, res);
        }
    }
};