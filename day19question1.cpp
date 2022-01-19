class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        map<string, int> mp;
        for(int i=0; i < n; i++) mp[arr[i]]++;
        
        string res;
        int c = 0;
        for(auto m : mp){
            if(m.second > c){
                c = m.second;
                res = m.first;
            }
        }
        return {res, to_string(c)};
    }
};