class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        
        int m = s.size();
    
        vector<vector<string>> res(m, vector<string>());
        
        set<string> sti;
        for(int i=0; i < n; i++) sti.insert(contact[i]);
        
        for(string str : sti){
            if(s[0] == str[0])
                res[0].push_back(str);
        }
    
        int j = 0;
        if(res[0].empty()) res[0].push_back("0");
        for(int i=1; i < m; i++){
            for(string &st : res[j]){
                if(i < st.size() && st[i] == s[i])
                    res[j+1].push_back(st);
            }
            if(res[j+1].empty()){
                res[j+1].push_back("0");
            } 
            j++;
        }
        
        
        
        return res;
    }
};