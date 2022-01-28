class Solution{
public:
    int height(int N){
        int h = sqrt(2*N);
        if( (h * (h+1))/2 <= N) return h;
        return h-1;
    }
};