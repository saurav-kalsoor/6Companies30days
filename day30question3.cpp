class Solution {
public:
    int divide(int a, int b) {
        if(a == 0) return 0;
        if(b == 1) return a;
        if(b == -1) return a == INT_MIN ? INT_MAX : -1 * a;
        
        return = a / b;
    }
};