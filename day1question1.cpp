class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        map<string, vector<string>> m;
        for(string s : string_list){
            string t = s;
            sort(t.begin(), t.end());
            m[t].push_back(s);
        }
            
        vector<vector<string>> res;
        
        for(auto a : m){
            res.push_back(a.second);
        }
        
        return res;
    }
};