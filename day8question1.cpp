class Solution {
	public:
		string FirstNonRepeating(string s){
		    vector<int> count(26, 0);
		    
		    int n = s.size();
		    string res(n, '#');
		    
		    int j = 0;
		    for(int i=0; i < n; i++){
		        count[s[i] - 'a']++;
		        
		        while(j <= i && count[s[j] - 'a'] > 1) j++;
		        if(j <= i){
		            res[i] = s[j];
		        }
		    }
		    
		    return res;
		}

};