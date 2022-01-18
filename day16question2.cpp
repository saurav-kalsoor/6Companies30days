class Solution{   
public:
    int lengthOfLongestAP(int arr[], int n) {
        if(n <= 2) return n;
        int res = 2;
        set<int> s;
        for(int i=0; i < n; i++) s.insert(arr[i]);
        
        for(int i=0; i < n; i++){
            for(int j=i+1; j < n; j++){
                int d = arr[j] - arr[i];
                int k = 1;
                while(s.find(arr[j] + d*k) != s.end() && arr[j] + d*k <= arr[n-1])
                    k++;
                k--;
                res = max(res, 2 + k);
            }
        }
        
        return res;
    }
};