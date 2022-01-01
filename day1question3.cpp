class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int st = 0, end = 0, count = 0;
        long long p = 1;
        while(end < n && st < n){
            p *= a[end];
            while(st <= end && p >= k){
                p /= a[st];
                st++;
            }
            
            count += end - st + 1;
            end++;
        }
        
        return count;
    }
};