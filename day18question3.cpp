class Solution{
  public:
    string nextPalin(string s) { 
        int n = s.size();
        int mid = n/2 - 1, k = -1;
        multiset<int> st;
        
        for(int i=mid; i >= 0; i--){
            st.insert(s[i] - '0');
            auto it = st.upper_bound(s[i] - '0');
            if(it != st.end()){
                k = i+1;
                s[i] = (*it) + '0';
                st.erase(it);
                break;
            }
        }
        
        if(k == -1) return "-1";
        
        auto it = st.begin();
        for(int i=k; i <= mid; i++){
            s[i] = *it + '0';
            it++;
        }
        
        for(int i = 0; i <= mid; i++){
            s[n-i-1] = s[i];
        }
        return s;
    }
};