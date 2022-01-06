class Solution {
public:
        
    vector<int> getCountVec(vector<int>& arr, int n){
        
        vector<int> res(n);
        res[0] = 1;
        
        for(int i=1; i < n; i++){
            if(arr[i] > arr[i-1])
                res[i] = res[i-1] + 1;
            else
                res[i] = 1;
        }
        
        return res;
    }
    
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> l, r;
        
        l = getCountVec(arr, n);
        reverse(arr.begin(), arr.end());
        
        r = getCountVec(arr, n);
        reverse(r.begin(), r.end());
        
        int res = 0;
        
        for(int i=1; i < n-1; i++){
            if(l[i] >= 2 && r[i] >= 2) res = max(res, l[i] + r[i] - 1);
        }

        return res;
    }
};