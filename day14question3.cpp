class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int x) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int> > res;
        
        set<vector<int>> s;
        
        for(int i=0; i < n-3; i++){
            for(int j=i+1; j < n - 2; j++){
                int st = j+1, end = n-1;
                while(st < end){
                    int sum = arr[st] + arr[end] + arr[i] + arr[j];
                    
                    if(sum == x){
                        vector<int> v = {arr[i], arr[j], arr[st], arr[end]};
                        if(s.find(v) == s.end()){
                            res.push_back(v);
                            s.insert(v);
                        }
                        st++;
                        end--;
                    }else if(sum < x){
                        st++;
                    }else{
                        end--;
                    }
                }
            }
        }
        
        return res;
    }
};