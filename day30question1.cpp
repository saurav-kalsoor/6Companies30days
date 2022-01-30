class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        vector<string> arr[101];
        
        for(string s : nums){
            int n = s.size();
            arr[n].push_back(s);
        }
        
        for(int i=100; i >= 1; i--){
            if(arr[i].size() >= k){
                sort(arr[i].begin(), arr[i].end(), greater<string>());
                return arr[i][k-1];
            }else{
                k -= arr[i].size();
            }
        }
        return 0;
    }
    
    
};