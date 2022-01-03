class Solution {
  public:
    int findPosition(int n , int m , int k) {
        int res = (k + m%n - 1)%n;
        if(res == 0) res = n;
        return res;
    }
};