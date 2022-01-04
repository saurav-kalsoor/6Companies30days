
class Solution{
    public:
        long long noOfSquares(long long n){
            return (n * (n + 1) * (2*n + 1))/6;
        }
};