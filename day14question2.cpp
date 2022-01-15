vector<string> generate(int N)
{
    vector<string> res;
    queue<string> q;
    q.push("1");
	while(N--){
	    string s1 = q.front();
	    q.pop();
	    
	    res.push_back(s1);
	    
	    string s2 = s1;
	    s1.push_back('0');
	    s2.push_back('1');
	    q.push(s1);
	    q.push(s2);
	}
	
	
	return res;
}