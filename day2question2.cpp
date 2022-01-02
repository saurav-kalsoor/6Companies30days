class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	
	
	ull getNthUglyNo(int n) {
	    n--;
	    set<ull> st;
	    st.insert(1);
	    
	    while(n--){
	        auto it = st.begin();
	        ull a = *it;
	        st.erase(it);
	        st.insert(2 * a);
	        st.insert(3 * a);
	        st.insert(5 * a);
	    }
	    
	    return *st.begin();
	}
};