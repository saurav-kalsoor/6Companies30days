class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int n) {
        stack<int> s;
        
        for(int i=n-1; i >= 0; i--){
            while(!s.empty() && arr[i] >= arr[s.top()]) s.pop();
            
            if(s.size() == 2){
                vector<int> res;
                res.push_back(arr[i]);
                res.push_back(arr[s.top()]);
                s.pop();
                res.push_back(arr[s.top()]);
                return res;
            }
            
            s.push(i);
        }
        return {};
    }
};