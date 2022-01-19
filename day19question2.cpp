class Solution{
    public:
    string amendSentence (string s)
    {
        string res;
        int n = s.size();
        for(int i=0; i < n; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                res.push_back(' ');
                res.push_back(s[i] - 'A' + 'a');
            }else{
                res.push_back(s[i]);
            }
            
        }
        
        if(res[0] == ' ') return res.substr(1);
        
        return res;
    }
};