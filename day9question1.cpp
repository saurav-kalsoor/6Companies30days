class Solution{
public:	

    map<char, int> mpt;
    
    bool operator()(const char a, const char b){
        return mpt[a] < mpt[b];
    }

	void matchPairs(char *nuts, char *bolts, int n) {
	    mpt['!'] = 0;
	    mpt['#'] = 1;
	    mpt['$'] = 2;
	    mpt['%'] = 3;
	    mpt['&'] = 4;
	    mpt['*'] = 5;
	    mpt['@'] = 6;
	    mpt['^'] = 7;
	    mpt['~'] = 8;
	    
	    sort(nuts, nuts+n);
	    sort(bolts, bolts+n);
	}

};