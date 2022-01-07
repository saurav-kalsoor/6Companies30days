class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int> dq;
        vector<int> res;
        dq.push_back(0);
        
        for(int i=1; i < k; i++){
            while(!dq.empty() && arr[i] >= arr[dq.back()]) 
                dq.pop_back();
            dq.push_back(i);
        }
        
        res.push_back(arr[dq.front()]);
        
        for(int i=k; i < n; i++){
            while(!dq.empty() && arr[i] >= arr[dq.back()]) 
                dq.pop_back();
            
            while(!dq.empty() && dq.front() <= i - k) 
                dq.pop_front();
            
            dq.push_back(i);
            
            res.push_back(arr[dq.front()]);
        }
        
        return res;
    }
};