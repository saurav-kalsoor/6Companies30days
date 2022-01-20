class Solution {
  public:
    int minInsAndDel(int a[], int b[], int n, int m) {
        vector<int> v;
        int len = 0;
        for(int i=0; i < n; i++){
            
            bool found = binary_search(b, b+m, a[i]);
            if(found){
                if(len == 0 || a[i] > v[len-1]){
                    len++;
                    v.push_back(a[i]);
                }else{
                    int idx = ceilIdx(0, len-1, v, a[i]);
                    v[idx] = a[i];
                }
            }
            
        }
        return (n + m - 2*len);
    }
    
    int ceilIdx(int l, int r, vector<int>& v, int x){
        int res = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(v[mid] >= x){
                res = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return res;
    }
    
};