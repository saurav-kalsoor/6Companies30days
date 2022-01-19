class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int arr[], int n){
        vector<int> res;
        int mx = 0;
        
        for(int i=n-1; i>=0; i--){
            if(arr[i] >= mx) res.push_back(arr[i]);
            mx = max(mx, arr[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};