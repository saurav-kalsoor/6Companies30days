class Solution{
public:
    string decodedString(string s){
        stack<pair<int, string>> st;
        
        int n = s.length();
        int i = 0;
        while(i < n){
            if(s[i] == '['){
                i++;
            }else if(s[i] == ']'){
                string t;
                int f;
                
                auto p = st.top();
                st.pop();
                t = p.second;
                
                p = st.top();
                st.pop();
                
                f = p.first;
                string t2;
                
                while(f--){
                    t2.append(t);
                }
                
                if(!st.empty() && st.top().first == 0){
                    p = st.top();
                    st.pop();
                    t2 = p.second + t2;
                }
                
                st.push(make_pair(0, t2));
                i++;
                
            }else if(s[i] >= 'a' && s[i] <= 'z'){
                string t;
                while(i < n && s[i] >= 'a' && s[i] <= 'z'){
                    t.push_back(s[i]);
                    i++;
                }
                
                if(!st.empty() && st.top().first == 0){
                    string t2 = st.top().second;
                    t2.append(t);
                    st.pop();
                    st.push(make_pair(0, t2));
                }else{
                    st.push(make_pair(0, t));
                }
            }else{
                int num = 0;
                while(i < n && s[i] >= '0' && s[i] <= '9'){
                    num *= 10;
                    num += (s[i] - '0');
                    i++;
                }
                st.push(make_pair(num, ""));
            }
        }
        
        return st.top().second;
    }
    
    
};