class Solution {
public:
    
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }
    
    string gcdOfStrings(string str1, string str2) {
        if(str1.length() < str2.length()){
            string t = str1;
            str1 = str2;
            str2 = t;
        }
        
        int n = str1.length(), m = str2.length();
        int g = gcd(n, m);
        
        string res = str2.substr(0, g);
        
        int k = res.length();
        
        for(int i=0; i < n; i++){
            if(str1[i] != res[i%k]) return "";
        }
        
        for(int i=0; i < m; i++){
            if(str2[i] != res[i%k]) return "";
        }
        return res;
    }
};